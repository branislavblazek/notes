import optparse

def main():
    parser = optparse.OptionParser()
    parser.add_option("-w", "--maxwidth", dest="maxwidth", type="int", help="maximalna dlzka riadku [default: %default]")
    parser.add_option("-f", "--format", dest="format", action='store_false', help="format pre vypis [default: %default]")
    parser.set_defaults(maxwidth=100, format=True)
    opts, args = parser.parse_args()

    print(opts, args)

main()
