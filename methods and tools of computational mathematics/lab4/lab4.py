import pandas as pd
import numpy as np
import math

a = -4
b = 4
h = 0.01

X = np.arange(a, b + h, h)
def F(x):
    y = (math.cos(x) ** 2) * math.sin(1.6 * x) * (x ** 2 + x + 1)
    return y

Y = []
for i in range(len(X)):
    Y.append(F(X[i]))

data = pd.DataFrame({'X' : X, 'Y' : Y})
print(data)

def Trapezoidal_rule(data, h):
    T = (data['Y'][0] + data['Y'][len(X) - 1]) / 2
    for i in range(1, len(X) - 1):
        T = T + data['Y'][i]
    return h * T

def Simpson_rule(data, h):
    S = data['Y'][0] + data['Y'][len(X) - 1]
    for i in range(1, int((len(X) - 1) / 2) + 1):
        S = S + 4 * data['Y'][2 * i - 1]
    for i in range(1, int(len((X) - 1) / 2)):
        S = S + 2 * data['Y'][2 * i]
    return h * S / 3

def Boole_rule(data, h):
    
    B = 7 * (data['Y'][0] + data['Y'][len(X) - 1])
    for i in range (1, int((len(X) - 1) / 2) + 1):
        B = B + 32 * data['Y'][2 * i - 1]
    for i in range (1, int((len(X) - 1) / 4) + 1):
        B = B + 12 * data['Y'][4 * i - 2]
    for i in range (1, int((len(X) - 1) / 4)):
        B = B + 14 * data['Y'][4 * i]
    return 2 * h * B / 45

print()
print('Trapezoidal rule: ', Trapezoidal_rule(data, h))
print("Simpson`s rule: ", Simpson_rule(data, h))
print("Boole`s rule: ", Boole_rule(data, h))