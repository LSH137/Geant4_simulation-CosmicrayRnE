//
// Created by lsh on 20. 3. 4..
//

#include "FileIO.h"
#include "Constant.h"
#include <cstdio>
#include <cstring>
#include <dirent.h>

//int runningDay[Daynum];
//extern int numberOfDay;



/////////////////////////////////////////////////////////////////////////////////////////

int NumberOftxtFile(const char d[150])
{
    DIR *path;
    char *p1,*p2;
    int ret;
    struct dirent *dir;
    int name_index = 0;

    path = opendir(d);
    if (path)
    {
        while ((dir = readdir(path)) != nullptr)
        {
            p1 = strtok(dir->d_name,".");
            p2 = strtok(nullptr,".");

            if(p2 != nullptr)
            {
                ret = strcmp(p2,"txt");

                if(ret == 0)
                {
                    //printf("%d: %s\n",name_index + 1, p1);
                    name_index ++;
                }
            }

        }
        closedir(path);
    }
    return name_index;
}

int NumberOfcsvFile(const char d[150])
{
    DIR *path;
    char *p1,*p2;
    int ret;
    struct dirent *dir;
    //printf("number of csv file called\n");
    int name_index = 0;

    path = opendir(d);
    if (path)
    {
        while ((dir = readdir(path)) != nullptr)
        {
            p1 = strtok(dir->d_name,".");
            p2 = strtok(nullptr,".");

            if(p2 != nullptr)
            {
                ret = strcmp(p2,"csv");

                if(ret == 0)
                {
                    //printf("%d: %s\n",name_index + 1, p1);
                    name_index ++;
                }
            }

        }
        closedir(path);
    }
    printf("number of csv file: %d\n", name_index);
    return name_index;
}

void FileName(const char d[150], char(*file_name)[150], const char type[])
{
    DIR *path;
    char *p1,*p2;
    int ret;
    struct dirent *dir;
    int name_index = 0;

    //printf(">>success to enter FileName\n");

    path = opendir(d);
    if (path)
    {
        while ((dir = readdir(path)) != nullptr)
        {
            p1 = strtok(dir->d_name,".");
            p2 = strtok(nullptr,".");

            if(p2 != nullptr)
            {
                ret = strcmp(p2,type);

                if(ret == 0)
                {
                    for(int i = 0; p1[i] != '\0'; i++)
                        file_name[name_index][i] = p1[i];

                    name_index ++;
                }
            }

        }
        closedir(path);
    } else
        printf(">>error occur while get data file name\n");

    //printf("||FileName end\n");
}