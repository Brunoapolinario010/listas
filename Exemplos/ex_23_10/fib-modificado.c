#include <stdio.h>

#define ulli unsigned long long int

ulli fib_rec(ulli n) {
   if (n == 0)
        return 0;
   if (n == 1)
        return 1;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

ulli fib_iter(ulli n) {
    ulli ant = 0, fib = 1;
    for (ulli i = 0; i < n; i++) {
        fib = fib + ant;
        ant = fib - ant;
    }
    return ant;
}

int main() {
    for (ulli i = 0; i < 100; i++)
        printf("fib(%llu) = %llu\n", i, fib_iter(i));
    return 0;
}
