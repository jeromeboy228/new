#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    long int second_since_epoch;
    struct tm current_time, *time_ptr;
    int hour, minute, second, day, month, year;

    second_since_epoch=time(0); // передает значение ,сколько прошло с начала эры,так сказать

    printf("time() секунд с начала эры :%ld\n",second_since_epoch);
    time_ptr=&current_time;
    localtime_r(&second_since_epoch,time_ptr);
    hour=current_time.tm_hour;
    minute=time_ptr->tm_min;
    second=current_time.tm_sec;
    printf("время %d h. %d min\n",hour,minute);
    return 0;
}
