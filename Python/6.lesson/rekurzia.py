import turtle

k = turtle.Turtle()
turtle.delay(0)

##def kresli(d):
##    if d > 100:
##        pass
##    else:
##        k.fd(d)
##        k.right(30)
##        kresli(d+0.5)
##    chvostova rekurzia, da sa vzdy prepisat pomocou cyklu
##
##kresli(1)

def kresli2(d):
    if d > 100:
        pass
    else:
        k.fd(d)
        k.right(30)
        kresli(d+0.5)
        k.pencolor('red')
        k.lt(30)
        k.backward(d)
        #vyuziva sa zasobnik - ako v zlej restike,
        #pride zakazik na konci a je prvy obluzeny

##kresli2(1)
 
def stvorec(d):
    if d < 5:
        pass
    else:
        for _ in range(4):
            k.forward(d)
            k.left(90)
        stvorec(d-5)
    
for _ in range(10):
    stvorec(150)
    k.right(36)

##def vypis(n):
##    if n == 0:
##        pass
##    else:
##        print(n)
##        vypis(n-1)
##        print(n)
##
##vypis(10)

##k.left(90)
##k.backward(150)
##def strom(n, d):
##    k.pensize(n*2)
##    if n == 0:
##        k.forward(d)
##        k.dot(5, 'green')
##        k.backward(d)
##    else:
##        k.fd(d)
##        k.lt(40)
##        strom(n-1, d * .7)
##        k.rt(75)
##        strom(n-1, d * .6)
##        k.lt(35)
##        k.backward(d)
##
##k.pencolor('maroon')
##
##strom(8, 200)
    
