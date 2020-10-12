vlastnosti = {'pocasie': 'pekne', 'nalada': 'ako tak dobra', 'stupnica': 6}
for item in vlastnosti.items():
    print(item[0], item[1])
for key, value in vlastnosti.items():
    print(key, value)
for value in vlastnosti.values():
    print(value)
for key in vlastnosti:
    print(key)
