import pandas as pd
from math import exp, e

def Gauss(A, B):
    n = len(B)
    for i in range(n):
        max_el = abs(A[i][i])
        max_row = i
        for k in range(i + 1, n):
            if abs(A[k][i]) > max_el:
                max_el = abs(A[k][i])
                max_row = k
        
        A[i], A[max_row] = A[max_row], A[i]
        B[i], B[max_row] = B[max_row], B[i]

        if A[i][i] == 0:
            print(f"Warning: Zero pivot element at A[{i}][{i}] after pivoting. System might be singular.")

        for k in range(i + 1, n):
            if A[i][i] == 0: 
                continue 
            c = -A[k][i] / A[i][i]
            for j in range(i, n): 
                if j == i: 
                    A[k][j] = 0 
                else:
                    A[k][j] += c * A[i][j]
            B[k] += c * B[i]

    x = [0.0 for _ in range(n)] 
    for i in range(n - 1, -1, -1):
        if A[i][i] == 0:
            raise ValueError(f"Zero diagonal element A[{i}][{i}] during back substitution. Cannot solve.")
        x[i] = B[i]
        for j in range(i + 1, n):
            x[i] -= A[i][j] * x[j]
        x[i] /= A[i][i]
    return x

a = 0.0           # ліва межа
y_a = 4.0         # y(0) = 4
b = 1.0           # права межа
y_b = 3.0 + 3.0*e   # y(1) = 3 + 3e

n = 7  
delta_x = (b - a) / (n + 1)

def exact_solution_F(x):
    return 2.0 * (x ** 2) + 3.0 * exp(x) + 1.0


def R_func(x_val):
    return 4.0*x_val + 6.0*exp(x_val) + 4.0

data_X = [a + i * delta_x for i in range(n + 2)]


data_F_exact = [exact_solution_F(x) for x in data_X]

A = [[0.0] * n for _ in range(n)] 
B = [0.0] * n                     

A[0][0] = -4.0
A[0][1] = 2.0 + delta_x
x1 = data_X[1] 
B[0] = 2.0 * delta_x**2 * R_func(x1) - (2.0 - delta_x) * y_a


for i in range(1, n - 1):
    A[i][i - 1] = 2.0 - delta_x
    A[i][i] = -4.0
    A[i][i + 1] = 2.0 + delta_x
    x_curr = data_X[i+1] 
    B[i] = 2.0 * delta_x**2 * R_func(x_curr)

A[n - 1][n - 2] = 2.0 - delta_x
A[n - 1][n - 1] = -4.0
xn_internal = data_X[n] 
B[n - 1] = 2.0 * delta_x**2 * R_func(xn_internal) - (2.0 + delta_x) * y_b

C = Gauss(A, B)

data_Y_numerical = [y_a] + C + [y_b]

result = pd.DataFrame({
    'x': data_X,
    'y(x)': data_Y_numerical,
    'F(x)': data_F_exact  
})

# Додаємо похибку
result['F(x) - y(x)'] = result['F(x)'] - result['y(x)']


print(result.to_string(float_format="%.6f")) 

result.to_excel('boundary_value_problem_corrected.xlsx', index=False)