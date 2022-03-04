/*
 * Install the GMP library first,
 * then execute the commands below in the shell.
 *
 * > gcc fibonacci.c -O2 -Wall -lgmp -o fibonacci
 * > ./fibonacci
 *
 */

#include <stdio.h>
#include <gmp.h>

typedef mpz_t matrix[2][2];

mpz_t tmp_z;
matrix tmp_m, base;

void matrix_init(matrix m) {
    mpz_inits(m[0][0], m[0][1], m[1][0], m[1][1], NULL);
}

void matrix_clear(matrix m) {
    mpz_clears(m[0][0], m[0][1], m[1][0], m[1][1], NULL);
}

void matrix_set(matrix dst, const matrix src) {
    mpz_set(dst[0][0], src[0][0]);
    mpz_set(dst[0][1], src[0][1]);
    mpz_set(dst[1][0], src[1][0]);
    mpz_set(dst[1][1], src[1][1]);
}

// C = AB
void matrix_mul(matrix c, const matrix a, const matrix b) {
// get(c[i][j])
#define MATRIX_MUL(i, j) \
    mpz_mul(c[i][j], a[i][0], b[0][j]); \
    mpz_mul(tmp_z, a[i][1], b[1][j]); \
    mpz_add(c[i][j], c[i][j], tmp_z);

    MATRIX_MUL(0, 0)
    MATRIX_MUL(0, 1)
    MATRIX_MUL(1, 0)
    MATRIX_MUL(1, 1)

#undef MATRIX_MUL
}

void matrix_pow(matrix result, int exp) {
    mpz_init_set_ui(result[0][0], 1);
    mpz_init_set_ui(result[0][1], 0);
    mpz_init_set_ui(result[1][0], 0);
    mpz_init_set_ui(result[1][1], 1);

    mpz_init_set_ui(base[0][0], 0);
    mpz_init_set_ui(base[0][1], 1);
    mpz_init_set_ui(base[1][0], 1);
    mpz_init_set_ui(base[1][1], 1);

    for ( ; exp; exp >>= 1) {
        if (exp & 1) {
            matrix_mul(tmp_m, result, base);
            matrix_set(result, tmp_m);
        }
        matrix_mul(tmp_m, base, base);
        matrix_set(base, tmp_m);
    }
}

/*
 *          (0  1)     
 * (A  B)   (    )  =  (B  A+B)
 *          (1  1)
 */
void print_fibonacci(int q) {
    matrix result;

    mpz_init(tmp_z);
    matrix_init(tmp_m);
    matrix_init(base);
    matrix_init(result);

    matrix_pow(result, q);
    gmp_printf("Result: %Zd\n", result[1][0]);

    mpz_clear(tmp_z);
    matrix_clear(tmp_m);
    matrix_clear(base);
    matrix_clear(result);
}

int main() {
    int q;
    printf("Enter fibonacci[q]: ");
    scanf("%d", &q);
    print_fibonacci(q);
    return 0;
}
