#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);
    printf("&x = %p\n", &x);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    printf("&p = %p\n", &p);

    return EXIT_SUCCESS;
}
