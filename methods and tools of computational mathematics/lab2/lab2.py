import numpy
import scipy.interpolate as spi
import matplotlib.pyplot as plt

x = [0, 0.5, 1, 2, 3.5, 4, 6]
f = [12.234, 9.239, 8.567, -1.098, 5.756, 7.345, 5.678]

d = len(x)

A = []
for j in range(d):
    s = []
    for i in range(d - 1, -1, -1):
        s.append(x[j]**i)
    A.append(s)

def Gauss(A, b):
    n = len(A)
    for i in range (n):
       A[i].append(b[i]) 
    for i in range(n):
          max_row = i
          for j in range(i + 1, n):
              if abs(A[j][i]) > abs(A[max_row][i]):
                  max_row = j
          A[i], A[max_row] = A[max_row], A[i]
          for j in range(i + 1, n):
              factor = A[j][i] / A[i][i]
              for k in range(i, n + 1):
                  A[j][k] -= factor * A[i][k]
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = A[i][n] / A[i][i]
        for j in range(i):
            A[j][n] -= A[j][i] * x[i]
    return x   

c = Gauss(A, f)

polynom_string = 'P(x) = '
for i in range(d):
    polynom_string = polynom_string + str(c[i]) + '*x^' + str(d - i -1) + '+'
polynom_string = polynom_string[:-5].replace('+-', '-').replace('x^1', 'x')

print('\nІнтерполяційний поліном')
print(polynom_string)

d = len(x)
A = []
for j in range(d-1, -1, -1):
    s = [1]
    p = 1
    for i in range(0, j):
        p = p * (x[j] - x[i])
        s.append(p)
    s.reverse()
    A.append(s)

def scalar_product(A, f, n):
    s = 0
    r = len(A[n])
    for i in range(1, r - 1):
        s = s + f[i]*A[n][r - i - 1]
    return s

for i in range(1, d):
    f[i] = (f[i] - f[0] - scalar_product(A, f, d-i-1)) / A[d - i - 1][0]

polynom_string = 'N(x) = ' + str(f[0]) + '+'
p = '*(x-' + str(x[0]) + ')'
for i in range(1, d):
    polynom_string = polynom_string + str(f[i]) + p + '+'
    p = p + '*(x-' + str(x[i]) + ')'
polynom_string = polynom_string[:-1].replace('+-', '-')

print("\nІнтерполяційний поліном Ньютона")
print(polynom_string)


d = len(x)

a = []
L = []

for j in range(d):
    p = 1
    s = ''
    for i in range(d):
        if i == j:
            continue
        else:
            p = p * (x[j] - x[i])
            s = s + '(x-' + str(x[i]) + ')'
    k = f[j] / p
    a.append(k)
    L.append(s)


polynom_string = 'L(x) = '
for i in range(d):
    polynom_string += str(a[i]) + '*' + L[i] + '+'
polynom_string = polynom_string[:-1].replace('+-', '-')

print("\nІнтерполяційний поліном Лагранжа")
print(polynom_string)


def lagrange_interpolation(x, f):
    d = len(x)
    a = []
    L = []
    
    for j in range(d):
        p = 1
        s = ''
        for i in range(d):
            if i == j:
                continue
            else:
                p *= (x[j] - x[i])
                s += f'(x-{x[i]})'
        k = f[j] / p
        a.append(k)
        L.append(s)
    
    polynom_string = 'L(x) = '
    for i in range(d):
        polynom_string += f'{a[i]}*{L[i]}+'
    polynom_string = polynom_string[:-1].replace('+-', '-')
    
    def P(x_val):
        result = 0
        for j in range(d):
            term = a[j]
            for i in range(d):
                if i != j:
                    term *= (x_val - x[i])
            result += term
        return result
    
    return P, polynom_string


x = numpy.array([1, 2, 3, 4, 5, 6, 7])
y = numpy.array([12.234, 9.239, 8.567, -1.098, 5.756, 7.345, 5.678])

p = spi.lagrange(x, y)
print(p)

z = numpy.linspace(1, 7, 100)
plt.plot(z, p(z), '-')
plt.plot(x, y, 'o')
plt.legend(['$L(x)$', 'data'])
plt.xlabel('x'); plt.ylabel('y'); plt.show()