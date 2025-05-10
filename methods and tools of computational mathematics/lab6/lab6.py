import pandas as pd
from math import exp

x0 = 0
y0 = 3

delta_x = 0.01
n = 10
def F(x):
    y = 2 * (x ** 2) + x + 2 * exp(-x) + 1
    return y

data_X = [x0]
data_Y = [y0]
data_F = [F(x0)]

for i in range(n):
    data_X.append(x0 + delta_x)
    data_Y.append(y0 + delta_x * (2 * (x0 ** 2) + 5 * x0 + 2 - y0))
    data_F.append(F(x0 + delta_x))
    y0 = y0 + delta_x * (2 * (x0 ** 2) + 5 * x0 + 2 - y0)
    x0 = x0 + delta_x

print('Результат обчислень')
print()
data = pd.DataFrame({'x': data_X, 'y(x)': data_Y, 'F(x)': data_F})
data.insert(loc=len(data.columns), 
            column='F(x)-y(x)', value=data['F(x)'] - data['y(x)'])
print(data)
data.to_excel('Cauchy_problem.xlsx')

