def add_person_details(rc, surname, **kwargs):
    print('ID = ' + str(rc))
    print('\tsurname = ' + surname)
    for key in sorted(kwargs):
        print('\t' + key + ' = ' + str(kwargs[key]))
        
add_person_details(210314852, 'Blazek', age=18, vorname='Branislav', sex='male')
