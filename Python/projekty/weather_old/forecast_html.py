from json import loads
from pprint import pprint
from datetime import datetime
from requests import get
import unicodedata

KEY = '9e2d94a63be352355ba3e7d78008bc95'

def main():
    # A main function
    ID = get_city_id()
    if not ID:
        print('ending...')
        return False
    data = get_weather_data(ID)
    print_table(data)

def unicode_city(word):
    # Replace diaktricics in names of cities.
    normal = unicodedata.normalize('NFKD', word).encode('ASCII', 'ignore')
    return normal.decode().lower()

def get_city_id():
    # Return ID of given city.
    with open('city.list.json', encoding='utf8') as f:
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
    # Return the data about the weather.
    weather_data = get('http://api.openweathermap.org/data/2.5/forecast?id={}&APPID={}&units=metric'.format(city_id, KEY))
    return weather_data.json()

def read_time(timestmp):
    # Function for converting time to human-read version
    return datetime.fromtimestamp(timestmp).strftime('%d.%m.%Y %H:%M')

def return_data(data, ID):
    # Return the value of specific item (ID) from dataset (data).
    print(data)
    if '3h' in data['rain']:
        rain_data = str(data['rain']['3h'])[:5]
    else:
        rain_data = str(0.0)

    if '3h' in data['snow']:
        snow_data = str(data['snow']['3h'])[:5]
    else:
        snow_data = str(0.0)

    weather_data = {'time': str(read_time(data['dt'])),
                    'clouds': str(data['clouds']['all']) + ' %',
                    'wind': str(int(data['wind']['speed'])*3.6) + ' km/h',
                    'pressure': str(data['main']['pressure']) + ' hPa',
                    'humidity': str(data['main']['humidity']) + ' %',
                    'temperature': str(data['main']['temp']) + ' °',
                    'temperature max': str(data['main']['temp_max']) + ' °',
                    'temperature min': str(data['main']['temp_min']) + ' °',
                    'description': str(data['weather'][0]['description']),
                    'main': str(data['weather'][0]['main']),
                    'rain': rain_data,
                    'snow': snow_data
    }

    return weather_data[ID]

def print_table(data):
    # Main function for creating HTML table.
    file = open('forecast.html', 'w', encoding='utf8')
    items = ['time', 'temperature', 'temperature max', 'temperature min',
         'rain', 'snow', 'clouds', 'wind', 'pressure', 'humidity', 'description', 'main']

    # Create the table tag.
    file.write('<table border="1">\n')
    # Create the header.
    # Create the label with name, country,...
    header_line = '\t<tr>\n\t\t<th colspan="12">'\
                 + data['city']['name'] + ', ' + data['city']['country']\
                 + ' (' + str(data['city']['coord']['lon']) + ', '\
                 + str(data['city']['coord']['lat']) + '), '\
                 + 'ID = ' + str(data['city']['id'])\
                 + '</th>\t</tr>\n'
    file.write(header_line)
    # Create the label with temp, wind,...
    header_line = '\t<tr>\n'
    for item in items:
        header_line += '\t\t<th>' + item + '</th>\n'
    file.write(header_line)
    file.write('\t</tr>\n')

    # Loop every item from items
    for hour in data['list']:
        table_line = '\t<tr>\n'
        for item in items:
            table_line += '\t\t<td>' + return_data(hour, item) + '</td>\n'
        table_line += '\t</tr>\n'
        file.write(table_line)

    # End the table
    file.write('</table>')
    print('file forecast.html updated!')

main()
