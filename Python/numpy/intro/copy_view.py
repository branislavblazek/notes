import numpy as np

arr = np.array([1,2,3,4,5])
x = arr.copy()
x[0] = 42

#Copies own the data = arr.base => None
#Views not own = arr.base =? refers to the org object

print(arr)
print(x)

arr = np.array([1,2,3,4,5])
x = arr.view()
arr[0] = 150

print(arr)
print(x)

arr = np.array([1,2,3,4,5])
x = arr.copy()
y = arr.view()

print(x.base)
print(y.base)