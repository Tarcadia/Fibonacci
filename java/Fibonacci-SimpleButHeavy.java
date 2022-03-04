
package net.tarcadia.fibonacci

import java.util.List;

public class fibonacci {

    static int N = 10000;

    static long getFibonacci(int q) {
        List<Long> x = new ArrayList<>();
        x.add(0);
        x.add(1);
        for (int i = 2; i < N; i++) {
            x.add(x.get(i-1) + x.get(i-2));
        }
        return x.get(q)
    }
}
