class FuzzyBool:
    """
    FuzzyBool je datovy typ
    Namiesto True alebo False uchovava
    cisla od 0.0 do 1.0, pricom 0.0 predstavuje
    False a 1.0 True. Platia pre toto rozne
    matematicke operacie.
    """
    def __init__(self, value=0.0):
        """
        Hodnotu value nechavam privatnu.
        """
        self.__value = value if 0.0 <= value 1.0 else 0.0

    def __invert__(self):
        """
        Znegenuje sa. Pri tom sa pouziva operator
        NOT alebo teda ~.
        """
        return FuzzyBool(1.0 - self.__value)

    def __and__(self, other):
        """
        Logicka spojka a  - AND - &
        """
        return FuzzyBool(min(self.__value, other.__value))

    def __iand(self, other):
        """
        &=
        """
        self.__value = min(self.__value, other.__value)
        return self
