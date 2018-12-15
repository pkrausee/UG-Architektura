#include "stdio.h"


int main()
{
	int x = 2018;
	int y = 0;

	asm volatile //volatile - nie optymalizuj kodu - opcjonalne
	(	

		".intel_syntax noprefix;" //praca w skladni intelowskiej

		"mov eax, %1;"
		"mov ecx, 0;"

		"xor ecx, ecx;" //wyzeruj rejestr

		"petla:"
		
			"add eax, eax;"
			"add ecx, 1;"

			"inc ecx;" //increment 
			"cmp ecx, 10;" //porownaj ecx do 10 // podziel przez 10 i spr czy reszta to 0
		
		"jnz petla;"
	
		"mov %0, eax;"

		".att_syntax prefix;" //wyl pracy w skladni intelowskiej

		:"=r"(y) //output =r nadpisuje wartosc //%0
		:"r"(x) //input x spodziewamy sie w rejestrze //%1
		:"eax", "ecx"

	);

	printf("y = %i\n",y);
	return 0;
}