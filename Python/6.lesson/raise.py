try:
    raise LookupError('nejaka ta chybicka sa stala')
except LookupError:
    print('nastala chyba pretoze som zavolal error')
