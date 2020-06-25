#include <iostream>
#include <cstdio>
#include <thread>
//#include <unistd.h>
//#include <sys/resource.h>

#include "Constant.h"
#include "FileIO.h"
#include "Gathering.h"
#include "Class.h"

std::thread threadlist[Threadnum +10];
int threads_sprit;

char file_name[Filenum + 10][150];


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

            
    printf("change csv to txt\n");


    //for(int i = 1; i <= 11; i++)
       // {
           // ChangeCSVtoTXT(i);
      //  }
    
                
        GatherTXT(11);

        //printf(">>step 6. sorting\n");
            //SortSimulationData(); //number of data have to less than MaxEdepNumber

    return 0;
}

