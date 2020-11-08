#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("rand_max() %u\n", RAND_MAX);
    printf("случайные числа от 1 до 20\n");
    for (int i = 0; i < 5; i++)
        printf("%d\n", (rand() % 10) + 1);
}
