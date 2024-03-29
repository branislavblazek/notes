﻿#!/usr/bin/env python3
# Copyright (c) 2008-9 Qtrac Ltd. All rights reserved.
# This program or module is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version. It is provided for educational
# purposes and is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.

"""
Tento modul nabízí několik obecných pomocných funkce:

- complete_comparisons()
- equal_float()
- s()
- logged()
- positive_result()
- bounded()
- is_unicode_punctuation()
- int2base36()

>>> file = os.path.join(tempfile.gettempdir(), "logged.log")
>>> @logged
... def discounted_price(price, percentage, make_integer=False):
...     result = price * ((100 - percentage) / 100)
...     if not (0 < result <= price):
...         raise ValueError("neplatná cena")
...     return result if not make_integer else int(round(result))
>>> discounted_price(100, 10)
90.0
>>> discounted_price(210, 5, make_integer=True)
200
>>> discounted_price(210, 14, True)
181
>>> discounted_price(210, 5)
199.5
>>> discounted_price(210, -8)
Traceback (most recent call last):
...
ValueError: neplatná cena
>>> @logged
... def f(a=10): return a**2
>>> f()
100
>>> f(20)
400
>>> f(a=12)
144
>>> #if os.path.exists(file): os.remove(file)

>>> @strictly_typed
... def discriminant(a : float, b : float, c : float) -> float:
...     return (b ** 2) - (4 * a * c)
>>> discriminant(4.0, 3.0, 2.0)
-23.0
>>> discriminant(a=4.0, b=3.0, c=2.0)
-23.0
>>> discriminant(a=4.0, b=3.0, c=2)
Traceback (most recent call last):
...
AssertionError: argument 'c' měl být typu <class 'float'>, je však typu <class 'int'>
>>> @strictly_typed
... def fail1(a : float, b : float, c : float):
...     return (b ** 2) - (4 * a * c)
Traceback (most recent call last):
...
AssertionError: chybějící typ pro návratovou hodnotu
>>> @strictly_typed
... def fail2(a : float, b, c : float) -> float:
...     return (b ** 2) - (4 * a * c)
Traceback (most recent call last):
...
AssertionError: chybějící typ pro parametr 'b'
>>> @strictly_typed
... def fail3(a : float, b : float, c : float) -> float:
...     return int((b ** 2) - (4 * a * c))
>>> fail3(a=4.0, b=3.0, c=2.0)
Traceback (most recent call last):
...
AssertionError: návratová hodnota měla být typu <class 'float'>, je však typu <class 'int'>
"""

import functools
import inspect
import logging
import os
import string
import sys
import tempfile
import unicodedata


def complete_comparisons(cls):
    """Dekorátor třídy, které doplní porovnávací operátory třídy.

    Dekorovaná třída bude mít operátory <, <=, ==, !=, >=, >,
    ovšem za předpokladu, že již mná operátor < a ideálně také operátor ==.
    Pokud třída nemá operátor <, vyvolá příkaz assert výjimku.

    >>> @complete_comparisons
    ... class AClass(): pass
    Traceback (most recent call last):
    ...
    AssertionError: AClass musí definovat < a ideálně ==
    >>> @complete_comparisons
    ... class Lt():
    ...     def __init__(self, x=""):
    ...         self.x = x
    ...     def __str__(self):
    ...         return self.x
    ...     def __lt__(self, other):
    ...         return str(self) < str(other) 
    >>> a = Lt("a")
    >>> b = Lt("b")
    >>> b2 = Lt("b")
    >>> (a < b, a <= b, a == b, a !=b, a >= b, a > b)
    (True, True, False, True, False, False)
    >>> (b < b2, b <= b2, b == b2, b != b2, b >= b2, b > b2)
    (False, True, True, False, True, False)
    >>> @complete_comparisons
    ... class LtEq():
    ...     def __init__(self, x=""):
    ...         self.x = x
    ...     def __str__(self):
    ...         return self.x
    ...     def __lt__(self, other):
    ...         return str(self) < str(other) 
    ...     def __eq__(self, other):
    ...         return str(self) == str(other) 
    >>> a = LtEq("a")
    >>> b = LtEq("b")
    >>> b2 = LtEq("b")
    >>> (a < b, a <= b, a == b, a !=b, a >= b, a > b)
    (True, True, False, True, False, False)
    >>> (b < b2, b <= b2, b == b2, b != b2, b >= b2, b > b2)
    (False, True, True, False, True, False)
    """
    assert cls.__lt__ is not object.__lt__, (
            "{0} musí definovat < a ideálně ==".format(cls.__name__))
    if cls.__eq__ is object.__eq__:
        cls.__eq__ = lambda self, other: (not
                (cls.__lt__(self, other) or cls.__lt__(other, self)))
    cls.__ne__ = lambda self, other: not cls.__eq__(self, other)
    cls.__gt__ = lambda self, other: cls.__lt__(other, self)
    cls.__le__ = lambda self, other: not cls.__lt__(other, self)
    cls.__ge__ = lambda self, other: not cls.__lt__(self, other)
    return cls


