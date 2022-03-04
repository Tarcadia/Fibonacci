#include <iostream>

void add(const char *x1, const char *x2, char *x3) {
    int c = 0;
    for (int i = 49; i >= 0; --i) {
        int sum = (int) *(x1 + i) + (int) *(x2 + i) - 96;
        sum += c;
        if (sum > 9) {
            sum -= 10;
            *(x3 + i) = (char) (sum + 48);
            c = 1;
        } else {
            *(x3 + i) = (char) (sum + 48);
            c = 0;
        }
    }
}

void print(const char *x) {
    bool zero = true;
    for (int i = 0; i < 50; ++i)
        if (*(x + i) == '0' && zero)
            continue;
        else {
            std::cout << *(x + i);
            zero = false;
        }
}

int main() {
    const int N = 32768;
    char x[N][50];
    char a[50];
    for (auto &i: x) {
        for (char &j: i) {
            j = '0';
        }
    }
    x[1][49] = '1';
    for (int i = 2; i < N; ++i) {
        add(x[i - 1], x[i - 2], x[i]);
    }
    int q;
    std::cout << "Enter fibonacci[q]: ";
    std::cin >> q;
    std::cout << "Result: ";
    print(x[q]);
    for (int i = 0; i < 50; ++i)
        *(a + i) = *(x[q] + i);
    return 0;
}