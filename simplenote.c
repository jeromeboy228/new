#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *prog_name, char *file_name)
{
    printf("Примеменено : %s к файлу %s \n", prog_name, file_name);
    exit(0);
}
void fatal(char *);
void ec_malloc(unsigned int);

int main(int argc, char const *argv[])
{
    int fd;
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
    if (write(fd, buffer, strlen(buffer)) == -1)
    {
        fatal("ошибка записи буфера в файл");
    }
    if (close(fd) == -1)
        fatal("ошибка закрытия файла\n");
    printf("заметка созданна \n");
    free(buffer);
    free(datafile);

    return 0;
}

void fatal(char *msg)
{
    char error_msg[100];
    strcpy(error_msg, "[!!] критическая ошибка\n");
    strncat(error_msg, msg, 50);
    perror(error_msg);
    exit(-1);
}

void ec_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    {
        fatal("в функции ec_malloc при выделении памяти");
    }
    return ptr;
}