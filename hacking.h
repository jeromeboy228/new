void fatal(char *msg)
{
    char error_msg[100];
    strcpy(error_msg, "[!!] критическая ошибка\n");
    strncat(error_msg, msg, 50);
    perror(error_msg);
    exit(-1);
}


void *ec_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    {
        fatal("в функции ec_malloc при выделении памяти");
    }
    return ptr;
}