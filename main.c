#include <stdio.h>
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
	time1=localtime(&stat1.st_mtime);
	printf("text1 : %s", asctime(time1));	

	return;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	time2=localtime(&stat2.st_mtime);
	printf("text2 : %s", asctime(time2));

	return;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	int a,b;
	a=(int)stat1.st_blocks;
	b=(int)stat2.st_blocks;
	printf("block compare\n");
	if(a>b)
		printf("text1 is bigger\n");
	else if(a==b)
		printf("The blocks of a and b files are the same\n");
	else
		printf("text2 is bigger\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
}
