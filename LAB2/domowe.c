#include "stdio.h"

int main()
{
    int x, y;
    y = 0;

    printf("Podaj liczbe: ");
    scanf("%i", &x);

    //eax - liczba
    //ebx - ilos kombinacji
    //cl - przesuniecie

    asm volatile
    (
        ".intel_syntax noprefix;"

        "xor cl, cl;"
        "mov eax, %1;"
        "xor ebx, ebx;"

        "petla:;"
            "shr eax, 1;"
                "jnc zle;"
            "shr eax, 1;"
                "jc zle;"
            "shr eax, 1;"
                "jnc zle;"
            "inc ebx;"
            "zle:;"
            "inc cl;"
            "mov eax, %1;"
            "shr eax, cl;"          
        "jnz petla;"

        "mov %0, ebx;"

        ".att_syntax prefix;"

        :"=r"(y)
        :"r"(x)
        :"eax", "ebx"
    );

    printf("Ilosc kombinacji w liczbie %i - %i\n",x,y);
    return 0;
}