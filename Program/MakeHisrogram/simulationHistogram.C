#include <stdio.h>
#include "Riostream.h"
#include<math.h>

#define nBin 200
#define MaxEdepNumber 5000000000
#define MaxEnergy 500
#define MaxParticleNum 10000


struct G4Data
{
    int particle = 0;
    double energy = 0;
    double total_edep_ch2 = 0.0;
    double total_edep_ch3 = 0.0;
};

G4Data g4data;
const char SimulationDataDir[200] ={"/media/cosmicray/CosmicrayRnE/simulationData/result"};
double total_bin_content = 0;
double dhist_ch2[nBin];
double dhist_ch3[nBin];
double dhist_total[nBin];

void simulationHistogram()
{
    FILE* fp_mu;
    FILE* fp_e;
    FILE* fp_hist;
    long long int escape;
    int count = 0;
    char dir[150];
    char name[150];
    char graph_name[150];
    int chk = 0;

    sprintf(dir, "%s/simulated_resize_mu.txt", SimulationDataDir);
    fp_mu = fopen64(dir, "r");

    TH1D* hist_mu_ch2 = new TH1D("mu-_ch2", "mu-_ch2", nBin, 0, 10000);
    TH1D* hist_mu_ch3 = new TH1D("mu-_ch3", "mu-_ch3", nBin, 0, 10000);
    TH1D* hist_mu_total = new TH1D("mu-_total", "mu-_total", nBin, 0, 10000);

    
    if(fp_mu != nullptr)
    {
        for(double e = 0.1; e < MaxEnergy; e = e + 0.1)
        {
            chk = 0;
            escape = 0;
            fseeko64(fp_mu, 0, SEEK_SET);
            while(!feof(fp_mu) && escape < MaxEdepNumber && chk == 0)
            {
                fscanf(fp_mu, "%lf %lf %lf", &g4data.energy, &g4data.total_edep_ch2, &g4data.total_edep_ch3);
                printf("%f %% end finding: %lf energy: %lf\r", (float)count/MaxParticleNum, e, g4data.energy);
                
                if(fabs(g4data.energy - e) < 0.01)
                {
                    hist_mu_ch2 -> Fill(g4data.total_edep_ch2);
                    hist_mu_ch3 -> Fill(g4data.total_edep_ch3);
                    hist_mu_total -> Fill(g4data.total_edep_ch2);
                    hist_mu_total -> Fill(g4data.total_edep_ch3);

                    if(count > MaxParticleNum)
                    {
                        total_bin_content = 0;
                        for(int i = 0; i < nBin; i++)
                            total_bin_content = total_bin_content + hist_mu_ch2->GetBinContent(i);
                    
                        for(int i = 0; i < nBin; i++)
                        {
                            hist_mu_ch2->SetBinContent(i, (hist_mu_ch2->GetBinContent(i))/total_bin_content);
                            hist_mu_ch3->SetBinContent(i, (hist_mu_ch3->GetBinContent(i))/total_bin_content);
                            hist_mu_total->SetBinContent(i, (hist_mu_total->GetBinContent(i))/(total_bin_content * 2));
                        }
                        sprintf(dir, "%s/s_mu_%lf.txt", SimulationDataDir, g4data.energy);
                        fp_hist = fopen(dir, "w");

                        if(fp_hist != nullptr)
                        {
                            for(int i = 0; i < nBin; i++)
                                fprintf(fp_hist, "%d %lf %lf %lf\n", i*50, hist_mu_ch2->GetBinContent(i), hist_mu_ch3->GetBinContent(i), hist_mu_total->GetBinContent(i));


                            fclose(fp_hist);
                        }
                        else
                            printf("error while making hisrogram\n");

                        chk = 1;
                    }
                    count++;
                }
                escape++;
            }
        }
       
    }
    else
    {
        printf("error\n");
    }
    

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sprintf(dir, "%s/simulated_resize_e.txt", SimulationDataDir);
    fp_e = fopen64(dir, "r");

    TH1D* hist_e_ch2 = new TH1D("e-_ch2", "e-_ch2", nBin, 0, 10000);
    TH1D* hist_e_ch3 = new TH1D("e-_ch3", "e-_ch3", nBin, 0, 10000);
    TH1D* hist_e_total = new TH1D("e-_total", "e-_total", nBin, 0, 10000);

    escape = 0;
    count = 0;
    if(fp_e != nullptr)
    {
        for(double e = 0.1; e < MaxEnergy; e = e + 0.1)
        {
            chk = 0;
            escape = 0;
            fseeko64(fp_e, 0, SEEK_SET);
            while(!feof(fp_e) && escape < (int)MaxEdepNumber && chk == 0)
            {
                fscanf(fp_e, "%lf %lf %lf", &g4data.energy, &g4data.total_edep_ch2, &g4data.total_edep_ch3);
                printf("%f %% end finding: %lf energy: %lf\r", (float)count/MaxParticleNum, e, g4data.energy);
                if(fabs(g4data.energy - e) < 0.01)
                {
                    hist_e_ch2 -> Fill(g4data.total_edep_ch2);
                    hist_e_ch3 -> Fill(g4data.total_edep_ch3);
                    hist_e_total -> Fill(g4data.total_edep_ch2);
                    hist_e_total -> Fill(g4data.total_edep_ch3);

                    if(count > MaxParticleNum)
                    {
                        total_bin_content = 0;
                        for(int i = 0; i < nBin; i++)
                            total_bin_content = total_bin_content + hist_e_ch2->GetBinContent(i);
                    
                        for(int i = 0; i < nBin; i++)
                        {
                            hist_e_ch2->SetBinContent(i, (hist_e_ch2->GetBinContent(i))/total_bin_content);
                            hist_e_ch3->SetBinContent(i, (hist_e_ch3->GetBinContent(i))/total_bin_content);
                            hist_e_total->SetBinContent(i, (hist_e_total->GetBinContent(i))/(total_bin_content * 2));
                        }
                        sprintf(dir, "%s/s_mu_%lf.txt", SimulationDataDir, g4data.energy);
                        fp_hist = fopen(dir, "w");

                        if(fp_hist != nullptr)
                        {
                            for(int i = 0; i < nBin; i++)
                                fprintf(fp_hist, "%d %lf %lf %lf\n", i*50, hist_e_ch2->GetBinContent(i), hist_e_ch3->GetBinContent(i), hist_e_total->GetBinContent(i));

                            fclose(fp_hist);
                        }
                        else
                            printf("error while making hisrogram\n");

                        
                        chk = 1;
                    }
                    count++;

                }
    
                escape++;
            }
            
        }
    }
    else
    {
        printf("error\n");
    }

}