def delegate(attribute_name, method_names):
    """Předá volání atributu s názvem attribute_name pro
    každou metodu uvedenou v seznamu method_names.
    (Příklad viz SortedListP.py.)
    """
    def decorator(cls):
        nonlocal attribute_name
        if attribute_name.startswith("__"):
            attribute_name = "_" + cls.__name__ + attribute_name
        for name in method_names:
            setattr(cls, name, eval("lambda self, *a, **kw: "
                                    "self.{0}.{1}(*a, **kw)".format(
                                    attribute_name, name)))
        return cls
    return decorator



def equal_float(a, b, epsilon=sys.float_info.epsilon):
    """Vrátí hodnotu True, pokud se a rovná b do limitu přesnosti 
    daného stroje nebo do limitu hodnoty epsilon, je-li zadána

    >>> equal_float(.1, .1), equal_float(.000000000001, .000000000001)
    (True, True)
    >>> equal_float(.00000000000101, .00000000000102, .0000000000001)
    True
    >>> equal_float(.00000000000101, .00000000000102)
    False
    """
    return abs(a - b) <= epsilon


s = lambda x: "" if x == 1 else "s"
s.__doc__ = "Vrátí 's' pro množství odlišné od 1"


def positive_result(function):
    @functools.wraps(function)
    def wrapper(*args, **kwargs):
        result = function(*args, **kwargs)
        assert result >= 0, function.__name__ + "() má výsledek < 0"
        return result
    return wrapper


@positive_result
def discriminant(a, b, c):
    """
    >>> discriminant(1, 2, 3)
    Traceback (most recent call last):
    ...
    AssertionError: discriminant() má výsledek < 0
    >>> discriminant(3, 4, 1)
    4
    >>> discriminant.__name__
    'discriminant'
    """
    return (b ** 2) - (4 * a * c)


def bounded(minimum, maximum):
    def decorator(function):
        @functools.wraps(function)
        def wrapper(*args, **kwargs):
            result = function(*args, **kwargs)
            if result < minimum:
                return minimum
            elif result > maximum:
                return maximum
            return result
        return wrapper
    return decorator


@bounded(0, 100)
def percent(amount, total):
    """
    >>> percent(512, 4096)
    12.5
    >>> percent(811, 700)
    100
    >>> percent(-7, 91)
    0
    """
    return (amount / total) * 100


def strictly_typed(function):
    annotations = function.__annotations__
    arg_spec = inspect.getfullargspec(function)

    assert "return" in annotations, "chybějící typ pro návratovou hodnotu"
    for arg in arg_spec.args + arg_spec.kwonlyargs:
        assert arg in annotations, ("chybějící typ pro parametr '" +
                                    arg + "'")
    @functools.wraps(function)
    def wrapper(*args, **kwargs):
        for name, arg in (list(zip(arg_spec.args, args)) +
                          list(kwargs.items())):
            assert isinstance(arg, annotations[name]), (
                    "argument '{0}' měl být typu {1}, je však typu {2}".format(
                    name, annotations[name], type(arg)))
        result = function(*args, **kwargs)
        assert isinstance(result, annotations["return"]), (
                    "návratová hodnota měla být typu {0}, je však typu {1}".format(
                    annotations["return"], type(result)))
        return result
    return wrapper


if __debug__:
    logger = logging.getLogger("Logger")
    logger.setLevel(logging.DEBUG)
    handler = logging.FileHandler(os.path.join(
                                tempfile.gettempdir(), "logged.log"))
    logger.addHandler(handler)

    def logged(function):
        @functools.wraps(function)
        def wrapper(*args, **kwargs):
            log = "volání: " + function.__name__ + "("
            log += ", ".join(["{0!r}".format(a) for a in args] +
                             ["{0!s}={1!r}".format(k, v)
                              for k, v in kwargs.items()])
            result = exception = None
            try:
                result = function(*args, **kwargs)
                return result
            except Exception as err:
                exception = err
            finally:
                log += ((") -> " + str(result)) if exception is None
                        else ") {0}: {1}".format(type(exception),
                                                 exception))
                logger.debug(log)
                if exception is not None:
                    raise exception
        return wrapper
else:
    def logged(function):
        return function


def is_unicode_punctuation(s : str) -> bool:
    """
    >>> is_unicode_punctuation("No way!")
    False
    >>> is_unicode_punctuation("@!?*")
    True
    >>> is_unicode_punctuation("@!?*X")
    False
    """
    for c in s:
        if unicodedata.category(c)[0] != "P":
            return False
    return True


def int2base36(integer):
    """Vrátí celé číslo jako číslo o základu 36 ve formě řetězce

    Pro obrácený převod použijte volání int(řetězec, 36).

    >>> int2base36(0)
    '0'
    >>> int2base36(35), int("Z", 36)
    ('Z', 35)
    >>> int2base36(36), int("10", 36)
    ('10', 36)
    >>> int2base36(37), int("11", 36)
    ('11', 37)
    >>> int2base36(98712374), int("1MRQYE", 36)
    ('1MRQYE', 98712374)
    >>> int2base36(825170), int("HOPE", 36)
    ('HOPE', 825170)
    """
    DIGITS = string.digits + string.ascii_uppercase
    digits = []
    while integer >= 36:
        integer, modulus = divmod(integer, 36)
        digits.append(DIGITS[modulus])
    digits.append(DIGITS[integer])
    return "".join(reversed(digits))


if __name__ == "__main__":
    import doctest
    doctest.testmod()
