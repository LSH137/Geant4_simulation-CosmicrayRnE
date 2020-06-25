#include<stdio.h>
#include<thread>

#define MaxParticleNum 10000

std::thread threadlist[5];

struct G4Data
{
    int particle = 0;
    double energy = 0;
    double total_edep_ch2 = 0.0;
    double total_edep_ch3 = 0.0;
};
G4Data g4data;

void e()
{
    FILE* fp_data;
    FILE* fp_resize;
    int* energy = new int[5000000];
    int count = 0;

    printf("e-\n");
    fp_data = fopen64("/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_e.txt", "r");
    fp_resize = fopen64("/media/cosmicray/CosmicrayRnE/simulationData/result/simulated_resize_e.txt", "w");

    if(fp_resize == nullptr || fp_data == nullptr) exit(-1);

    while(!feof(fp_data))
    {
        fscanf(fp_data, "%lf %lf %lf", &g4data.energy, &g4data.total_edep_ch2, &g4data.total_edep_ch3);

        if(energy[(int)((g4data.energy) * 10)] < MaxParticleNum)
        {
            fprintf(fp_resize, "%lf %lf %lf\n", g4data.energy, g4data.total_edep_ch2, g4data.total_edep_ch3);
            energy[(int)((g4data.energy) * 10)]++;
        }
      
    }
    fclose(fp_data);
    fclose(fp_resize);

    delete[] energy;
}

void mu()
{
    FILE* fp_data;
    FILE* fp_resize;
    int* energy = new int[5000000];
    int count = 0;

    printf("mu-\n");
    fp_data = fopen64("/media/cosmicray/CosmicrayRnE/simulationData/result/simulation_mu.txt", "r");
    fp_resize = fopen64("/media/cosmicray/CosmicrayRnE/simulationData/result/simulated_resize_mu.txt", "w");

    if(fp_resize == nullptr || fp_data == nullptr) exit(-1);

    while(!feof(fp_data))
    {
        fscanf(fp_data, "%lf %lf %lf", &g4data.energy, &g4data.total_edep_ch2, &g4data.total_edep_ch3);

        if(energy[(int)((g4data.energy) * 10)] < MaxParticleNum)
        {
            fprintf(fp_resize, "%lf %lf %lf\n", g4data.energy, g4data.total_edep_ch2, g4data.total_edep_ch3);
            energy[(int)((g4data.energy) * 10)]++;
        }
      
    }
    fclose(fp_data);
    fclose(fp_resize);

    delete[] energy;
}

int main(void)
{
    threadlist[0] = std::thread(e);
    threadlist[1] = std::thread(mu);

    threadlist[0].join();
    threadlist[1].join();
}