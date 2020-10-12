#!/usr/bin/env python3
"""
Tento modul ponuka niekolko funckii pre manipulaciu s retazcami.

>>> is_balanced("(Python (není (jako (lisp))))")
True
>>> shorten("Velká křižovatka", 10)
'Velká k...'
>>> simplify(" nějaký    text    s  nadbytečnými  mezerami  ")
'nějaký text s nadbytečnými mezerami'
"""

import string

def is_balanced(text, brackets="{}[]()<>"):
    """
    Vrátí hodnotu True, jsou-li všechny závorky v textu vyváženy.

    U každé dvojice závorek musejí být levé a pravé znaky odlišné.

    >>> is_balanced("úplně bez závorek")
    True
    >>> is_balanced("<b>tučně</b>")
    True
    >>> is_balanced("[<b>(někde {něco}) máme</b>]")
    True
    >>> is_balanced("<b>[sem (to {nejspíš}) nepatří}]</b>")
    False
    >>> is_balanced("(není (<značka>(jako) (jiná)</značka>)")
    False
    """
    # uchovava lave zatovrky
    counts = {}
    # prave
    left_for_right = {}
    for left, right in zip(brackets[::2], brackets[1::2]):
        assert left != right, "Znaky dvoch zatvoriek sa musia rovnat"
        counts[left] = 0
        left_for_right[right] = left
    for c in text:
        if c in counts:
            counts[c] += 1
        elif c in left_for_right:
            left = left_for_right[c]
            if counts[left] == 0:
                return False
            counts[left] -= 1
    return not any(counts.values())

def simplify(text, whitespace=string.whitespace, delete=""):
    """
    Vrati text s viacnasoobnymi medzerami zredukovanych na jednu medzeru

    Parameter whitespace je retazec znakobv, pricom kazdy je medzerami
    Nie je Parameter delete prazdny, mal by obsahovat retazec, ktoreho znaky sa vyhladaju
    vo vyslednom retazci a odstrania
    Funkcnost:
    Funckia prechadza kazdy jeden znak.
    Pokial je znak v delete, hned ide na dalsi.
    Pokial dalsi znak nie je v delete a ani vo whitespace, prida ho do word.
    Pokial je dalsi znak whitespace, a zaroven je nieco v slove, tak to slovo vypise.

    >>> simplify(" tohle    a\\n také\\t tamto")
    'tohle a také tamto'
    >>> simplify("  Vejce   a.s.\\n")
    'Vejce a.s.'
    >>> simplify("  Vejce   a.s.\\n", delete=",;:.")
    'Vejce as'
    >>> simplify(" nesamohláskový ", delete="aáeiouyý")
    'nsmhlskv'
    """
    result = []
    word = ""
    for char in text:
        if char in delete:
            continue
        elif char in whitespace:
            if word:
                result.append(word)
                word = ''
        else:
            word += char
    if word:
        result.append(word)
    return " ".join(result)

def shorten(text, length=25, indicator="..."):
    """
    Vrati text alebo orezanu kopiu s pripojenym indikatorom

    Text je lubovolny retazec;
    length je maximalna dlzka vrateneho
    retazca (vratane pripadneho indkatora);
    indikator je retazec pridany na koniec, ktory signalizuje, ze text bol skrateny

    >>> shorten("Druhá varieta")
    'Druhá varieta'
    >>> shorten("Hlasy z druhej strany ulice", 17)
    'Hlasy z druhej...'
    >>> shorten("Radio Express", 9, "*")
    'Radio Ex*'
    """
    if len(text) > length:
        text = text[:length - len(indicator)] + indicator
    return text

if __name__ == "__main__":
    import doctest
    doctest.testmod()
