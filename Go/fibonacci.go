package main

import "fmt"

func fib(index int) int {
	if index == 0 {
		return 0
	}
	if index == 1 {
		return 1
	}
	return fib(index-1) + fib(index-2)
}

func main() {
	fmt.Println(fib(20))
}
