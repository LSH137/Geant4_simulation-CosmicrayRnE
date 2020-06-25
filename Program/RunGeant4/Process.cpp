//
// Created by lsh on 20. 3. 4..
// save event during 0ns to 950ns
//

#include "Process.h"
#include <cstdio>
#include <mutex>
#include <algorithm>
#include "Constant.h"
#include "Class.h"
#include "FileIO.h"

extern FILE* fp_EdepData[Threadnum + 10];

extern char file_name[Filenum + 10][150];
extern FILE* fp_flux[Threadnum+10];

extern int state;

extern int number_of_file;

extern long long int number_of_event;

std::mutex mtx;
/*
inline void CopyTime(const Time& now, Time& old)
{
    old.year = now.year;
    old.month = now.month;
    old.day = now.day;
    old.hour = now.hour;
    old.minute = now.minute;
    old.sec = now.sec;
}
*/
inline int CompareTime(const Time& now, const Time& old)
{
    if(now.year == old.year)
        if(now.month == old.month)
            if(now.day == old.day)
                if(now.hour == old.hour)
                    if(now.minute == old.minute)
                        if(now.sec == old.sec)
                            return 1;

    return 0;
}




bool cmp(const G4Data &p1, const G4Data &p2)
{
    return p1.energy < p2.energy;
}


void SortSimulationData()
{
    FILE* fp_mu;
    FILE* fp_e;
    int escape;
    char dir[150];
    G4Data* g4data = new G4Data[MaxEdepNumber];

    printf("||sort mu- data \n");
    sprintf(dir, "%s/simulation_mu.txt", SimulationDataDir);
    fp_mu = fopen64(dir, "r");

    escape = 0;
    if(fp_mu != nullptr)
    {
        while(!feof(fp_mu) && escape < MaxEdepNumber)
        {
            fscanf(fp_mu, "%lf %lf %lf", &g4data[escape].energy, &g4data[escape].total_edep_ch2, &g4data[escape].total_edep_ch3);
            escape++;
        }
        std::sort(g4data, g4data + escape - 1, cmp);

        fclose(fp_mu);
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //sprintf(dir, "%s/simulation_mu.txt", SimulationDataDir);
        fp_mu = fopen64(dir, "w");

        if(fp_mu != nullptr)
        {
            for(int i = 0; i < escape; i++)
                fprintf(fp_mu, "%f %lf %lf\n", g4data[i].energy, g4data[i].total_edep_ch2, g4data[i].total_edep_ch3);

            fclose(fp_mu);
        }
        else{
            printf(">>error occur while making simulation_mu.txt - sorted\n");
        }
    }
    else{
        printf(">>error occur while opening simulation_mu.txt\n");
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("||sort e- data\n");
    sprintf(dir, "%s/simulation_e.txt", SimulationDataDir);
    fp_e = fopen64(dir, "r");

    escape = 0;
    if(fp_e != nullptr)
    {
        while(!feof(fp_e) && escape < MaxEdepNumber)
        {
            fscanf(fp_e, "%d %lf %lf %lf", &g4data[escape].particle, &g4data[escape].energy, &g4data[escape].total_edep_ch2, &g4data[escape].total_edep_ch3);
            escape++;
        }
        std::sort(g4data, g4data + escape - 1, cmp);

        fclose(fp_e);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //sprintf(dir, "%s/simulation_e.txt", SimulationDataDir);
        fp_e = fopen64(dir, "w");

        if(fp_e != nullptr)
        {
            for(int i = 0; i < escape; i++)
                fprintf(fp_e, "%lf %lf %lf\n", g4data[i].energy, g4data[i].total_edep_ch2, g4data[i].total_edep_ch3);

            fclose(fp_e);
        }
        else{
            printf(">>error occur while making simulation_e.txt - sorted\n");
        }
    }
    else{
        printf(">>error occur while opening simulation_e.txt\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////