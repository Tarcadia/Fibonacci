
x0 = 0
x1 = 1
q = int(input())
for i in range(2, q):
    x = x0 + x1
    x0 = x1
    x1 = x

print(x)