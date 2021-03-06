import collections
import sys

User = collections.namedtuple('User', 'username forename middlename surname id')
ID, FORENAME, MIDDLENAME, SURNAME, DEPARTMENT = range(5)

def main():
    if len(sys.argv) == 1 or sys.argv[1] in {'-h', '--help'}:
        print('pouzitie: {} subor1 [subor2 ...]'.format(sys.argv[0]))
        sys.exit()

    usernames = set()
    users = {}
        
    for filename in sys.argv[1:]:
        for line in open(filename, encoding="utf8"):
            line = line.rstrip()
            if line:
                user = process_line(line, usernames)
                users[(user.surname.lower(), user.forename.lower(), user.id)] = user
    print_users(users)


def process_line(line, usernames):
    fields = line.split(":")
    username = generate_username(fields, usernames)
    user = User(username, fields[FORENAME], fields[MIDDLENAME], fields[SURNAME], fields[ID])

    return user

def generate_username(fields, usernames):
    username = ((fields[FORENAME][0] + fields[MIDDLENAME][:-1] + fields[SURNAME]).replace('-', '').replace('\'', ''))
    username = original_name = username[:8].lower()
    count = 1
    while username in usernames:
        username = '{}{}'.format(original_name, count)
        count += 1
    usernames.add(username)

    return username

def print_users(users):
    namewidth = 32
    usernamewidth = 9

    print('{0:<{namewidth}} {1:^6} {2:{usernamewidth}}'.format('Meno', 'ID', 'username', **locals()))
    print('{0:-<{namewidth}} {0:-<6} {0:-<{usernamewidth}}'.format('', **locals()))

    for key in sorted(users):
        user = users[key]
        initial = ''
        if user.middlename:
            initial = ' ' + user.middlename[0]
        name = '{0.surname}, {0.forename} {1}'.format(user, initial)
        print('{0:.<{namewidth}} ({1.id:4}) {1.username:<{usernamewidth}}'.format(name, user, **locals()))

main()
