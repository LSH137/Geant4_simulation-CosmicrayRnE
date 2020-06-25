#include <iostream>
#include <cstdio>
#include <thread>
#include <unistd.h>
//#include <sys/resource.h>

#include "Constant.h"
#include "FileIO.h"
#include "Process.h"
#include "Gathering.h"
#include "Class.h"
#include "MakeDir.h"
#include "CreateFile.h"
#include "BuildG4Proj.h"
#include "AutoRun.h"

using std::thread;
thread threadlist[Threadnum +10];

int number_of_file = 0;
int low = 0, high = 0;
int works = 0;
int state = 0;
char file_name[Filenum + 10][150];
char folderchk = 0;
long long int number_of_event = 0;
int repeat = 0;
int max_energy = 0;

FILE* fp_EdepData[Threadnum + 10];
FILE* fp_flux[Threadnum + 10];
int number_of_proj = 0;

int main()
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    printf("||1st test\n");
    printf("||make folder\n||%s/flux\n", ProcessedDataDir);
    printf("||%s/edep\n", ProcessedDataDir);
    printf("||%s/divide\n", DivideDataDir);
    printf("||%s/total\n", DivideDataDir);
    printf("||%s\n", ProjectDir);
    printf("||Sample project must be at %s\n", SampleDir);
    printf("||number of file must more then %d\n", Threadnum);
    printf("||Are you ready?\n||press s for simulation\n||press q to quit\n>> ");
    fflush(stdin);

    scanf("%c", &folderchk);
    fflush(stdin);

    switch(folderchk)
    {
        case 'q': return 0;
        /*
          
        case 's':
        {
            printf(">>make Geant4 project\n");
            printf("||enter the maximum energy of particle\n>> ");
            fflush(stdin);
            scanf("%d", &max_energy);

            chdir(ProjectDir);
            system("rm -rf e-");
            system("rm -rf mu-");

            number_of_proj = max_energy * divide;
            printf("||number of project: %d\n", number_of_proj);

            MakeDir(number_of_proj);
            MakeFile(number_of_proj);
            Build(number_of_proj);
            ///////////////////////////////////////////////////////////////////////////////////////////////////
            
            printf(">>step 4. simulate\n");
            //printf("||enter the number of particle for simulation: 10000 X ");
            //fflush(stdin);
            //scanf("%d", &repeat);
            repeat = 100;
            sleep(1);
            ControlAutoRun(number_of_proj, repeat);

            printf("change csv to txt\n");
            for(int i = 1; i < 8; i++)
                ChangeCSVtoTXT(i);

            GatherTXT(8);

            printf(">>step 6. sorting\n");
            SortSimulationData(); //number of data have to less than MaxEdepNumber
        }
        case 'r':
        {
            printf("||maximum energy: ");
            scanf("%d", &max_energy);

            number_of_proj = max_energy * divide;
            repeat = 100;
            sleep(1);
            ControlAutoRun(number_of_proj, repeat);

            printf("change csv to txt\n");
            for(int i = 1; i < 8; i++)
                ChangeCSVtoTXT(i);

            GatherTXT(8);

            printf(">>step 6. sorting\n");
            SortSimulationData(); //number of data have to less than MaxEdepNumber
        }
        */
        case 'g':
        {
            printf("change csv to txt\n");
            for(int i = 1; i < 9; i++)
            {
                printf("%d ", i);
                ChangeCSVtoTXT(i);
                
            }
                

            GatherTXT(9);

            printf(">>step 6. sorting\n");
            //SortSimulationData(); //number of data have to less than MaxEdepNumber
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

