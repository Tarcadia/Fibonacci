/*
 * Install the GMP library first,
 * then execute the commands below in the shell.
 *
 * > gcc fibonacci-bottom-up.c -O2 -Wall -lgmp -o fibonacci
 * > ./fibonacci
 *
 */

#include <stdio.h>
#include <gmp.h>


/*
 *  F(2n-1) = F^2(n) + F^2(n-1)
 *  F(2n)   = (2F(n-1) + F(n))F(n)
 *          = (2F(n+1) - F(n))F(n)
 */
void fibonacci (mpz_t res, unsigned q) {
    int zero_bits;
    unsigned mask;
    mpz_t tmp, tmp2, f0, f1;

    if (q == 0) {
        mpz_set_ui(res, 0);
        return;
    }

    mpz_inits(tmp, tmp2, f0, f1, NULL);
    mpz_set_ui(f0, 1);
    mpz_set_ui(f1, 1);

    zero_bits = __builtin_clz(q);
    mask = (1U << (31 - zero_bits)) >> 1;

    for (; mask > 0; mask >>= 1) {
        mpz_mul(tmp, f0, f0);
        mpz_mul(tmp2, f1, f1);
        mpz_add(tmp, tmp, tmp2);
        if (q & mask) {
            mpz_mul_2exp (tmp2, f0, 1);
            mpz_add (tmp2, tmp2, f1);
            mpz_mul(f1, tmp2, f1);
            mpz_set(f0, tmp);
        } else {
            mpz_mul_2exp (tmp2, f1, 1);
            mpz_sub (tmp2, tmp2, f0);
            mpz_mul(f0, tmp2, f0);
            mpz_set(f1, tmp);
        }
    }

    mpz_set(res, f0);
    mpz_clears(tmp, tmp2, f0, f1, NULL);
}

int main() {
    unsigned q;
    mpz_t a;

    printf("Enter fibonacci[q]: ");
    scanf("%d", &q);

    mpz_init(a);
    fibonacci(a, q);

    gmp_printf("Result: %Zd\n", a);
    mpz_clear(a);

    return 0;
}
