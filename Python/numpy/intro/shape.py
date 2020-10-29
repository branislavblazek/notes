import numpy as np

arr = np.array([[1, 2, 3, 4], [5, 6, 7, 4]])

print(arr.shape)
#(2,4)
#array has 2 dimensions, each dimension has 4 elements

arr = np.array([1, 2, 3, 4], ndmin=5)

print(arr)
print('shape of array :', arr.shape)