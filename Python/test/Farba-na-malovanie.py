stena_a = float(input ("Zadaj dĺžku steny a:"))
stena_b = float(input ("Zadaj dĺžku steny b:"))
stena_c = float(input ("Zadaj dĺžku steny c:"))
sirka_o = float(input ("Zadaj šírku okna:"))
vyska_o = float(input ("Zadaj výšku okna:"))
sirka_d = float(input ("Zadaj šírku dverí:"))
vyska_d = float(input ("Zadaj výšku dverí:"))
pocet_o = float(input ("Zadaj počet okien:"))
pocet_d = float(input ("Zadaj počet dverí:"))
vyska_i = float(input ("Zadaj výšku izby:"))
izba_1 = vyska_i * stena_a * 2 + vyska_i * stena_b * 2
izba_2 = vyska_i * stena_a * 2 + vyska_i * stena_c * 2
o = izba_1 + izba_2 - pocet_o * sirka_o * vyska_o - pocet_d * vyska_d * sirka_d
print("Budete potrebovať " + str(o) + "m2 farby.")
