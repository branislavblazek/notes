class Transaction:
    def __init__(self, amount, date, currency="EUR", euro_rate=1, description=None):
        self.__amount = amount
        self.__date = date
        self.__currency = currency
        self.__euro_rate = euro_rate
        self.__description = description

    @property
    def amount(self):
        return self.__amount

    @property
    def date(self):
        return self.__date

    @property
    def currency(self):
        return self.__currency

    @property
    def euro_rate(self):
        return self.__euro_rate

    @property
    def description(self):
        return self.__description

    @property
    def eur(self):
        return self.__amount * self.__euro_rate

def Account:
    def __init__(self, number, name):
        self.__number = number
        self.__name = name
        self.__transactions = []

    @property
    def number(self):
        return self.__number

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, name):
        assert len(name) >= 4, "aspon 4!"
        self.__name = name

    def __len__(self):
        return len(self.__transactions)