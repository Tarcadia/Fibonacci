N=9999
x=rep(1,N)
for (i in 3:N){
  x[i]=x[i-1]+x[i-2]
}
print(x)
