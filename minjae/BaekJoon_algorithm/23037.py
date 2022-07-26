import math

def pow(n):
    return math.pow(n,5)

num = int(input())
a = num % 10
num = int(num/10)
b = num % 10
num = int(num/10)
c = num % 10
num = int(num/10)
d = num % 10
num = int(num/10)
e = num % 10
num = int(num/10)

print(int(pow(a)+pow(b)+pow(c)+pow(d)+pow(e)))