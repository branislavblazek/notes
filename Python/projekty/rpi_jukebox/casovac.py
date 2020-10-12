import datetime
def main(hours, minutes, seconds):
    new_date = datetime.datetime.now()
    add_date = datetime.timedelta(hours=hours,minutes=minutes,seconds=seconds)
    new_date = new_date + add_date
    while True:
        now = datetime.datetime.now()
        countdown = new_date - now
        print(countdown)
        if new_date.strftime('%H:%M:%S') == now.strftime('%H:%M:%S'):
            break

main(0,0,10)
    
