import os

path = input('Input the path: ')

date_from_name = {}
if path == 'current':
    path = os.getcwd()
print(path)
for name in os.listdir(path):
    fullname = os.path.join(path, name)
    print(name)
    if os.path.isfile(fullname):
        date_from_name[fullname] = os.path.getmtime(fullname)

print()
print(date_from_name)
