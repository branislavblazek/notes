#!usr/bin/env python3
import sys
import subprocess

class RangeError(Exception): pass
class RowRangeError(RangeError): pass
class ColumnRangeError(RangeError): pass

_CHAR_ASSERT_TEMPLATE = "Je nutne zadat jediny znak: '{0}' je prilis dlhy!"


#pouziva sa na zaciatku podtrzitko aby sa neimportovalli aj tieto premene
_max_rows = 25
_max_columns = 80
_grid = []
_background_char = " "

def clear_screen():
    command = (["clear"] if not sys.platform.startswith('win') else ["cmd.exe", "/C", "cls"])
    subprocess.call(command)

clear_screen.__doc__ = """Vymaze obrazovku pomocou prikazu \
pre vymazanie obrazovky aktualne pouzivaneho systemu"""

def char_at(row, column):
    """
    Vrati znak na zadanej pozicii
    """
    try:
        return _grid[row][column]
    except IndexError:
        if 0 <= row <= _max_rows:
            raise RowRangeError()
        raise ColumnRangeError()

def set_background(char=" "):
    """
    Nastavi znak pre pozadie

    >>> set_background("*")
    >>> char_at(0,0)
    '*'
    >>> set_background("<>")
    Traceback (most recent call last):
    ...
    Je nutne zadat jediny znak: '<>' je prilis dlhy!
    """
    assert len(char) == 1, _CHAR_ASSERT_TEMPLATE.format(char)
    global _background_char
    old_background = _background_char
    _background_char = char
    for row in range(_max_rows):
        for column in range(_max_columns):
            if _grid[row][column] == old_background:
                _grid[row][column] = _background_char

def add_horizontal_line(row, column0, column1, char='-'):
    """Prida do mriezky vodorovnu ciaru s pouzitim zadaneho znaku

    >>> add_horizontal_line(8, 20, 25, '=')
    >>> char_at(8, 20) char_at(8, 24) == "="
    True
    >>> add_horizontal_line(31, 11, 12)
    Traceback (most recent call last):
    ...
    RowRangeError
    """
    assert len(char) == 1, _CHAR_ASSERT_TEMPLATE.format(char)
    try:
        for column in range(column0, column1):
            _grid[row][column] = char
    except IndexError:
        if not 0 <= row <= _max_rows:
            raise RowRangeError()
        raise ColumnRangeError()

def add_vertical_line(column, row0, row1, char='|'):
    """Prida do mriezky zvislu ciaru s pouzitim zadaneho znaku

    >>> add_vertical_line(5, 2, 10, "&")
    >>> char_at(2, 5) == char_at(3, 5) == "&"
    True
    >>> add_vertical_line(85, 1, 2)
    Traceback (most recent call last):
    ...
    ColumnRangeError
    """
    assert len(char) == 1, _CHAR_ASSERT_TEMPLATE.format(char)
    try:
        for row in range(row0, row1):
            _grid[row][column] = char
    except IndexError:
        if not 0 <= row <= _max_rows:
            raise RowRangeError()
        raise ColumnRangeError()

def add_rectangle(row0, column0, row1, column1, char='*', fill=False):
    if not fill:
        add_horizontal_line(row0, column0, column1, char)
        add_horizontal_line(row1-1, column0, column1, char)
        add_vertical_line(column0, row0, row1, char)
        add_vertical_line(column1-1, row0, row1, char)
    else:
        assert len(char) == 1, _CHAR_ASSERT_TEMPLATE.format(char)
        try:
            for row in range(row0, row1):
                for column in range(column0, column1):
                    _grid[row][column] = char
        except IndexError:
            if not 0 <= row <= _max_rows:
                raise RowRangeError()
            raise ColumnRangeError()


def render(clear=True):
    if clear:
        clear_screen()
    for row in range(_max_rows):
        print("".join(_grid[row]))

def get_size():
    """Vracia velkost mriezky
    """
    return _max_rows, _max_columns

def resize(max_rows, max_columns, char=None):
    """Zmeni velkost mriezky, pricom zahodi obsah a zmeni pozadie,
    ak nema znak predstavujuci pozadie hodnotu None"""
    assert max_rows > 0 and max_columns > 0, "Prilis male!"
    global _grid, _max_rows, _max_columns, _background_char
    if char is not None:
        assert len(char) == 1, _CHAR_ASSERT_TEMPLATE.format(char)
        _background_char = char
    _max_rows = max_rows
    _max_columns = max_columns
    _grid = [[_background_char for column in range(_max_columns)] for row in range(_max_rows)]

resize(_max_rows, _max_columns, "-")
