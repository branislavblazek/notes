from collections import namedtuple

User = namedtuple('User', 'name years bday nick password')
users = []
users.append(User('Branislav', 16, '2002-10-31', 'branisla0', '123456789heslo'))
users.append(User('test', 99, '1991-02-29', 'test_user', 'somepass'))
users.append(User('Filip', 27, '1995-05-05', 'FiLipQ', 'hahaha'))

average_year = 0
count_users = 0

for user in users:
    average_year += user.years
    count_users += 1
    print('vyhodnucujem pouzivatela ' + user.name)

print('priemerny vek je {0:.2f}'.format(average_year / count_users))

#----

Aircraft = namedtuple('Aircraft', 'manufacturer model seating')
Seating = namedtuple('Seating', 'minimum maximum')
aircraft = Aircraft('Airbus', 'A320-200', Seating(100, 220))
print('The minimum seating of {0.manufacturer} {0.manufacturer.model} is {0.seating.minimum}'.format(aircraft))
