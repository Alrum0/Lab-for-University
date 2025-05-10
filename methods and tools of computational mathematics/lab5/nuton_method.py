from math import cos, sin
from numpy import sign
import pandas as pd

def F(x):
    y = (cos(x) ** 2) * sin(1.6 * x) * (x ** 2 + x + 1)
    return y

a = -1
b = 0.5

h = 0.001

def dF(x):
    y = cos(x) * (-2 * (x**2 + x + 1) * sin(x) * sin(1.6 * x) + 1.6 * (x**2 + x + 1) * cos(x) * cos(1.6 * x) + (2 * x + 1) * sin(1.6 * x) * cos(x))
    return y

c = 0.3

data_C = [c]
data_F_C = [F(c)]
while abs(F(c)) > h:
    c = c - F(c) / dF(c)
    data_C.append(c)
    data_F_C.append(F(c))

print('\nРезультати обчислення методом Ньютона: ')
print()
data = pd.DataFrame({'c' : data_C, 'F(c)' : data_F_C})
print (data)
print()
print('В точці c = ', c, ', F(C) = ', F(c))