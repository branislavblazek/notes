from json import loads
from pprint import pprint
from datetime import datetime
from requests import get
import unicodedata

KEY = '9e2d94a63be352355ba3e7d78008bc95'

def unicode_city(word):
    normal = unicodedata.normalize('NFKD', word).encode('ASCII', 'ignore')
    return normal.decode().lower()

def get_city_id():
    with open('city.list.json', encoding='utf8') as f:
        print(f)
        data = loads(f.read())
    city = input('Which is the closest city to the place you are travelling to? ')
    city = unicode_city(city)
    city_id = False
    for item in data:
        if unicode_city(item['name']) == city:
            answer = input("Is this in " + item['country'] + ' ')
            if answer == 'y' or answer == 'yes':
                city_id = item['id']
                break
    if not city_id:
        print('Sorry, that location is not available...')
        return False
        
    return city_id
            
def get_weather_data(city_id):
    weather_data = get('http://api.openweathermap.org/data/2.5/weather?id={}&APPID={}&units=metric'.format(city_id, KEY))
    return weather_data.json()
