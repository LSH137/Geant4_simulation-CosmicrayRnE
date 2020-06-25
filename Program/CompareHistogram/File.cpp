#include <stdio.h>
#include <stdlib.h>
#include <mutex>
#include <dirent.h>
#include <cstring>
#include "File.h"
#include "constant.h"

long long int process = 0;

std::mutex mtx2;

int GetFileName(const char search_Path[250], char (*file_name)[250])
{
    int name_index = 0;
    DIR *path;
    char *p1,*p2;
    int ret;
    struct dirent *dir;
    //printf(">>success to enter FileName\n");

    path = opendir(search_Path);
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
                    for(int i = 0; p1[i] != '\0'; i++)
                        file_name[name_index][i] = p1[i];

                    //printf("%s\n", file_name[name_index]);
                    name_index ++;
                }
            }

        }
        closedir(path);
    } else
        printf(">>error occur while get data file name\n");

    return name_index;
}

void Gather()
{
    FILE* fp_beforeGather;
    FILE* fp_gather;
    char dir[250];
    int temp[10];

    fp_gather = fopen("percent.txt", "w");

    if (fp_gather != nullptr)
    {
        for (int i = 0; i < Threadnum; i++)
        {
            sprintf(dir, "/media/cosmicray/CosmicrayRnE/compare/percent/_%d_percent.txt", i);
            fp_beforeGather = fopen(dir, "r");

            if (fp_beforeGather != nullptr)
            {
                while (!feof(fp_beforeGather))
                {
                    fscanf(fp_beforeGather, "%d %d %d %d %d %d %d %d %d %d", temp, temp + 1, temp + 2, temp + 3, temp + 4, temp + 5, temp + 6, temp + 7, temp + 8, temp + 9);
                    fprintf(fp_gather, "%d %d %d %d %d %d %d %d %d %d\n", temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9]);
                }
                
                fclose(fp_beforeGather);
            }
        }

        fclose(fp_gather);
    }
}

void MakePercent(int start, int end, int threadnum)
{
    FILE* fp;
    char dir[250];

    sprintf(dir, "/media/cosmicray/CosmicrayRnE/compare/percent/_%d_percent.txt", threadnum);
    fp = fopen(dir, "w");
    if (fp != nullptr)
    {
        for (int p1 = start; p1 < end; p1++)
            for (int p2 = 0; p2 <= p1; p2++)
                for (int p3 = 0; p3 <= p2; p3++)
                {
                    if (p1 + p2 < 20) break;
                    for (int p4 = 0; p4 <= p3; p4++)
                        for (int p5 = 0; p5 <= p4; p5++)
                            for (int p6 = 0; p6 <= p5; p6++)
                            {
                                if (p1 + p2 + p3 + p4 + p5 < 50) break;
                                for (int p7 = 0; p7 <= p6; p7++)
                                    for (int p8 = 0; p8 <= p7; p8++)
                                        for (int p9 = 0; p9 <= p8; p9++)
                                            for (int p10 = 0; p10 <= p9; p10++)
                                            {
                                                if (p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10 == 100)
                                                {
                                                    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

                                                    mtx2.lock();
                                                    process++;
                                                    printf("process: %lld\r", process);
                                                    mtx2.unlock();
                                                }
                                            }
                            }
                                
                }
                    

        fclose(fp);
    }
    else
        printf("fail to make percent table\n");
    
}