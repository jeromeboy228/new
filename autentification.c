#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int autentif(char *);

int main(int argc, char  *argv[])
{
    if (argc < 2)
    {
        printf("введите пароль %s password\n", argv[0]);
    exit(0);
    }
    if (autentif(argv[1]))
    {
        printf("=============\n");
        printf("Доступ разрешен\n");
        printf("=============\n");
    }
    else
    {
        printf("Доступ запрещен\n");
    }

    return 0;
}
int autentif(char *password){
    int flag=0;
    char pass_buf[10];
    strcpy(pass_buf,password);
    if(strcmp(password,"good")==0) // с этим ты и проебался дурачок,ЕСЛИ СТРОКИ ОДИНАКОВЫ Т.Е. ВОЗВРАЩАЮТ 0
        flag=1;
    if(strcmp(password,"egor")==0) // ТОГДА ,ТУПОЙ ТЫ ШАКАЛ , И БУДЕТ FLAG = 1 
        flag=1;
        return flag;
}
