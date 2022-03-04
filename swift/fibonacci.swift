import Foundation

func fibonacci(n: Int) -> Int {
    if n == 1 || n == 2 {
        return 1
    } else {
        return fibonacci(n: n - 1) + fibonacci(n: n - 2)
    }
}

print(fibonacci(n: Int(readLine()!)!))
