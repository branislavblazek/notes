a = ['nejaky string', 25, True]
b = ['ahojsvet', 33, False]
print(a is b)#false
b = a
print(a is b)#true

a = 'nieco'
b = None
print(a is not None,b is None)#true true
