#include "stdio.h"


int main()
{
	int x = 2018;
	int y = 0;

	asm volatile //volatile - nie optymalizuj kodu - opcjonalne
	(	

		".intel_syntax noprefix;" //praca w skladni intelowskiej
		"mov eax,%1;" //przenies %1 do eax
		"add eax,eax;" //dodaj eax do eax
		"mov %0,eax;"
		".att_syntax prefix;" //wyl pracy w skladni intelowskiej
		:"=r"(y) //output =r nadpisuje wartosc //%0
		:"r"(x) //input x spodziewamy sie w rejestrze //%1
		:"eax" //uzywany rejestr

	);

	printf("y = %i\n",y);
	return 0;
}