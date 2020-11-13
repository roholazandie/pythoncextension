import time
import calculate

#print(add.__doc__)

a = 150000
b = 34

t1 = time.time()
x = calculate.sub(a, b)
t2 = time.time()
print("\n")
print(t2-t1)

x = calculate.fibonacci(5)
print(x)

############################
n = 100000
t1 = time.time()
x = calculate.heavy(n)
t2 = time.time()
elapsed_c = t2 - t1
print(elapsed_c)

t1 = time.time()
x = 1
for i in range(n):
    x = x*i
t2 = time.time()
elapsed_py = t2 - t1
print(elapsed_py)

print(elapsed_py/elapsed_c)