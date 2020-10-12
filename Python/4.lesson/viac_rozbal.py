def print_args(*args, **kwargs):
    for i, arg in enumerate(args):
        print('pozicny argument {0} = {1}'.format(i, arg))
    for key in kwargs:
        print('klucovy argument {0} = {1}'.format(key, str(kwargs[key])))


print_args('ahoj', 'krasny', 'svet', value=18, weather='sunny')
