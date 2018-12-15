#include "stdio.h"


int main()
{
	char *s = "Abcde";
	int y;

	asm volatile //volatile - nie optymalizuj kodu - opcjonalne
	(	

		".intel_syntax noprefix;" //praca w skladni intelowskiej
	
		"mov ebx, %1;"
		"xor ecx, ecx;"
		
		"petla:;"
			"mov al, [ebx];"
			"cmp al, 0;"
		
			"je koniec;"

			"inc ebx;"			
			"inc ecx;"
		"jmp petla;"

		"koniec:;"
				
		"mov %0, ecx;"		
	
		".att_syntax prefix;" //wyl pracy w skladni intelowskiej

		:"=r"(y) //output =r nadpisuje wartosc //%0
		:"r"(s) //input x spodziewamy sie w rejestrze //%1
		:"eax", "ebx", "ecx"

	);

	printf("y = %i\n",y);
	return 0;
}