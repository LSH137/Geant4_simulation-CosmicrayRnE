//
// Created by lsh on 20. 4. 1..
//

#include "Gathering.h"
#include "FileIO.h"
#include "Constant.h"
#include "Class.h"
#include <cstdio>
#include <algorithm>

FILE* fp_re_flux[Threadnum];

extern long long int number_of_event;

int Gathering()
{
    Flux flux;
    long long int progress = 0;
    char gather[250] = {0};

    //printf("||Gathering called\n");

    sprintf(gather, "%s/flux.txt", ProcessedDataDir);
    if(reOpenFluxFile())
    {
        FILE* fp_gather_flux = fopen64(gather, "w");
        if(fp_gather_flux != nullptr)
        {
            for(auto & fp : fp_re_flux)
            {
                while(!feof(fp))
                {
                    fscanf(fp, "%d,%d,%d,%d,%d,%d,%d", &flux.year, &flux.month, &flux.day, &flux.hour, &flux.minute, &flux.sec, &flux.flux);
                    flux.ConvertTime();

                    fprintf(fp_gather_flux, "%lld %d %d %d %d %d %d %d\n", flux.time, flux.year, flux.month, flux.day, flux.hour, flux.minute, flux.sec, flux.flux);
                    progress++;
                    printf(">>step 2. gathering: %f %% end\r", (float)progress/(float)number_of_event * 100);
                }
                    fclose(fp);
            }
            fclose(fp_gather_flux);

        } else return 0;
    } else return 0;

    printf(">>success to gather flux file\n");

    return 1;
}

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
        printf("func: GahterTXT()| error occur while making result file");
        exit(-1);
    }
    for(int i = 0; i < n; i++)
    {
        sprintf(dir, "/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_mu%d", i);
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
            printf("func: GahterTXT() error");
        }
        
    }

     for(int i = 0; i < n; i++)
    {
        sprintf(dir, "/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_e%d", i);
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
            printf("func: GahterTXT() error");
        }
    }
}

char info[50] = {0};
FILE* fp_simulation;
FILE* fp_mu;
FILE* fp_e;

void ChangeCSVtoTXT(int n)
{
    printf("test1\n");
    double particle;
    double energy;
    int escape;
    int index;
    int number_of_file;
    double temp[3];
    char dir[250];
    char file_name[Filenum+10][150];
    

    printf("test\n");
    snprintf(dir,250,"%s/simulationData/simulation%d", SimulationDataDir, n);
    FileName(dir, file_name, CSV);
    number_of_file  = NumberOfcsvFile(dir);

    printf("%d\n", number_of_file);

    snprintf(dir, 250, "%s/simulationData/result/simulation_mu%d.txt", SimulationDataDir, n);
    fp_mu = fopen64(dir, "w");

    snprintf(dir, 250,"%s/simulationData/result/simulation_e%d.txt", SimulationDataDir, n);
    fp_e = fopen64(dir, "w");

    index = 0;
    if(fp_mu != nullptr && fp_e != nullptr && number_of_file > 0)
    {
        for(int i = 0; i < number_of_file; i++)
        {
            //printf("||%s\n", file_name[i]);
            snprintf(dir, 250, "%s/%s.csv", SimulationDataDir, file_name[i]);
            fp_simulation = fopen(dir, "r");

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
                printf(">>error occur while convert simulation data\n");
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



/*
void ConvertCloudData(int end_year, int end_month, int end_day, int end_hour)
{
    FILE* fp_cloud;
    char cloud_file_name[200] = {0};
    char trash[15] = {0};
    Cloud cloud;
    int temp[5] = {0};
    int index = 0;
    int err = 0;

    printf("||ConvertCloudData called\n");

    sprintf(cloud_file_name, "%s/cloud_data1.csv", CloudDataDir);
    fp_cloud = fopen64(cloud_file_name, "r");

    if(fp_cloud != nullptr)
    {
        printf(">>success to open cloud_data1.csv\n");
        while(!feof(fp_cloud))
        {
            err = fscanf(fp_cloud, "%d.%d.%d-%dh,", &temp[0], &temp[1], &temp[2], &temp[3]);
            //sleep(1);
            if(err == 0 || err == feof(fp_cloud))
                printf(">>error occur while reading cloud data\n");

            cloud.year.push_back(temp[0]);
            cloud.month.push_back(temp[1]);
            cloud.day.push_back(temp[2]);
            cloud.hour.push_back(temp[3]);
            index++;

            if(temp[0] == end_year && temp[1] == end_month && temp[2] == end_day && temp[3] == end_hour)
                break;
        }
        //fscanf(fp_cloud, "%s,", trash);
        for(int i = 0; i < index; i++)
        {
            fscanf(fp_cloud, "%d,", &temp[4]);
            cloud.total_cloud_cover.push_back(temp[4]);
        }

        //fscanf(fp_cloud, "%s,", trash);
        for(int i = 0; i < index; i++)
        {
            fscanf(fp_cloud, "%d,", &temp[4]);
            cloud.fog.push_back(temp[4]);
        }

        //fscanf(fp_cloud, "%s,", trash);
        for(int i = 0; i < index; i++)
        {
            fscanf(fp_cloud, "%d,", &temp[4]);
            cloud.low_cloud.push_back(temp[4]);
        }

        //fscanf(fp_cloud, "%s,", trash);
        for(int i = 0; i < index; i++)
        {
            fscanf(fp_cloud, "%d,", &temp[4]);
            cloud.middle_cloud.push_back(temp[4]);
        }

        //fscanf(fp_cloud, "%s,", trash);
        for(int i = 0; i < index; i++)
        {
            fscanf(fp_cloud, "%d,", &temp[4]);
            cloud.high_cloud.push_back(temp[4]);
        }

        cloud.Sort();
        cloud.number_of_data = index;

        cloud.fPrint();
    }
    else printf(">>error occur while opening cloud data\n");

   // return cloud;
}
*/



