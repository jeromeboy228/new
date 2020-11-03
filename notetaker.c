#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"
void usage(char *prog_name, char *file_name)
{
    printf("Примеменено : %s к файлу %s \n", prog_name, file_name);
    exit(0);
}
void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char const *argv[])
{
    int fd,userid;
    char *buffer, *datafile;
    buffer = (char *)malloc(200);
    datafile = (char *)malloc(20);
    strcpy(datafile, "notes.txt");
    if (argc < 2)
    {
        usage(argv[0], datafile);
    }
    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer %p \t%s\n", buffer, buffer);
    printf("[DEBUG] filename %p \t%s\n", datafile, datafile);
    strncat(buffer, "\n", 1);

    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
        fatal("ошибка при кткрытии файла");
    printf("[DEBUG] дескриптор файла %d\n", fd);
    
    userid=getuid();
    if(write(fd,&userid,4)==-1) // write записывает в файл fd число байт 4 записи &userid
        fatal("в функции main() при записи userid()");
    write(fd,"\n",1);   
    
    
    if (write(fd, buffer, strlen(buffer)) == -1)
    {
        fatal("ошибка записи буфера в файл");
    }
    write(fd,"\n",1);
    if (close(fd) == -1)
        fatal("ошибка закрытия файла\n");
    printf("заметка созданна \n");
    free(buffer);
    free(datafile);

    return 0;
}
