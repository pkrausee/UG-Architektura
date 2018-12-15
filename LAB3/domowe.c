#include "stdio.h"

int main()
{
    int x = 0xffffffff;
    int y = 0;

    //eax - liczba
    //ebx - liczba pomocnicza
    //ecx - dlugosc najdluzszego ciagu 1
    //edx - dlugosc pomocnicza


    asm volatile
    (
        ".intel_syntax noprefix;"
	 
	"mov eax, %1;"
	"mov ecx, 0;"
	"mov edx, 0;"
	
	"petla:;"

		"mov ebx, eax;"

		"petlaa:;"
			"inc edx;"
			"shr ebx, 1;"
		"jc petlaa;"

		"dec edx;"

		"cmp ecx, edx;"
			"jge dalej;"

		"mov ecx, edx;"

		"dalej:;"
		"mov edx, 0;"
		"shr eax, 1;"
		
        "jnz petla;"
	
        "mov %0, ecx;"

        ".att_syntax prefix;"

        :"=r"(y)
        :"r"(x)
        :"eax", "ebx", "ecx", "edx"
    );

    printf("Ilosc kombinacji w liczbie %i - %i\n",x,y);
    return 0;
}