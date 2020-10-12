table = [['ahoj', 'svet'], ['hello', 'world']]
target = 'l'

found = False
for row, record in enumerate(table):
    for column, field in enumerate(record):
        for index, item in enumerate(field):
            #pre chapanie = teraz som dostal kazde jedno pismenko
            if item == target:
                found = True
                break
        if found:
            break
    if found:
        break
if found:
    print('najdene: ({0}, {1}, {2})'.format(row, column, index))
else:
    print('nenajdene')

# a teraz nieco lepsie:

class FoundException(Exception):
    pass

try:
    for row, record in enumerate(table):
        for column, field in enumerate(record):
            for index, item in enumerate(field):
                if item == target:
                    raise FoundException()
except FoundException:
    print('najdene: ({0}, {1}, {2})'.format(row, column, index))
else:
    print('nenajdene')
            
