/*
 * Install the GMP library first,
 * then execute the commands below in the shell.
 *
 * > g++ fibonacci-gmp.cpp -O2 -Wall -lgmpxx -lgmp -o fibonacci-gmp
 * > ./fibonacci-gmp
 *
 */

#include <iostream>
#include <gmpxx.h>


/*
 *  F(2n-1) = F^2(n) + F^2(n-1)
 *  F(2n)   = (2F(n-1) + F(n))F(n)
 *          = (2F(n+1) - F(n))F(n)
 */
mpz_class fibonacci (unsigned q) {
    int zero_bits;
    unsigned mask;
    mpz_class tmp, f0, f1;

    if (q == 0) {
        return 0;
    }

    f0 = f1 = 1;

    zero_bits = __builtin_clz(q);
    mask = (1U << (31 - zero_bits)) >> 1;

    for (; mask > 0; mask >>= 1) {
        tmp = f0*f0 + f1*f1;
        if (q & mask) {
            f1 = (2*f0 + f1)*f1;
            f0 = tmp;
        } else {
            f0 = (2*f1 - f0)*f0;
            f1 = tmp;
        }
    }

    return f0;
}

int main() {
    unsigned q;
    mpz_class a;

    std::cout << "Enter fibonacci[q]: ";
    std::cin >> q;

    a = fibonacci(q);

    std::cout << "Result: " << a << "\n";

    return 0;
}
