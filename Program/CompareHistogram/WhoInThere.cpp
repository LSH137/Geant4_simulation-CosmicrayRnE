#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<mutex>
#include<math.h>
#include<random>
#include"constant.h"
#include"dataStructure.h"

struct HistogramPack
{
	Histogram ch2;
	Histogram ch3;
	int energy[10];
};

extern FileName observedFile;
int energy_memo[1000][15];
int test = 0;

std::mutex mtx;

int ReadSimulationData_e(int energy, int threadnum, HistogramPack* hist)
{
	FILE* fp_ch2;
	FILE* fp_ch3;
	//HistogramPack hist;
	char dir[250];
	long long int temp1, temp2;

	//printf("thread %d energy: %d\n", threadnum, energy);
	sprintf(dir, "%s/mu/ch2/_%dMeV_histogram_mu_ch2.txt", SIMULATED_HISTOGRAM_DIR, energy);
	fp_ch2 = fopen(dir, "r");

	sprintf(dir, "%s/mu/ch3/_%dMeV_histogram_mu_ch3.txt", SIMULATED_HISTOGRAM_DIR, energy);
	fp_ch3 = fopen(dir, "r");

	if (fp_ch2 != nullptr && fp_ch3 != nullptr)
	{
		hist->ch2.energy = energy;
		hist->ch3.energy = energy;

		while (feof(fp_ch2) == 0)
		{
			for (int i = 0; i < Histogram_nclass; i++)
			{
				fscanf(fp_ch2, "%lld %lld", &temp1, &temp2);
				if (feof(fp_ch2)) break;
				//printf("%d: ch2 %lld %lld\n", threadnum, temp1, temp2);
				hist->ch2.Add(temp2);
			}
			hist->ch2.Setsub_index();
		}
		fclose(fp_ch2);

		while (feof(fp_ch3) == 0)
		{
			for (int i = 0; i < Histogram_nclass; i++)
			{
				fscanf(fp_ch3, "%lld %lld", &temp1, &temp2);
				if (feof(fp_ch3)) break;
				//printf("%d: ch3 %lld %lld\n", threadnum, temp1, temp2);
				hist->ch3.Add(temp2);
			}
			hist->ch3.Setsub_index();
		}
		fclose(fp_ch3);
		//printf("%d read end\n", threadnum);

		return 1;
	}
	else
	{
		return 0;
	}
	
	
	//return hist;
}

int ReadSimulationData_mu(int energy, int threadnum, HistogramPack* hist)
{
	FILE* fp_ch2;
	FILE* fp_ch3;
	//HistogramPack hist;
	char dir[250];
	long long int temp1, temp2;

	//printf("thread %d energy: %d\n", threadnum, energy);
	sprintf(dir, "%s/mu/ch2/_%dMeV_histogram_mu_ch2.txt", SIMULATED_HISTOGRAM_DIR, energy);
	fp_ch2 = fopen(dir, "r");

	sprintf(dir, "%s/mu/ch3/_%dMeV_histogram_mu_ch3.txt", SIMULATED_HISTOGRAM_DIR, energy);
	fp_ch3 = fopen(dir, "r");

	if (fp_ch2 != nullptr && fp_ch3 != nullptr)
	{
		hist->ch2.energy = energy;
		hist->ch3.energy = energy;

		while (feof(fp_ch2) == 0)
		{
			for (int i = 0; i < Histogram_nclass; i++)
			{
				fscanf(fp_ch2, "%lld %lld", &temp1, &temp2);
				if (feof(fp_ch2)) break;
				//printf("%d: ch2 %lld %lld\n", threadnum, temp1, temp2);
				hist->ch2.Add(temp2);
			}
			hist->ch2.Setsub_index();
		}
		fclose(fp_ch2);
		for(int i = 0; i < Histogram_nclass; i++)
		{
			hist->ch2.Set_d(i, hist->ch2.mem[i] / (double)(hist->ch2.GetEntry()));
		}

		while (feof(fp_ch3) == 0)
		{
			for (int i = 0; i < Histogram_nclass; i++)
			{
				fscanf(fp_ch3, "%lld %lld", &temp1, &temp2);
				if (feof(fp_ch3)) break;
				//printf("%d: ch3 %lld %lld\n", threadnum, temp1, temp2);
				hist->ch3.Add(temp2);
			}
			hist->ch3.Setsub_index();
		}
		fclose(fp_ch3);
		for(int i = 0; i < Histogram_nclass; i++)
		{
			hist->ch3.Set_d(i, hist->ch3.mem[i] / (double)(hist->ch3.GetEntry()));
		}

		//printf("%d read end\n", threadnum);

		return 1;
	}
	else
	{
		return 0;
	}
	
	
	//return hist;
}

