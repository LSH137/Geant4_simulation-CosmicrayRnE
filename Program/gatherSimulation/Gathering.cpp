//
// Created by lsh on 20. 4. 1..
//

#include "Gathering.h"
#include "FileIO.h"
#include "Constant.h"
#include "Class.h"
#include <cstdio>
#include <algorithm>

void GatherTXT(int n)
{
    FILE* fp_data;
    FILE* fp_result_mu;
    FILE* fp_result_e;
    char dir[250];
    double energy, ch2, ch3;

    fp_result_e = fopen64("/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_e.txt", "w");
    fp_result_mu = fopen64("/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_mu.txt", "w");

    if(fp_result_mu == nullptr || fp_result_e == nullptr) 
    {
        printf("func: GahterTXT()| error occur while making result file\n");
        exit(-1);
    }

    printf("processing e-\n");
    for(int i = 1; i < n; i++)
    {
        sprintf(dir, "/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_e%d.txt", i);
        fp_data = fopen64(dir, "r");
        if(fp_data != nullptr)
        {
            while(!feof(fp_data))
            {
                fscanf(fp_data, "%lf %lf %lf", &energy, &ch2, &ch3);
                fprintf(fp_result_e, "%lf %lf %lf", energy, ch2, ch3);
            }
            fclose(fp_data);
        }
        else
        {
            printf("func: GahterTXT() error %d\n", i);
        }
    }

    printf("processing mu-");
    for(int i = 1; i < n; i++)
    {
        sprintf(dir, "/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_mu%d.txt", i);
        fp_data = fopen64(dir, "r");
        if(fp_data != nullptr)
        {
            while(!feof(fp_data))
            {
                fscanf(fp_data, "%lf %lf %lf", &energy, &ch2, &ch3);
                fprintf(fp_result_mu, "%lf %lf %lf", energy, ch2, ch3);
            }
            fclose(fp_data);
        }
        else
        {
            printf("func: GahterTXT() error %d\n", i);
        }
        
    }

    
}


void ChangeCSVtoTXT(int n)
{
    //printf("test1\n");
    double particle;
    double energy;
    int escape;
    int index;
    int number_of_file;
    double temp[3];
    char dir[250];
    char file_name[Filenum+10][150];
    char info[50] = {0};
    FILE* fp_simulation;
    FILE* fp_mu;
    FILE* fp_e;
    

    //printf("test\n");
    snprintf(dir,250,"%s/simulationData/simulation%d", SimulationDataDir, n);
    printf("%s\n", dir);
    FileName(dir, file_name, CSV);
    number_of_file  = NumberOfcsvFile(dir);

    printf("%d\n", number_of_file);

    snprintf(dir, 250, "%s/simulationData/result/simulation_mu%d.txt", SimulationDataDir, n);
    printf("%s\n", dir);
    fp_mu = fopen64(dir, "w");

    snprintf(dir, 250,"%s/simulationData/result/simulation_e%d.txt", SimulationDataDir, n);
    printf("%s\n", dir);
    fp_e = fopen64(dir, "w");

    index = 0;
    if(fp_mu != nullptr && fp_e != nullptr && number_of_file > 0)
    {
        for(int i = 1; i < number_of_file; i++)
        {
            //printf("||%s\n", file_name[i]);
            snprintf(dir, 250, "%s/simulationData/simulation%d/%s.csv", SimulationDataDir, n, file_name[i]);
            fp_simulation = fopen64(dir, "r");

            if(fp_simulation != nullptr)
            {
                for(int j = 0; j < 20; j++)
                {
                    fscanf(fp_simulation, "%s", info);
                    //printf("%s\n", info);
                }

                while(!feof(fp_simulation) && escape < 15000)
                {
                    if(fscanf(fp_simulation, "%lf,%lf,%lf,%lf", &energy, &particle, &temp[0], &temp[1]) == EOF)
                    {
                        //printf(">>error occur while reading simulation data\n");
                        break;
                    }
                    //printf("energy: %f\n", energy);
                    if(particle == 0)
                        fprintf(fp_mu, "%lf %lf %lf\n", energy, temp[0], temp[1]); //mu- is 0
                    else if(particle == 1)
                        fprintf(fp_e, "%lf %lf %lf\n", energy, temp[0], temp[1]); //e- is 1

                    escape++;
                }

                escape = 0;
                index++;
                //printf(">>step 5. Converting: %f %% end\r", (float)index/(float)number_of_file * 100);

                fclose(fp_simulation);
            }
            else{
                //printf(">>error occur while convert simulation data\n");
                //return 0;
            }
        }

        fclose(fp_mu);
        fclose(fp_e);
    }
    else
    {
        printf(">>error occur while making simulation.txt\n||number of file: %d\n", number_of_file);
        //return 0;
    }
    //return 1;
}