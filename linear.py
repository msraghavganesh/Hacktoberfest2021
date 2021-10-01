#Contributing python codes to approximate solutions
# JACOBI_METHOD ITERATIVE SOLUTION
# Defining equations to be solved
# in diagonally dominant form
f1 = lambda x,y,z: (85 + 2*z - 3*y)/15
f2 = lambda x,y,z: (51 - 2*x - z)/10
f3 = lambda x,y,z: (5 + 2*y - x)/8

# Initial setup
x0 = 0
y0 = 0
z0 = 0
count = 1

# Reading tolerable error
e = float(input('Enter tolerable error: '))

# Implementation of Jacobi Iteration
print('\nCount\tx\ty\tz\n')

condition = True

while condition:
    x1 = f1(x0,y0,z0)
    y1 = f2(x0,y0,z0)
    z1 = f3(x0,y0,z0)
    print('%d\t%0.4f\t%0.4f\t%0.4f\n' %(count, x1,y1,z1))
    e1 = abs(x0-x1);
    e2 = abs(y0-y1);
    e3 = abs(z0-z1);
    
    count += 1
    x0 = x1
    y0 = y1
    z0 = z1
    
    condition = e1>e and e2>e and e3>e

print('\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n'% (x1,y1,z1))

# GUASS SEIDAL ITERATION
# Defining equations to be solved
# in diagonally dominant form
f1 = lambda x,y,z: (17-y+2*z)/20
f2 = lambda x,y,z: (-18-3*x+z)/20
f3 = lambda x,y,z: (25-2*x+3*y)/20

# Initial setup
x0 = 0
y0 = 0
z0 = 0
count = 1

# Reading tolerable error
e = float(input('Enter tolerable error: '))

# Implementation of Gauss Seidel Iteration
print('\nCount\tx\ty\tz\n')

condition = True

while condition:
    x1 = f1(x0,y0,z0)
    y1 = f2(x1,y0,z0)
    z1 = f3(x1,y1,z0)
    print('%d\t%0.4f\t%0.4f\t%0.4f\n' %(count, x1,y1,z1))
    e1 = abs(x0-x1);
    e2 = abs(y0-y1);
    e3 = abs(z0-z1);
    
    count += 1
    x0 = x1
    y0 = y1
    z0 = z1
    
    condition = e1>e and e2>e and e3>e

print('\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n'% (x1,y1,z1))

#BISECTION METHOD
# Raghav Ganesh
# Function Sample = x^3 - x^2 + 2
# Bisection Method!
def func(x):
    return x*x*x - x*x + 2


def bisection(a, b):
    if (func(a) * func(b) >= 0):
        print("You have not assumed right a and b\n")
        return

    c = a
    k = 0
    while ((b-a) >= 0.01):
        c = (a+b)/2
        if (func(c) == 0.0):
            break
        if (func(c)*func(a) < 0):
            b = c
        else:
            a = c
        print("stepAns", k, "= %.4f" % c)
        k += 1

    print("The value of root is : ", "%.4f" % c)


a = -200
b = 300
bisection(a, b)

#Newton Raphson Method