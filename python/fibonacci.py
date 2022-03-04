x = [0] * 10000;
x[0] = 0;
x[1] = 1;
for i in range(2, 10000):
    x[i] = (x[i-1] + x[i-2])

q = int(input());
a = x[q];
print(a);