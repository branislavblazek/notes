class Frequency:
    def __init__(self, input_text):
        self.alphabet = [chr(i+97) for i in range(26)]
        self.slovnik = dict()
        self.spolu = 0
        self.input_text = ""
        self.table = dict()

        for letter in self.alphabet:
            self.slovnik[letter] = 0
            self.table[letter] = ""

        self.input_text = input_text.lower().lstrip().rstrip()

        for letter in self.input_text:
            if letter in self.alphabet:
                self.slovnik[letter] += 1
                self.spolu += 1

        percento = self.spolu / 100
        self.per_slovnik = dict()

        for letter, value in self.slovnik.items():
            hodnota = value / percento
            self.per_slovnik[letter] = round(hodnota, 2)

    @property
    def value(self):
        print('Values of letters in text in numbers:')
        return self.slovnik

    @property
    def percentage(self):
        print('Values of letters in text in percetanges:')
        return self.per_slovnik

    @property
    def crypto_table(self):
        return self.table

    @property
    def key(self):
        key = ''.join([item[1] for item in self.table.items()])
        return key

    @property
    def max(self):
        print('First 6 letters found in text with highest repeating:')
        x = sorted(self.per_slovnik.items(), key=lambda item: item[1], reverse=True)
        return x[:6]

    @property
    def text(self):
        return self.input_text

    def replace(self, values):
        what_replace, with_replace = values[0], values[1]
        what_replace = what_replace.lower()
        with_replace = with_replace.upper()

        print('Replacing ' + what_replace + ' with ' + with_replace)
        
        if self.crypto_table[with_replace.lower()] != '':
            print('For this letter is set another letter!')
            return

        self.crypto_table[with_replace.lower()] = what_replace
        self.input_text = self.input_text.replace(what_replace, with_replace)

analysis = Frequency("""GFS WMY OG LGDVS MF SFNKYHOSU ESLLMRS, PC WS BFGW POL DMFRQMRS, PL OG CPFU M UPCCSKSFO HDMPFOSXO GC OIS LMES DMFRQMRS DGFR SFGQRI OG CPDD GFS LISSO GK LG, MFU OISF WS NGQFO OIS GNNQKKSFNSL GC SMNI DSOOSK. WS NMDD OIS EGLO CKSJQSFODY GNNQKKPFR DSOOSK OIS 'CPKLO', OIS FSXO EGLO GNNQKKPFR DSOOSK OIS 'LSNGFU' OIS CGDDGWPFR EGLO GNNQKKPFR DSOOSK OIS 'OIPKU', MFU LG GF, QFOPD WS MNNGQFO CGK MDD OIS UPCCSKSFO DSOOSKL PF OIS HDMPFOSXO LMEHDS. OISF WS DGGB MO OIS NPHISK OSXO WS WMFO OG LGDVS MFU WS MDLG NDMLLPCY POL LYEAGDL. WS CPFU OIS EGLO GNNQKKPFR LYEAGD MFU NIMFRS PO OG OIS CGKE GC OIS 'CPKLO' DSOOSK GC OIS HDMPFOSXO LMEHDS, OIS FSXO EGLO NGEEGF LYEAGD PL NIMFRSU OG OIS CGKE GC OIS 'LSNGFU' DSOOSK, MFU OIS CGDDGWPFR EGLO NGEEGF LYEAGD PL NIMFRSU OG OIS CGKE GC OIS 'OIPKU' DSOOSK, MFU LG GF, QFOPD WS MNNGQFO CGK MDD LYEAGDL GC OIS NKYHOGRKME WS WMFO OG LGDVS.""")
print(analysis.value)

replace = [('s', 'e'), ('o', 't'), ('i', 'h'), ('g', 'o'), ('f', 'n'), ('l', 's'), 
('d', 'l'), ('v', 'v'), ('m', 'a'), ('u', 'd'), ('e', 'm'), ('r', 'g'), ('x', 'x'),
('n', 'c'), ('q', 'u'), ('n', 'c'), ('w', 'w'), ('k', 'r'), ('h', 'p'), ('j', 'q'),
('y', 'y'), ('p', 'i'), ('c', 'f'), ('b', 'k'), ('a', 'b'), ('z', 'z'), ('t', 't')
]

for coom in replace:
    analysis.replace(coom)

print(analysis.text)
print(analysis.crypto_table)
print(analysis.key)