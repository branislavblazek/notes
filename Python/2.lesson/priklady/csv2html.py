import sys
import xml.sax.saxutils

def main():
    maxwidth, format = process_options()
    if maxwidth is not None:
        print_start()
        count = 0
        while True:
            try:
                line = input()
                if count == 0:
                    color = 'lightgreen'
                elif count % 2:
                    color = 'white'
                else:
                    color = 'lightyellow'
                print_line(line, color, maxwidth, format)
                count += 1
            except EOFError as err:
                break
        print_end()

def process_options():
    maxwidth_arg = 'maxwidth='
    format_arg = 'format='
    maxwidth = 100
    format = ".0f"
    for arg in sys.argv[1:]:
        if arg in ('-h', '--help'):
            print('pouzitie: ')
            print('{0} [maxwidth=int] [format=str] < infile.csv > outfile.html'.format(sys.argv[0]))
            return None, None
        elif arg.startswith(maxwidth_arg):
            try:
                maxwidth = int(arg)
            except ValueError:
                pass
        elif arg.startswith(format_arg):
            format = arg
        return maxwidth, format
            
    

def print_start():
    print('<table border="1">')

def print_line(line, color, maxwidth, format):
    print('<tr bgcolor="{0}">'.format(color))
    fields = extract_fields(line)
    for field in fields:
        if not field:
            print('<td></td>')
        else:
            number = field.replace(',', '')
            try:
                x = float(number)
                print('<td align="right">{0:{1}}</td>'.format(round(x), format))
            except ValueError:
                field = field.title()
                field = field.replace(" A ", ' a ')
                if len(field) <= maxwidth:
                    field = xml.sax.saxutils.escape((field))
                else:
                    field = '{0}...'.format(xml.sax.saxutils.escape((field[:maxwidth])))
                print('<td>{0}</td>'.format(field))
    print('</tr>')

def extract_fields(line):
    fields = []
    field = ''
    quote = None
    for c in line:
        if c in "\"'":
            if quote is None:
                quote = c
            elif quote == c:
                quote = None
            else:
                field += c
            continue
        if quote is None and c == ',':
            fields.append(field)
            field = ''
        else:
            field += c
    if field:
        fields.append(field)
    return fields

def print_end():
    print('</table>')

main()
