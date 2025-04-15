
x = float(input("Введіть наближене значення величини X: "))
delta_x = float(input("Введіть абсолютну похибку вимірювання величини X: "))
y = float(input("Введіть наближене значення величини Y: "))
delta_y = float(input("Введіть абсолютну похибку вимірювання величини Y: "))

omega_x = delta_x / x
omega_y = delta_y / y

def delta_sum(delta_x, delta_y):
    return delta_x + delta_y

def delta_sub(delta_x, delta_y):
    return delta_x - delta_y

def delta_mult(x, y, delta_x, delta_y):
    return delta_x * delta_y + delta_x * y + delta_y * x

def delta_div(x, y, delta_x, delta_y):
    return (delta_x + x) / (delta_y + y) - x / y

def omega_sum(x, y, omega_x, omega_y):
    return x / (x + y) * omega_x + y / (x + y) * omega_y

def omega_sub(x, y, omega_x, omega_y):
    return x / (x - y) * omega_x - y / (x - y) * omega_y

def omega_mult(x, y, omega_x, omega_y):
    return (omega_x * omega_y) + omega_x + omega_y

def omega_div(x, y, omega_x, omega_y):
    return (omega_x - omega_y) / (omega_y + 1)

print("\n")
print("-----------------------------------------")
print("\n")

print(f"Відносна похибка значення величини X: {omega_x}")
print(f"Відносна похибка значення величини Y: {omega_y}")
print("\n")
print(f"Абсолютна похибка суми X + Y =: {delta_sum(delta_x, delta_y)}")
print(f"Абсолютна похибка різниці X - Y =: {delta_sub(delta_x, delta_y)}")
print(f"Абсолютна похибка добутку X * Y =: {delta_mult(x, y, delta_x, delta_y)}")
print(f"Абсолютна похибка частки X / Y =: {delta_div(x, y, delta_x, delta_y)}")
print("\n")

print(f"Відносна похибка суми X + Y =: {omega_sum(x, y, omega_x, omega_y)}")
print(f"Відносна похибка різниці X - Y =: {omega_sub(x, y, omega_x, omega_y)}")
print(f"Відносна похибка добутку X * Y =: {omega_mult(x, y, omega_x, omega_y)}")
print(f"Відносна похибка частки X / Y =: {omega_div(x, y, omega_x, omega_y)}")
