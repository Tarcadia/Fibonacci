import java.math.BigInteger;
import java.util.Scanner;

class Matrix {
    public BigInteger x[][] = new BigInteger[2][2];

    public Matrix() {}

    public Matrix(int indicator) {
        if (indicator == 0) {
            x[0][0] = x[0][1] = x[1][0] = x[1][1] = BigInteger.ZERO;
        } else {
            x[0][0] = x[1][1] = BigInteger.ONE;
            x[0][1] = x[1][0] = BigInteger.ZERO;
        }
    }

    public Matrix(Matrix o) {
        x[0][0] = o.x[0][0];
        x[0][1] = o.x[0][1];
        x[1][0] = o.x[1][0];
        x[1][1] = o.x[1][1];
    }

    public Matrix multiply(Matrix o) {
        Matrix a = new Matrix(0);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    a.x[i][j] = a.x[i][j].add(x[i][k].multiply(o.x[k][j]));
        return a;
    }

    public Matrix pow(int exp) {
        Matrix base = new Matrix(this);
        Matrix result = new Matrix(1);
        for ( ; exp > 0; exp >>= 1) {
            if ((exp & 1) == 1)
                result = result.multiply(base);
            base = base.multiply(base);
        }
        return result;
    }
}

public class Fibonacci {
    public static BigInteger getValue(int q) {
        Matrix a = new Matrix();
        a.x[0][0] = BigInteger.ZERO;
        a.x[0][1] = a.x[1][0] = a.x[1][1] = BigInteger.ONE;
        a = a.pow(q);
        return a.x[1][0];
    }

    public static void main(String[] args) {
        System.out.print("Enter fibonacci[q]: ");
        Scanner cin = new Scanner(System.in);
        int q = cin.nextInt();
        cin.close();
        System.out.print("Result: ");
        System.out.println(getValue(q));
    }
}