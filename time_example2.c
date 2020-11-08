#include <stdio.h>
#include <time.h>

void dump_time_struct_bytes(struct tm *, int);

int main(int argc, char const *argv[])
{
    long int second_sinse_epoch;
    int second, minute, hour, day, month, year, *int_ptr;
    struct tm current_time, *time_ptr;
    second_sinse_epoch = time(0);
    printf("время с начала эпохи %ld\n", second_sinse_epoch);
    time_ptr = &current_time;
    localtime_r(&second_sinse_epoch, time_ptr);
    hour = time_ptr->tm_hour;     // прямой доступ
    minute = current_time.tm_min; // доступ по указателю
    second = *((int *)time_ptr);  // приведение типа
    printf("%02d:%02d:%02d\n", hour, minute, second);
    dump_time_struct_bytes(&current_time, sizeof(current_time));
    minute=hour=0;
    int_ptr = (int *)time_ptr;
    for(int i=0;i<3;i++){
    printf("int_ptr @ %p  %d\n", int_ptr, *int_ptr);
    int_ptr++;}
    return 0;
}

void dump_time_struct_bytes(struct tm *time_ptr, int size)
{
    unsigned char *raw_ptr;
    printf("байты в структуре по адресу %p\n", time_ptr);
    for (int i = 0; i < size; i++)
    {
        printf("%02x ", raw_ptr[i]);
        if (i % 16 == 15)
            printf("\n");
    }

    printf("\n");
}