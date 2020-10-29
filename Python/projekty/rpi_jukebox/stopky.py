import datetime
def main():
    start = datetime.datetime.now()
    while True:
        now = datetime.datetime.now()
        print(now - start)
        print(format(now - start, '%S'))

main()
