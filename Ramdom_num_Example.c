#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));

	int S;
	int num;
	num = rand();

	S = (int)num % 10;

	if (S <= 2) { //0,1,2
		puts("베었으나 실패");
	}
	if (S >= 3 && S <= 6) { //3,4,5,6
		puts("베었습니다.");
	}
	if (S >= 7 && S <= 9) { //7,8,9
		puts("제대로 베었습니다!");
	}
}

// https://blockdmask.tistory.com/308