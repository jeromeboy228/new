#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

#define FILENAME "notes.txt"
int print_notes(int, int, char *);
int find_user_note(int, int);
int search_note(char *, char *);
void fatal(char *);

int main(int argc, char const *argv[])
{
    int userid, printing = 1, fd;
    char searchstring[100];

    if (argc > 1)
        strcpy(searchstring, argv[1]);
    else
        searchstring[0] = 0;
    userid = getuid();
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1)
        fatal("в функции main() при откытии файла на чтение\n");
    while (printing)
        printing = print_notes(fd, userid, searchstring);
    printf("----[конец данных касающихся заметки]----\n");
    close(fd);

    return 0;
}

int print_notes(int fd, int uid, char *searchstring)
{
    int note_leigh;
    char byte = 0, note_buffer[100];
    note_leigh = find_user_note(fd, uid);
    if (note_leigh == -1)
        return 0;

    read(fd, note_buffer, note_leigh);
    note_buffer[note_leigh] = 0;
    if (search_note(note_buffer, searchstring))
        printf(note_buffer);
    return 1;
}

int find_user_note(int fd, int user_uid)
{
    int note_uid = -1;
    unsigned char byte;
    int length;

    while (note_uid != user_uid)
    {
        if (read(fd, &note_uid, 4) != 4)
            return -1;
        if (read(fd, &byte, 1) != 1)
            return -1;
        byte = length = 0;
        while (byte != '\n')
        {
            if (read(fd, &byte, 1) != 1)
                return -1;
            length++;
        }
    }
    lseek(fd, length * -1, SEEK_CUR);
    printf("[DEBUG] обнаружена заметка длинной %d для пользователя id %d\n", length, note_uid);
    return length;
}

int search_note(char *note, char *keyword)
{
    int i, keyword_length, match = 0;
    keyword_length = strlen(keyword);
    if (keyword_length == 0)
        return 1;

    for (i = 0; i < strlen(note); i++)
    {
        if (note[i] == keyword[match])
            match++;
        else
        {
            if (note[0] == keyword[0])
                match = 1;
            else
                match = 0;
        }
        if (match == keyword_length)
            return 1;
    }
    return 0;
}