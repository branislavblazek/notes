from json import loads
from pprint import pprint
from datetime import datetime
from requests import get
import unicodedata

KEY = '9e2d94a63be352355ba3e7d78008bc95'

def main():
    # A main function
    count = int(input('How many cities do you want to watch? '))
    all_data = []
    for i in range(count):
        ID = get_city_id(i)
        if not ID:
            print('ending for problem...')
            return False
        all_data.append(get_weather_data(ID))
    
    print_table(all_data)

def unicode_city(word):
    # Replace diaktricics in names of cities.
    normal = unicodedata.normalize('NFKD', word).encode('ASCII', 'ignore')
    return normal.decode().lower()

def get_city_id(i):
    # Return ID of given city.
    with open('city.list.json', encoding='utf8') as f:
        data = loads(f.read())
    city = input('What is the ' + str(i+1) + '. city? ')
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

    print('OK, i remebered the ' + str(i+1) + '. city!')    
    return city_id
            
def get_weather_data(city_id):
    # Return the data about the weather.
    weather_data = get('http://api.openweathermap.org/data/2.5/weather?id={}&APPID={}&units=metric'.format(city_id, KEY))
    return weather_data.json()

def read_time(timestmp):
    # Function for converting time to human-read version
    return datetime.fromtimestamp(timestmp).strftime('%d.%m.%Y %H:%M:%S')

def return_data(data, ID):
    # Return the value of specific item (ID) from dataset (data).
    weather_data = [str(data['name']),
                    str(data['sys']['country']),
                    str(data['id']),
                    str(read_time(data['dt'])),
                    str(data['coord']['lon']) + ', ' + str(data['coord']['lat']),
                    str(data['weather'][0]['description']),
                    str(data['weather'][0]['main']),
                    str(read_time(data['sys']['sunrise'])),
                    str(read_time(data['sys']['sunset'])),
                    str(int(data['visibility'])/1000) + ' km',
                    str(data['clouds']['all']) + ' %',
                    str(data['wind']['speed']*3.6) + ' km/h',
                    str(data['main']['pressure']) + ' hPa',
                    str(data['main']['humidity']) + ' %',
                    str(data['main']['temp']) + ' °',
                    str(data['main']['temp_max']) + ' °',
                    str(data['main']['temp_min']) + ' °'
                    ]
    return weather_data[ID]

def print_table(data):
    # Main function for creating HTML table.
    file = open('weather_compare.html', 'w', encoding='utf8')
    items = ['name', 'country', 'ID', 'last updated', 'coord', 'description', 'main',
             'sunrise', 'sunset','visibility', 'clouds', 'wind', 'pressure',
             'humidity', 'temperature', 'max temperature', 'min temperature']
    
    # Create the table tag.
    file.write('<table border="1">\n')
    # Create the header.
    file.write('\t<tr>\n')
    header_line = '\t\t<th></th>\n'
    for city in data:
        header_line += '\t\t<th>' + return_data(city, 0) + ', ' + return_data(city, 1) + '</th>\n'
    file.write(header_line)
    file.write('\t</tr>\n')
    
    # Loop every item from items
    for item in range(2, len(items)):
        table_line = '\t<tr>\n\t\t<td>' + items[item] + '</td>\n'
        for city in data:
            table_line += '\t\t<td>' + return_data(city, item) + '</td>\n'
        table_line += '\t</tr>\n'
        file.write(table_line)

    # End the table
    file.write('</table>')
    print('file weather.py updated!')

main()