int Merge(int propability[10], int threadnum, HistogramPack & result) //percent
{
	int energy[10];
	int check = 0;
	int check2 = 0;
	int same_energy = 0;
	HistogramPack* simulation = new HistogramPack[15];
	std::random_device rn;
	std::mt19937_64 rnd( rn() );
	std::uniform_int_distribution<int> range(100, 500);

	//HistogramPack result;

	//propability check
	for (int i = 0; i < 10; i++)
		check = check + propability[i];

	if (check != 100)
	{
		printf("wrong propability!\n");
		printf("%d %d %d %d %d %d %d %d %d %d\n", propability[0], propability[1], propability[2], propability[3], propability[4], propability[5], propability[6], propability[7], propability[8], propability[9]);
	}
	else
	{
		//srand((unsigned int)(clock()%INT_MAX));
SETENERGY:
		// pick 10 energy to merge
		//if (same_energy != 0) Sleep(5);

		if(same_energy > 500) return 0;

		for (int i = 0; i < 10; i++)
			energy[i] = range(rnd) * 100;
			
		if (test > 1)
		{
			check2 = 0;
			for (int j = 0; j < test; j++)
				for (int i = 0; i < 10; i++)
				{					
					if (energy_memo[j][i] == energy[i])
						check2++;
				}

			if (check2 < 10)
			{
				for (int i = 0; i < 5; i++)
				{
					if(ReadSimulationData_mu(energy[i], threadnum, &simulation[i]))
					{
						mtx.lock();
						energy_memo[test][i] = energy[i];
						mtx.unlock();
					}
					//printf("thread %d debug point\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
					
				}
				for (int i = 5; i < 10; i++)
				{
					ReadSimulationData_e(energy[i], threadnum, &simulation[i]);
					//printf("thread %d debug point\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
					mtx.lock();
						energy_memo[test][i] = energy[i];
						mtx.unlock();
				}
			}
			else
			{
				printf("same energy\n");
				same_energy++;
				goto SETENERGY;
			}
				
		}
		else
		{
			for (int i = 0; i < 5; i++)
				{
					if(ReadSimulationData_mu(energy[i], threadnum, &simulation[i]))
					{
						energy_memo[test][i] = energy[i];
					}
					else
					{
						goto SETENERGY;
						same_energy++;
					}
					
					//printf("thread %d debug point\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
					
				}
				for (int i = 5; i < 10; i++)
				{
					if(ReadSimulationData_e(energy[i], threadnum, &simulation[i]))
					{
						energy_memo[test][i] = energy[i];
					}
					else
					{
						goto SETENERGY;
						same_energy++;
					}
					
					//printf("thread %d debug point\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
					
				}
		}
			

		//merge
		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < Histogram_nclass; j++)
			{
				result.ch2.hist[j] = result.ch2.hist[j] + simulation[i].ch2.hist[j] * propability[i];
				result.ch3.hist[j] = result.ch3.hist[j] + simulation[i].ch3.hist[j] * propability[i];
			}
			result.energy[i] = simulation[i].ch2.energy;
		}

		printf("%d test:%d\n", threadnum, test);
		test++;
	}
	delete[] simulation;

	return 1;
}

