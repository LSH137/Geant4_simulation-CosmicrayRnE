#include<cstdio>
#include<thread>
#include"constant.h"
#include"WhoInThere.h"
#include"File.h"
#include"dataStructure.h"

std::thread threadList[Threadnum];

FileName observedFile;

char dir[250];

int file_num;
int works;
int start, end;

int chk;

int main(void)
{
	printf("1th test\n");
	
	sprintf(dir, "%s", OBSERVED_DATA_DIR);
	file_num = GetFileName(dir, observedFile.fileName_ch2);

	sprintf(dir, "%s", OBSERVED_DATA_DIR);
	file_num = GetFileName(dir, observedFile.fileName_ch3);

	printf("file number: %d",file_num);

	/*
	printf("make percent\n");
	
	start = 10;
	end = 19;
	for (int i = 0; i < Threadnum; i++)
	{
		threadList[i] = std::thread(MakePercent, start, end, i);
		start = start + 9;
		end = end + 9;
	}

	for (int i = 0; i < Threadnum; i++)
		threadList[i].join();

	Gather();

	printf("make percent end\n");
	*/

	if(file_num > Threadnum)
	{ 
		works = file_num / Threadnum;

		for (int i = 0; i < Threadnum - 1; i++)
		{
			start = i * works;
			end = start + works;

			threadList[i] = std::thread(WhoInThere, start, end, i);
		}
		threadList[Threadnum - 1] = std::thread(WhoInThere, end, file_num, Threadnum-1);

		for (int i = 0; i < Threadnum; i++)
			threadList[i].join();
	}

	scanf("%d", &chk);
}