#pragma once
#include"constant.h"
#include<math.h>
#include<stdio.h>

class FileName
{
public:
	FileName() = default;
	~FileName() = default;

	char fileName_ch2[MAX_FILENUM][250] = {0};
	char fileName_ch3[MAX_FILENUM][250] = {0};
};

class Histogram
{
public:
	Histogram()
	{
		index = 0;
		time = 0;
		entry = 0;
		sigma = 0;
		sub_index = 0;
		energy = 0;
	}
	~Histogram()
	{
		delete[] hist;
		delete[] mem;
	}

	long long int* hist = new long long int[Histogram_nclass+10];
	double* mem = new double[Histogram_nclass+10];
	long long int time;
	long long int entry;
	double sigma;
	int energy; //MeV

	void multiply(double ratio)
	{
		for (int i = 0; i < index; i++)
		{
			mem[i] = (double)hist[i] * ratio;
		}
	}

	double GetSigma()
	{
		int trash = 0;
		long long int sum = 0;
		long long int all = 0;
		long double average = 0;
		long double temp = 0;
		long double diff[605] = {0};
		long double spread = 0;

		for (int i = 0; i < 600; i++)
			sum = sum + (((long long int)i * 10) + 5) * hist[i];

		for (int i = 0; i < 600; i++)
			all = hist[i] + all;

		average = (long double)(sum) / (long double)(all);

		for (int i = 0; i < 600; i++)
			diff[i] = hist[i] - average;

		for (int i = 0; i < 600; i++)
			temp = diff[i] * diff[i] + temp;

		spread = temp / (long double)all;

		sigma = sqrt((double)spread);

		return sigma;
		/*
		long double average = 0;
		long double spread = 0;
		long double* difference = new long double[Histogram_nclass];
		long double temp = 0;
		
		if (entry == 0) printf("entry is 0\n");
		else
		{
			for (long long int i = 0; i < Histogram_nclass; i++)
				temp = temp + ((i * 10 + 5) * hist[i]); //0 ~ 10(5) / 10 ~ 20(15) ... 5990 ~ 6000(5995)

			average = temp / (long double)entry;

			for (int i = 0; i < Histogram_nclass; i++)
				difference[i] = hist[i] - average;

			for (int i = 0; i < Histogram_nclass; i++)
				temp = temp + (difference[i] * difference[i]) * hist[i];

			spread = temp / (long double)entry;

			sigma = sqrt(spread);
		}
		return sigma;
		*/
	}

	int Get(double n)
	{
		if (index < MaxFluxIn1Hour)
		{
			mem[index] = n;
			index++;
			return 0;
		}
		else
		{
			printf("(GET_double)buffer over flow detected!!\n");
			return 1;
		}
	}

	long long int GetEntry()
	{
		//printf("get entry\n");
		for (int i = 0; i < Histogram_nclass; i++)
			entry = entry + hist[i];

		return entry;
	}

	void Set(long long int n)
	{
		if (index < Histogram_nclass)
		{
			hist[index] = n;
			index++;
		}
		else
			printf("(SET(long long int))buffer over flow detected!!\n");
	}

	void Set_d(int i, double n)
	{
		if (index < Histogram_nclass)
		{
		    mem[i] = n;
		}
		else
			printf("(SET(double))buffer over flow detected!!\n");
	}

	void Add(long long int n)
	{
		if (sub_index < Histogram_nclass)
		{
			hist[sub_index] = hist[sub_index] + n;
			sub_index++;
		}
		else
			printf("(ADD(long long int))buffer over flow detected!!\n");

		if (sub_index == Histogram_nclass - 1)
			sub_index = 0;
	}

	void Setsub_index()
	{
		sub_index = 0;
	}

	void Draw()
	{
		if (index == 0)
		{
			printf(">>error!. number of data is 0\n");
		}
		else
		{
			for (int i = 0; i < Histogram_nclass; i++)
			{
				for (int j = 0; j < index; j++)
				{
					if (mem[j] < (((double)i + 1.0) * 10.0) && mem[j] > (double)i * 10.0)
						hist[i]++;
				}
			}
		}
	}



	void print(FILE* fp)
	{
		//printf("print\n");
		if (fp != nullptr)
		{
			for (int i = 0; i < Histogram_nclass; i++)
			{
				fprintf(fp, "%d %lld\n", i * 10, hist[i]);
				//printf("%d %lld\n", i * 10, hist[i]);
			}

		}
		else
			printf(">>error! file pointer is nullptr\n");
	}

	void print()
	{
		for (int i = 0; i < Histogram_nclass; i++)
			printf("%d %lld\n", i * 10, hist[i]);
		
	}

	int GetIndex()
	{
		return index;
	}

	void clean()
	{
		index = 0;
		entry = 0;
		sigma = 0;
		time = 0;
		sub_index = 0;
		energy = 0;

		for (int i = 0; i < Histogram_nclass; i++)
		{
			hist[i] = 0;
			mem[i] = 0;
		}
	}

private:
	int index;
	int sub_index;
};