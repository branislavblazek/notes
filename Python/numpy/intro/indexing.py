import numpy as np

arr = np.array([1, 2, 3, 4])
print(arr)
print(arr[0] + arr[1])

arr = np.array([[1,2,3,4,5], [6,7,8,9,10]])
print(arr)
print('2nd element on 1st dim: ', arr[0, 1])
print('Lat element from 2nd dim: ', arr[1, -1])

arr = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
print(arr)
print(arr[0, 1, 2])