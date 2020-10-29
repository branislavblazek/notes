import sortedlist

class SortedDict(dict):
    def __init__(self, dictionary=None, key=None, **kwargs):
        dictionary = dictionary or {}
        super().__init__(dictionary)
        if kwargs:
            super().update(kwargs)
        self.__keys = sortedlist.SortedList(super().keys(), key)

    def update(self, dictionary=None, **kwargs):
        if dictionary is None:
            pass
        elif isinstance(dictionary, dict):
            super().update(dictionary)
        else:
            for key, value in dictionary.items():
                super().__setitem__(key, value)
        
        if kwargs:
            super().update(kwargs)
        self.__keys = sortedlist.SortedList(super().keys(), self.__keys.key)