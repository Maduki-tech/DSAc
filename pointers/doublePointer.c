#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("x = %d\n", x);
    printf("&x = %p\n", &x);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    printf("&p = %p\n", &p);
    printf("pp = %p\n", pp);
    printf("*pp = %p\n", *pp);
    printf("**pp = %d\n", **pp);

    int y = 20;
    *pp = &y;
    printf("**pp = %d\n", **pp);

    printf("&pp = %p\n", &pp);


    return EXIT_SUCCESS;
}
