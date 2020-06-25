#include <iostream>
#include <cstdio>
#include <thread>
#include <unistd.h>
//#include <sys/resource.h>

#include "Constant.h"
#include "FileIO.h"
#include "Process.h"
#include "Gathering.h"

using std::thread;
thread threadlist[Threadnum +10];

int number_of_file = 0;
int low = 0, high = 0;
int works = 0;
int state = 0;
char file_name[Filenum + 10][150];
char folderchk = 0;
long long int number_of_event = 0;

FILE* fp_EdepData[Threadnum + 10] = {nullptr};
FILE* fp_flux[Threadnum + 10] = {nullptr};
int number_of_proj = 0;

int main()
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    printf("||1st test\n");
    printf("||make folder\n||%s/flux\n", ProcessedDataDir);
    printf("||%s/edep\n", ProcessedDataDir);
    printf("||%s/divide\n", DivideDataDir);
    printf("||%s/total\n", DivideDataDir);
    printf("||Data have to be at %s\n", RawDataDir);
    printf("||number of file must more then %d\n", Threadnum);
    printf("||Are you ready?\npress 'a' to start\npress 'q' for quit\n>> ");
    fflush(stdin);

    scanf("%c", &folderchk);
    fflush(stdin);

    switch(folderchk)
    {
        case 'q': return 0;

        case 'a':
        {
            

           break;
        }
        default:
        {
            printf(">>error. you type wrong command\n");
            break;
        }
    }

    return 0;
}

