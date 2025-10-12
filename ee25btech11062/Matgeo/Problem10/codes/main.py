import numpy as np

A = np.array([1, 0, 1, 0, 0, 1, 0, 1, 1, 0, -1, 0, 0, 1, 0, -1]).reshape(4,4)
A_inv = np.linalg.inv(A)
B = np.array([7, 0, 2, 5, 3, 0, 0, 4]).reshape(4,2)
C = A_inv@B

print('Matrix X')
print(C[0:2][:])
print('Matrix Y')
print(C[2:][:])
