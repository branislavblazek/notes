import collections
import sys

ID, FORENAME, MIDDLENAME, SURNAME, DEPARTMENT = range(5)

User = collections.namedtuple('User', 'username forename middlename surname id')

def main():
    if len(sys.argv) == 1 or sys.argv[1] in {'-h', '--help'}:
        print('pouzitie: {} subor1 [subor2 ...suborN]'.format(sys.argv[0]))
        sys.exit()

    usernames = set()#aby sa nevytvarali duplicity
    users = {}#kluc je tuple - [(surname, forename, id)] = User (namedtuple) 
    for filename in sys.argv[1:]:
        for line in open(filename, encoding='utf8'):
            line = line.rstrip()
            if line:
                user = process_line(line, usernames)
                users[(user.surname.lower(), user.forename.lower(), user.id)] = user
    print_users(users)

def process_line(line, usernames):
    fields = line.split(':')
    username = generate_username(fields, usernames)
    user = User(username, fields[FORENAME], fields[MIDDLENAME], fields[SURNAME], fields[ID])
    
    return user#vracia username='' forename='' surname='' id='', to je namedtuple

def generate_username(fields, usernames):
    username = ((fields[FORENAME][0] + fields[MIDDLENAME][:1] + fields[SURNAME]).replace("-", "").replace("'", ""))
    username = original_name = username[:8].lower()
    #kontrola jedinecnosti
    count = 1
    while username in usernames:
        username = "{}{}".format(original_name, count)
        count += 1
    usernames.add(username)
    
    return username

def print_users(users):
    namewidth = 17
    usernamewidth = 9
    formfeed = 64

    head = "{0:<{nw}} {1:^6} {2:{uw}}".format("Meno", "ID", "username", nw=namewidth, uw=usernamewidth)
    ciara = "{0:-<{nw}} {0:-<6} {0:-<{uw}}".format("", nw=namewidth, uw=usernamewidth)

    print("{0:.{1}}\t{0}".format(head, formfeed))
    print("{0:.{1}}\t{0}".format(ciara, formfeed)) 

    count = 1
    line = ''
    for key in sorted(users):
        user = users[key]
        initial = ""
        if user.middlename:
            initial = " " + user.middlename[0]
        name = "{0.surname}, {0.forename} {1}".format(user, initial)
        data = "{0:.<{nw}.{nw}} ({1.id:4}) {1.username:{uw}}".format(name, user, nw=namewidth, uw=usernamewidth)
        if count == 2:
            line += data
            print(line)
            count = 1
            line = ''
        else:
            count += 1
            line = '{0:.{1}}\t'.format(data, formfeed)

main()
