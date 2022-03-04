function fibonacci(n, current, last)
	if n == 0 then
		return current
	else
		return fibonacci(n - 1, current + last, current)

n = io.read("*number")
print(fibonacci(n - 1, 1, 0))
