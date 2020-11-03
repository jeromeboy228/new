#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int value = 5;
    char buffer_one[8], buffer_two[8];
    strcpy(buffer_one, "one");
    strcpy(buffer_two, "two");
    printf("[ДО] buffer_one по адресу %p содержит %s\n", &buffer_one, buffer_one);
    printf("[ДО] buffer_two по адресу %p содержит %s\n", &buffer_two, buffer_two);
    printf("[ДО] value по адресу %p содержит %d\n", &value, value);
    printf("копируем argv[1] в buffer_two\n");
    strcpy(buffer_two,argv[1]);

    printf("[ПОСЛЕ] buffer_one по адресу %p содержит %s\n", &buffer_one, buffer_one);
    printf("[ПОСЛЕ] buffer_two по адресу %p содержит %s\n", &buffer_two, buffer_two);
    printf("[ПОСЛЕ] value по адресу %p содержит %d\n", &value, value);
    
}