import numpy as np

arr = np.array([1,2,3,4,5])

print(arr)
#objekt ndarray
print(type(arr))

#0-D array
zero_d = np.array(42)
print(zero_d)
print(zero_d.ndim)
#1-D array
one_d = np.array([1,2,3,4,5])
print(one_d)
print(one_d.ndim)
#2-D array
two_d = np.array([[1,2,3], [4,5,6]])
print(two_d)
print(two_d.ndim)
#3-D array
three_d =  np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])
print(three_d)
print(three_d.ndim)

#5-D array
five_d = np.array([1,2,3,4,5], ndmin=5)
print(five_d)
print(five_d.ndim)