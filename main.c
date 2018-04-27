#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
	stat("text1",&stat1);

	return;
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
	stat("text2",&stat2);

	return;
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	time1=(tm*)malloc(sizeof(tm));
	*time1=*localtime(&stat1.st_mtime);
	printf("text1 : %s", asctime(time1));	

	return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	time2=(tm*)malloc(sizeof(tm));
	*time2=*localtime(&stat2.st_mtime);
	printf("text2 : %s", asctime(time2));

	return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	printf("size compare\n");

	if(stat1.st_size > stat2.st_size)
		printf("text1 is bigger\n");
	if(stat1.st_size < stat2.st_size)
		printf("text2 is bigger\n");
	if(stat1.st_size == stat2.st_size)
		printf("text1 is equal text2\n");
	
	return;
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	int block1,block2;
	printf("block compare\n");
	block1=(int)stat1.st_blocks;
	block2=(int)stat2.st_blocks;
	if(block1>block2)
		printf("text1 is bigger\n");
	else if(block1==block2)
		printf("text1 is equal text2\n");
	else
		printf("text2 is bigger\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	int month1,date1;
	int month2,date2;
	month1=time1->tm_mon+1;
	month2=time2->tm_mon+1;
	date1=time1->tm_mday;
	date2=time2->tm_mday;
	printf("month/date compare\n");
	if(month1==month2){
		if(date1>date2)
			printf("text1 is early\n");
		else if(date1==date2)
			printf("same time\n");
		else
			printf("text2 is early\n");
	}
	else if(month1>month2)
		printf("text1 is early\n");
	else
		printf("text2 is early\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	int hour1,min1;
	int hour2,min2;
	hour1=time1->tm_hour;
	min1=time1->tm_min;
	hour2=time2->tm_hour;
	min2=time2->tm_min;
	printf("time compare\n");
	if(hour1==hour2){
		if(min1==min2)
			printf("same time\n");
		else if(min1>min2)
			printf("text1 is early\n");
		else
			printf("text2 is early\n");
			
	}
	else if(hour1>hour2)
		printf("text1 is early\n");
	else
		printf("text2 is early\n");
}
