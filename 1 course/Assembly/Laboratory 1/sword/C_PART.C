#include <stdio.h>

extern signed int calculate(signed int a, signed int c, signed int d);

int main()
{
    signed int a = 49, c = 42, d = 1;

    printf("\nPositive:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    a = -a;
    c = -c;
    d = -d;

    printf("Negative:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    return 0;
}