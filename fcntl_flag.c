#include <stdio.h>
#include <fcntl.h>

void display_flag(char *, unsigned int);
void binary_print(unsigned int);

int main(int argc, char const *argv[])
{
    display_flag("O_RDONLY\t\t", O_RDONLY);
    display_flag("O_WRONLY\t\t", O_WRONLY);
    display_flag("O_RDRW\t\t\t", O_RDWR);
    printf("\n");
    display_flag("O_APPEND\t\t", O_APPEND);
    display_flag("O_TRUNC\t\t\t", O_TRUNC);
    display_flag("O_CREATE\t\t", O_CREAT);
    printf("\n");
    display_flag("O_WRONLY|O_APPEND|O_CREAT", O_WRONLY | O_APPEND | O_CREAT);
}

void display_flag(char *label, unsigned int val)
{
    printf("%s\t:%d\t:", label, val);
    binary_print(val);
    printf("\n");
}


void binary_print(unsigned int value)
{
    unsigned int mask = 0xff000000;
    unsigned int shift = 256 * 256 * 256;
    unsigned int byte, byte_iteratror, bit_iterator;

    for (byte_iteratror = 0; byte_iteratror < 4; byte_iteratror++)
    {
        byte = (value & mask) / shift;
        printf(" ");
        for (bit_iterator = 0; bit_iterator < 8; bit_iterator++)
        {
            if (byte & 0x80)
                printf("1");
            else
                printf("0");
            byte *= 2;
        }
        mask /=256;
        shift /=256;
    }
}