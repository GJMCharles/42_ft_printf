#include "ft_printf.h"
#include <stdio.h>

static void test(int *pa, int *pb)
{
    *pa = 10;
    *pb = 20;
}

int main(void) {

	// int n = 65;
	// char x[2] = "a";

    int a;
    int b;
    int *pa = &a;
    int *pb = &b;
    int x1 = 17;
	int x2 = 600;

    test(&a, &b);
    test(pa, pb);
    // printf("x = %p, a = %p, b = %p\n", x1, a, b);
	ft_printf("x = %p, a = %p, b = %p\n", x1, a, b);
	// printf("x = %p, a = %p, b = %p\n", x2, *pa, *pb);
	ft_printf("x = %p, a = %p, b = %p\n", x2, *pa, *pb);

	// printf("%d\n", printf("%p...%s\n", n, "a"));
	// printf("{%c}...{%p}\n", 'a', x);
	// ft_printf("{%c}...{%p}\n", 'a', x);

    // int nb = 65;
    int age = 32; // age and height not initialized
    int height = 182;

    ft_printf("I am '%c'='X'.\n", 'X');
    // printf("I am '%c'.\n", 'X');
    ft_printf("THIS IS A: => '%s#'\n", "test", "123");

    // ft_printf("I am %d cm tall.\n", age);
    // printf("I am %d cm tall.\n", age);
    // ft_printf("I am %d years old.\n", height);
    // printf("I am %d years old.\n", height);
    // printf("I wanna go to \"Panama\" again.\n"); // scaping double quotes
    // printf("I am %2$d tall and %1$d years old\n", age, height); // how to use
    // positional arguments in printf statement

    ft_printf("I wanna go to \"Panama\" again.\n"); // scaping double quotes
    // // how to use positional arguments in printf statement
    // printf("I am using the number pi: %'.2f\n", 3.1415939);
    // printf("#f => %06.f\n", 1.42);

    // printf("#X => %#X\n", 23);
    // printf("#o => %#o\n", 42);
    // printf("#x => %#x\n", 42);

    // printf("#X => %#X\n", 65);
    // printf("#o => %#o\n", 65);
    // printf("#x => %#x\n", 65);

    // printf("#F => %#F\n", 1.42);
    // printf("#f => %#f\n", 1.42);
    // printf("#A => %#A\n", 1.42);
    // printf("#a => %#a\n", 1.42);
    // printf("#e => %#e\n", 17.6);
    // printf("#E => %#E\n", 17.6);

    // printf("#g => %#g\n", 2.42);
    // printf("#G => %#G\n", 2.619);
    // Testing the %# formatting
    // printf("Testing for A: %#c ABC", 'A');

    // printf("%d\n", printf("Test 1 2 3: %s => %s ...\n", "'STRING'", "4242"));
    // printf("original:");
    // int a = printf(" %+d ", 0);
    // printf("\nmy function:");
    // int b = ft_printf(" %+d ", 0);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST2\n\n");
    // printf("original:");
    // a = printf(" %+d ", -1);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", -1);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST3\n\n");
    // printf("original:");
    // a = printf(" %+d ", 9);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 9);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST4\n\n");
    // printf("original:");
    // a = printf(" %+d ", 10);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 10);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST5\n\n");
    // printf("original:");
    // a = printf(" %+d ", -11);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", -11);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST6\n\n");
    // printf("original:");
    // a = printf(" %+d ", 15);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 15);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST7\n\n");
    // printf("original:");
    // a = printf(" %+d ", -16);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", -16);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST8\n\n");
    // printf("original:");
    // a = printf(" %+d ", 17);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 17);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST9\n\n");
    // printf("original:");
    // a = printf(" %+d ", 99);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 99);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST10\n\n");
    // printf("original:");
    // a = printf(" %+d ", 100);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 100);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST11\n\n");
    // printf("original:");
    // a = printf(" %+d ", 101);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", 101);
    // printf(" %d %d\n", a, b);

    // printf("\nTEST12\n\n");
    // printf("original:");
    // a = printf(" %+d ", -9);
    // printf("\nmy function:");
    // b = ft_printf(" %+d ", -9);
    // printf(" %d %d\n", a, b);
	return (0);
}
