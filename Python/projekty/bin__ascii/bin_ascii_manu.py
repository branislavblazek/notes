import math

def pridaj_nulu(cislo):
	kolko = 8 - len(cislo)
	for i in range(kolko):
		cislo = '0' + cislo
	return cislo

def podel(letter):
	try:
		cislo = int(letter)
	except ValueError:
		print('Error with int')
		return
	binary = ''
	while cislo / 2 > 0:
		binary = str(cislo % 2) + binary
		cislo = cislo // 2
	# kontrola ci netreba dat pred to nulu
	if len(binary) < 8:
		binary = pridaj_nulu(binary)
	# vracia normalne binarne cislo
	return binary

def nasob(bin):
	hodnota = 0
	for ity, znak in enumerate(bin):
		hodnota += int(znak) * int(math.pow(2, len(bin) - ity - 1))
	return chr(hodnota)

def to_ascii(text):
	ascii_data = []
	for i in text:
		ascii_data.append(ord(i))
	return ascii_data

def to_binary(text):
	ascii_data = to_ascii(text)
	bin_data = ''
	for letter in ascii_data:
		# spusti algorytmus na ziskanie binary z ascii, vrati binary str
		bin_data += podel(letter) + ' '
	bin_data = bin_data.rstrip()
	print(bin_data)

def to_text(bin):
	splitted = bin.split(' ')
	text = ''
	for item in splitted:
		# spusti algorytmus na ziskanie textu z bin, vrati text str
		text += str(nasob(item))
	print(text)

#to_binary('ahoj')
#to_text('01100001 01101000 01101111 01101010')
#shdgasdjashdlkaj

# main script
while True:
	typ = input('What would you like to do? (encode/decode): ')
	typ = typ.lower().strip()
	text = input('Insert text for ' + typ[:-1] + 'ing: ')
	print('\nThe result text is: ')
	if typ == 'encode':
		to_text(text)
	elif typ == 'decode':
		to_binary(text)
	else:
		print('I don\'t know what I should do!')
	print('')