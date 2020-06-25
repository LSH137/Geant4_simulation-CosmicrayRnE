#include <stdio.h>
#include "TH1.h"
#include "Riostream.h"

#define nBin 200

struct ObData
{
    long long int time;
    int month, day, hour, minute;
    int total_edep_ch2 = 0.0;
    int total_edep_ch3 = 0.0;
};

ObData obdata;
const char DivideDataDir[200] = {"/media/cosmicray/CosmicrayRnE/COSMICRAY_DATA/Processed/result/divide"};
const char ResultDataDir[200] = {"/media/cosmicray/CosmicrayRnE/COSMICRAY_DATA/Processed/result"};
//const char MeanDataDir[200] = {"/media/lsh/CosmicrayRnE/COSMICRAY_DATA/Processed/result/mean"};
int fileNumber;
char totalDir[250];
int total_bin_content = 0;

void observedHistogram()
{
    FILE* fp_data;
    FILE* fp_hist;
    char dir[150];
    char name[150];
    char graph_name[150];
    int error;
    double energy;
    double mean;
    int process = 0;
    scanf("%d", &fileNumber);

    printf("file number: %d\n", fileNumber);

    auto canvas_ch2 = new TCanvas("observated_data_ch2","observated_data_ch2",800, 600);
    auto canvas_ch3 = new TCanvas("observated_data_ch3","observated_data_ch3",800, 600);
    auto canvas = new TCanvas("observated_data","observated_data",800, 600);

    TH1D* hist_ch2 = new TH1D("total_edep_ch2", "total_edep_ch2", nBin, 0, 10000);
    TH1D* hist_ch3 = new TH1D("total_edep_ch3", "total_edep_ch3", nBin, 0, 10000);
    TH1D* hist_total = new TH1D("total_edep", "total_edep", nBin, 0, 10000);



    for(int i = 0; i < fileNumber; i++)
    {
        sprintf(totalDir, "%s/_%d_edep.txt", DivideDataDir, i);
        fp_data = fopen(totalDir, "r");

        if(fp_data != nullptr)
        {
            error = fscanf(fp_data, "%lld %d %d %d %d", &obdata.time, &obdata.month, &obdata.day, &obdata.hour, &obdata.minute);
            while(!feof(fp_data))
            {
                error = fscanf(fp_data, "%d %d\n",&obdata.total_edep_ch2, &obdata.total_edep_ch3);
                if(error == EOF) 
                {
                    printf("error occur while scan data file");
                    break;
                }
                else
                {
                    hist_ch2 -> Fill(obdata.total_edep_ch2);
                    hist_ch3 -> Fill(obdata.total_edep_ch3);
                    hist_total -> Fill(obdata.total_edep_ch2);
                    hist_total -> Fill(obdata.total_edep_ch3);
                }
                
            }

            total_bin_content = 0;
            for(int i = 0; i < nBin; i++)
                total_bin_content = total_bin_content + hist_ch2->GetBinContent(i);

            printf("total bin content: %d\n", total_bin_content);    

            for(int i = 0; i < nBin; i++)
                {
                    hist_ch2->SetBinContent(i, (hist_ch2->GetBinContent(i))/total_bin_content);
                    hist_ch3->SetBinContent(i, (hist_ch3->GetBinContent(i))/total_bin_content);
                    hist_total->SetBinContent(i, (hist_total->GetBinContent(i))/(total_bin_content * 2));
                }
            
            sprintf(dir, "%s/observed_data_%lld.txt", ResultDataDir, obdata.time);
            fp_hist = fopen64(dir, "w");

            if(fp_hist != nullptr)
            {
                for(int i = 0; i < nBin; i++)
                    fprintf(fp_hist, "%d %lf %lf %lf\n", i*50, hist_ch2->GetBinContent(i), hist_ch3->GetBinContent(i), hist_total->GetBinContent(i));

                fclose(fp_hist);

                process++;
                printf("%f %% end\t\r", (float)process / (float)fileNumber);
            }

            
            
            canvas_ch2->cd();
            hist_ch2 -> Draw();
            //canvas_ch2->BuildLegend();
            sprintf(graph_name, "/media/cosmicray/CosmicrayRnE/COSMICRAY_DATA/Processed/result/total/ch2/totalObEdep_%d_%llu-%llu_ch2.png", i, obdata.time - 3600, obdata.time);
            canvas_ch2->SaveAs(graph_name);
            hist_ch2->Reset();

            canvas_ch3->cd();
            hist_ch3 -> Draw();
            //canvas_ch3->BuildLegend();
            sprintf(graph_name, "/media/cosmicray/CosmicrayRnE/COSMICRAY_DATA/Processed/result/total/ch3/totalObEdep_%d_%llu-%llu_ch3.png", i, obdata.time - 3600, obdata.time);
            canvas_ch3->SaveAs(graph_name);
            hist_ch3->Reset();

            canvas->cd();
            hist_total -> Draw();
            //canvas_ch2->BuildLegend();
            sprintf(graph_name, "/media/cosmicray/CosmicrayRnE/COSMICRAY_DATA/Processed/result/total/total/totalObEdep_%d_%llu-%llu_total.png", i, obdata.time - 3600, obdata.time);
            canvas->SaveAs(graph_name);
            hist_total->Reset();
            
        }
        else{
            printf("ROOT: error occur while opening obEdep.txt\n");
        }
    }

}
