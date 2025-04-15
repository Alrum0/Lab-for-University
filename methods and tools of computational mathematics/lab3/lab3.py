import math
import numpy as np
import pandas as pd

first = -4
last = 4
h = 0.01

firstLast = np.arange(first, last+h, h)

def F(x):
    y = (math.cos(x) ** 2) * math.sin(1.6 * x) * (x**2 + x + 1)
    return y

Y = []
for i in range(len(firstLast)):
    Y.append(F(firstLast[i]))

data = pd.DataFrame({'X': firstLast, 'Y': Y})

dY = []
dY.append((data['Y'][1] - data['Y'][0]) / h)
for i in range(1, len(firstLast) - 1):
    dY.append((data['Y'][i + 1] - data['Y'][i - 1]) / (2 * h))
dY.append((data['Y'][len(firstLast) - 1] - data['Y'][len(firstLast) - 2]) / h)

data.insert(loc=len(data.columns), column='dY', value=dY)

def derF(x):
    y = math.cos(x) * (-2 * (x**2 + x + 1) * math.sin(x) * math.sin(1.6 * x) + 1.6 * (x**2 + x + 1) * math.cos(x) * math.cos(1.6 * x) + (2 * x + 1) * math.sin(1.6 * x) * math.cos(x))
    return y

dF = []
for i in range(len(firstLast)):
    dF.append(derF(firstLast[i]))

data.insert(loc=len(data.columns), column='dF', value=dF)


delta_dF_dY = []
for i in range(len(firstLast)):
    delta_dF_dY.append(data['dF'][i] - data['dY'][i])

data.insert(loc=len(data.columns), column='dF-dY', value=delta_dF_dY)
ddY = []
ddY.append((data['Y'][0] - 2 * data['Y'][1] + data['Y'][2]) / (h**2))
for i in range(1, len(firstLast) - 1):
    ddY.append((data['Y'][i + 1]- 2* data['Y'][i] + data['Y'][i - 1]) / (h**2))

ddY.append((data['Y'][len(firstLast) - 1] - 2*data['Y'][len(firstLast) - 2] + data['Y'][len(firstLast) - 3]) / (h**2))
data.insert(loc=len(data.columns), column='ddY', value=ddY)

def der_2_F(x):
 
    y = math.sin(1.6 * x) * (2 * (x**2 + x + 1) * (math.sin(x)**2) - 2 * x * (x + 1) * (math.cos(x)**2) - 4 * (2 * x + 1) * math.sin(x) * math.cos(x)) - 2.56 * (x**2 + x + 1) * math.sin(1.6 * x) * (math.cos(x)**2) + 3.2 * math.cos(1.6 * x) * math.cos(x) * ((2 * x + 1) * math.cos(x) - 2 * (x**2 + x + 1) * math.sin(x))
    return y

ddF = []
for i in range(len(firstLast)):
    ddF.append(der_2_F(firstLast[i]))

data.insert (loc=len (data.columns), column='ddF', value=ddF)
delta_ddF_ddY = []
for i in range(len(firstLast)):
    delta_ddF_ddY.append(data['ddF'][i] - data['ddY'][i])

data.insert (loc=len(data.columns), column='ddF-ddY', value=delta_ddF_ddY)

pd.set_option('display.width', 0)  

with pd.option_context('display.max_columns', None):
    print (data)

data.to_excel('derivatives.xlsx')