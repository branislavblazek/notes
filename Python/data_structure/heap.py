import math

class heap:
    def __init__(self):
        self.pq = []

    def __repr__(self):
        return str(self.pq)

    def heappush(self, item):
        #dam na koniec
        self.pq.append(item)
        #novo pridany prvok je na poslednej pozicii
        where = len(self.pq) - 1
        while where > 0:
            #otca syna ziskam ako (i-1)/2,
            parent = int((where-1) / 2)
            #pokial je syn vacsi ako otec, treba ich vymenit
            if self.pq[where] < self.pq[parent]:
                #vymen ich pozicie
                self.pq[where], self.pq[parent] = self.pq[parent], self.pq[where]
                where = parent
            #pokial je syn vacsi ako otec, je to OK
            else:
                break

    def heappop(self):
        l = len(self.pq)
        #vyberieme najmensi prvok
        lowest = self.pq[0]
        #na jeho miesto dame posledny prvok
        self.pq[0] = self.pq[l - 1]
        #odstrani prvok z konca ktory je teraz duplikatne aj na zaciatku
        self.pq.pop()
        l -= 1
        while True:
            dest = where
            #2*where+1/2 je odkaz na synov, ich otec je where
            #pokial je syn este stale v poli (1.pod)
            #pokial je syn1 mesni ako otec (2.pod)
            if 2*where+1 < l and self.pq[2*where+1] < self.pq[dest]:
                #odkaz bude na prveho syna
                dest = 2*where+1
            #pokial je druhy syn mensi ako otec
            # \varianta ked prve if je false
            #pokial je druhy syn mensi ako prvy syn
            # \varianta ked prve if je true
            if 2*where+2 < l and self.pq[2*where+2] < self.pq[dest]:
                dest = 2*where+2
            #pokial sa nemusi nic prehadzovat, tak return, inak prehod a pokracuj
            if where != dest:
                self.pq[where], self.pq[dest] = self.pq[dest], self.pq[where]
                where = dest
            else:
                return lowest

    def height(self):
        return math.floor(math.log2(len(self.pq))) + 1

    def show(self):
        vyska = self.height()
        #mocnina udava pocet cisel v spodnomm riadku
        mocnina = 2 ** (vyska - 1)
        #kolko 'patiek' bude v riadkoch
        pocet5 = mocnina / 2
        #kolko bude medzier medzi patkami
        medzery = pocet5 - 1
        #aka je dlzka spodneho riadku, teda kazdeho riadku v pyramide
        spolu = int(5 * pocet5 + medzery)
        #pocet znakov na jednej strane pyramidy - ak je pyramida dlha 11, tak jedna strana ma 5
        strana = int((spolu - 1) / 2)
        #cyklus, prejde kazdy riadok
        for i in range(vyska):
            #tu su cisla ktore sa budu prave vypisovat
            active_numbers = self.pq[2**i-1:2**(i+1)-1]



halda = heap()

halda.heappush(5)
halda.heappush(1)
halda.heappush(7)
halda.heappush(2)
halda.heappush(8)
halda.heappush(4)