void WhoInThere(int start, int end, int threadnum)
{
	long long int temp1 = 0, temp2 = 0, temp3 = 0;
	int percent[10];
	int correct = 0, wrong = 0;
	FILE* fp_data_ch2;
	FILE* fp_data_ch3;
	FILE* fp_percent;
	FILE* fp_result;
	char dir[250];
	Histogram observed_hist_ch2;
	Histogram observed_hist_ch3;
	HistogramPack compare;
	int index = 0;
	double ratio = 0.0;
	double res;
	//printf("WhoInThere?\n");

	mtx.lock();
	fp_percent = fopen("/media/cosmicray/CosmicrayRnE/compare/percent/percent.txt", "r");
	mtx.unlock();

	sprintf(dir, "/media/cosmicray/CosmicrayRnE/compare/result_%d.txt", threadnum);
	fp_result = fopen(dir, "w");

	if (fp_result != nullptr && fp_percent != nullptr)
	{
		for (int i = start; i < end; i++)
		{
			printf("%d open observed data file\n", threadnum);
			sprintf(dir, "%s/%s.txt", OBSERVED_DATA_DIR, observedFile.fileName_ch2[i]);
			fp_data_ch2 = fopen(dir, "r");
			printf("%s\n", dir);
			
			
			if (fp_data_ch2 != nullptr)
			{
				//fscanf(fp_data_ch2, "%lld", &observed_hist_ch2.time);
				//fscanf(fp_data_ch3, "%lld", &observed_hist_ch3.time);
				observed_hist_ch2.clean();
				observed_hist_ch3.clean();
				
				for (int i = 0; i < Histogram_nclass; i++)
				{
					fscanf(fp_data_ch2, "%lld %lld %lld", &temp1, &temp2, &temp3);
					observed_hist_ch2.Set(temp2);
					observed_hist_ch3.Set(temp3);		
				}
				
				observed_hist_ch2.GetEntry();
				observed_hist_ch3.GetEntry();
				
				while (!feof(fp_percent))
				{
					//mtx.lock();
					fscanf(fp_percent, "%d %d %d %d %d %d %d %d %d %d", &percent[0], &percent[1], &percent[2], &percent[3], &percent[4], &percent[5], &percent[6], &percent[7], &percent[8], &percent[9]);
					//mtx.unlock();
					test = 0;
					while (test < 500)
					{
						compare.ch2.clean();
						compare.ch3.clean();

						//mtx.lock();
						Merge(percent, threadnum, compare);
						//mtx.unlock();

						compare.ch2.GetEntry();
						compare.ch3.GetEntry();
						//printf("thread %d debug point1\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
						//ratio = (double)compare.ch2.entry / (double)observed_hist_ch2.entry;

						//compare.ch2.multiply(ratio);
						//compare.ch3.multiply(ratio);
						//printf("thread %d debug point2\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
						printf("sigma_ch2: %lf\tsigma_ch3: %lf\n", observed_hist_ch2.GetSigma(), observed_hist_ch3.GetSigma());
							
						//if verticle is same in range sigma we say "Oh it's rignt"

						for (int i = 0; i < Histogram_nclass; i++)
						{
							if (fabs((double)observed_hist_ch2.hist[i] - compare.ch2.mem[i]) < SIGMA * (observed_hist_ch2.sigma) && fabs((double)observed_hist_ch3.hist[i] - compare.ch3.mem[i]) < SIGMA * (observed_hist_ch3.sigma))
							{
								correct++;
							}
							else wrong++;
						}
						//printf("thread %d debug point3\n", threadnum); /////////////////////////////////////////////////DEBUG POINT
						res = ((double)correct / (double)((long long int)correct + wrong)) * 100;
						printf("%lf %% right\n", res);

						if (res > 95.0)
						{
							sprintf(dir, "/media/cosmicray/CosmicrayRnE/compare/%s", observedFile.fileName_ch2[i]);
							fp_result = fopen(dir, "a");
							if (fp_result != nullptr)
							{
								fprintf(fp_result, "ch2\n");
								compare.ch2.print(fp_result);
								fprintf(fp_result, "ch3\n");
								compare.ch3.print(fp_result);

								fclose(fp_result);
							}
							else printf("error occur while make result file\n");

						}

						//test++;
					}
				
				}

				fclose(fp_data_ch2);
			}
			else
				printf("error occur while opening observed data file\n");

			observed_hist_ch2.clean();
			observed_hist_ch3.clean();
		}

		fclose(fp_result);
		fclose(fp_percent);
	}
}

//504