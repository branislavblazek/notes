#!/usr/bin/python3
import datetime
import xml.sax.saxutils
#funkcia xml.sax.saxutils.escape() vracia zakodovane znaky "<" -> "&lt;"

#definuje tri globalne retazce
COPYRIGHT_TEMPLATE = "Copyright (c) {0} {1}. All rights reserved."
STYLESHEET_TEMPLATE = '<link rel="stylesheet" type="text/css" media="all" href="{0}">\n'
HTML_TEMPLATE = """<!DOCTYPE html>
<html lang="sk">
	<head>
        <!-- {copyright} -->
		<title>{title}</title>
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta charset="utf-8">
		<meta name='robots' content='all'>
        <meta name='description' content="{description}">
        <meta name='keywords' content='{keywords}'>
        {stylesheet}\
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
	</head>
    <body>

    </body>
</html>
"""

#definujeme si vlastnu vynimku
class CancelledError(): 
    pass


def main():
	information = dict(name=None, year=datetime.date.today().year, filename=None, title=None, description=None, keywords=None, stylesheet=None)
	while True:
		try:
			print('\nVytvorenie ramca suboru HTML\n')
			#naplni informacie
			populate_information(information)
			#spracuje informacie	
			make_html_skeleton(**information)
		except CancelledError:
			print('Zrusene')
		if (get_string("\nVytvorit dalsi (a/n)?", default="a").lower() not in {'a', 'ano'}):
			break


def populate_information(information):
	name = get_string('Zadajte svoje meno (len pre coperight)', "name", information["name"])
	if not name:
		raise CancelledError

	year = get_integer('Zadajte rok pre copyright', "year", information["year"], 2000, datetime.date.today().year + 1, True)
	if year == 0:
		raise CancelledError

	filename = get_string('Zadajte nazov suboru', "filename")
	if not filename:
		raise CancelledError
	if not filename.endswith(('.html', '.htm')):
		filename += '.html'

	title = get_string('Zadajte titulok', 'title')
	if not title:
		raise CancelledError

	description = get_string('Zadajte popis(volitelne)', "keyword")

	keywords = []
	while True:
		keyword = get_string('Zadajte klucove slovo(volitelne)', "keyword")
		if keyword:
			keywords.append(keyword)
		else:
			break
	
	stylesheet = get_string('Zadajte nazov suboru so sablonou CSS(volitelne)', "stylesheet")
	if stylesheet and not stylesheet.endswith('.css'):
		stylesheet += '.css'

	information.update(name=name, year=year, filename=filename, title=title, description=description, keywords=keywords, stylesheet=stylesheet)

def make_html_skeleton(year, name, title, description, keywords, stylesheet, filename):
	copyright = COPYRIGHT_TEMPLATE.format(year, xml.sax.saxutils.escape(name))
	title = xml.sax.saxutils.escape(title)
	description = xml.sax.saxutils.escape(description)
	keywords = ",".join([xml.sax.saxutils.escape(k) for k in keywords]) if keywords else ""
	stylesheet = (STYLESHEET_TEMPLATE.format(stylesheet) if stylesheet else "")
	html = HTML_TEMPLATE.format(**locals())
	fh = None
	try:
		fh = open(filename, "w", encoding="utf8")
		print(fh)
		fh.write(html)
	except EnvironmentError as err:
		print("ERROR", err)
	else:
		print("Ulozeny ramec", filename)
	finally:
		if fh is not None:
			fh.close()

def get_string(message, name="string", default=None, minimum_length=0, maximum_length=80):
	message += ": " if default is None else " [{0}]: ".format(default)
	while True:
		try:
			line = input(message)
			if not line:
				if default is not None:
					return default
				if minimum_length == 0:
					return ""
				else:
					raise ValueError("{0} nemoze byt prazdne".format(name))
			if not (minimum_length <= len(line) <= maximum_length):
				raise ValueError("{name} musi mat najmenej {minium_length} a najviac {maximum_length} znakov".format(**locals()))
			return line
		except ValueError as err:
			print("ERROR", err)

def get_integer(message, name="integer", default=None, minimum=0,maximum=100, allow_zero=True):
	
	class RangeError(Exception): 
		pass

	message += ': ' if default is None else " [{0}]: ".format(default)
	while True:
		try:
			line = input(message)
			if not line and default is not None:
				return default
			i = int(line)
			if i == 0:
				if allow_zero:
					return i
				else:
					raise RangeError("{0} nemoze byt nula!".format(name))
			if not (minimum <= i <= maximum):
				raise RangeError("{name} musi byt medzi {minimum} a {maximum}"
					"vratane {0}".format(" (alebo 0)" if allow_zero else "", **locals()))
			return i
		except RangeError as err:
			print('ERROR', err)
		except ValueError as err:
			print("ERROR {0} musi byt cislica".format(name))

main()
