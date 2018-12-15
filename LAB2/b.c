#include "stdio.h"


int main()
{
	int x = 2018;
	int y = 0;

	asm volatile //volatile - nie optymalizuj kodu - opcjonalne
	(	

		".intel_syntax noprefix;" //praca w skladni intelowskiej

		"mov eax, %1;"
		"mov ecx, 32;"
		"xor ebx, ebx;"

		"petla:"
		
			"shl eax, 1;"		
			"jnc skok;"
				"inc ebx;"
			"skok:"
			//"dec ecx;"
			"cmp eax , 0;"		

		"jnz petla;"

		"mov %0, ebx;"	
		
		".att_syntax prefix;" //wyl pracy w skladni intelowskiej

		:"=r"(y) //output =r nadpisuje wartosc //%0
		:"r"(x) //input x spodziewamy sie w rejestrze //%1
		:"eax", "ebx", "ecx"

	);

	printf("y = %i\n",y);
	return 0;
}