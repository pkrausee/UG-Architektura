#include <stdio.h>

int main() {
    char s[] = "Abcde";

    asm volatile //volatile - nie optymalizuj kodu - opcjonalne
    (
        ".intel_syntax noprefix;"
        "mov ecx, %0;"
        "mov ebx, %0;"

        "petla:" //szukanie konca stringa
        
            "inc ebx;"
            "mov al, [ebx];"
            "cmp al, 0;"

        "jne petla;"

        "dec ebx;"

        "petla2:" //zamiana liter

            "mov al, [ecx];"
            "mov ah, [ebx];"
            "mov [ebx], al;"
            "mov [ecx], ah;"

            "inc ecx;"
            "dec ebx;"
            "cmp ecx, ebx;"

        "jb petla2;"
        
        ".att_syntax prefix;"
        :
        :"r"(s)
        :"eax", "ebx", "ecx"
);

    printf("s = %s\n", s);
}