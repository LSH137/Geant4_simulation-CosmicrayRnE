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

int GatherFlux()
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
                    fscanf(fp, "%llu %d %d %d %d %d %d %d",&flux.time, &flux.year, &flux.month, &flux.day, &flux.hour, &flux.minute, &flux.sec, &flux.flux);
                
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


FILE* fp_re_EdepData[Threadnum + 10];

bool cmp2(const ObData& p1, const ObData& p2)
{
    return p1.time < p2.time;
}

void GatherEdep()
{
    auto* data = new ObData[number_of_event + 10];
    FILE* fp_data;
    int index = 0;
    char data_name[250];

    printf("||start to gather edep\n");
    printf("||number of event: %lld\n", number_of_event);

    sprintf(data_name, "%s/ObEdep.txt", ProcessedDataDir);

    fp_data = fopen64(data_name, "w");

    if (fp_data != nullptr)
    {
        if (ReadEdepFile())
        {
            for (int i = 0; i < Threadnum; i++)
            {
                while (true)
                {
                    if(feof(fp_re_EdepData[i])) break;

                    fscanf(fp_re_EdepData[i], "%lld %d %d %d %d %d %d %d %d", &data[index].time, &data[index].year, &data[index].month, &data[index].day, &data[index].hour, &data[index].minute, &data[index].sec, &data[index].total_edep_ch2, &data[index].total_edep_ch3);
                    index++;
                    printf("%f %% end\r", (float )index / (float)number_of_event * 100);
                }
            }

            std::sort(data, data + index - 1, cmp2);
        }

        for (int i = 0; i < index; i++)
            fprintf(fp_data, "%lld %d %d %d %d %d %d %d %d\n", data[i].time, data[i].year, data[i].month, data[i].day, data[i].hour, data[i].minute, data[i].sec, data[i].total_edep_ch2, data[i].total_edep_ch3);

        fclose(fp_data);

        for (int i = 0; i < Threadnum; i++)
        {
            if (fp_re_EdepData[i] != nullptr)
                fclose(fp_re_EdepData[i]);
        }

    }
    else{
        printf(">>error occur while making ObEdep.txt\n");
    }

    delete [] data;
}