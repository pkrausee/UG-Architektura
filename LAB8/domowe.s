.intel_syntax noprefix
.global _start
.text

# ecx - ciag znakow 
# edx - dlugosc

_start:
    mov ecx, [esp + 8]

    fCond:
        mov edx, 0
        mov eax, ecx
        mov bl, [eax]

        cmp bl, 0
        je end

        cmp bl, 'a'
        je sCond

        cmp bl, 'b'
        je sCond

        cmp bl, 'z'
        je sCond

        add ecx, 1
        jmp fCond

    sCond:
        add edx, 1
        add eax, 1
        mov bl, [eax]

        cmp bl, 0
        je end

        cmp bl, 'a'
        je wrongC
        
        cmp bl, 'b'
        je wrongC
        
        cmp bl, 'c'
        je checkEnd

        jmp sCond

    wrongC:
        add ecx, 1
        jmp fCond

    checkEnd:
        cmp edx, 1
        jna wrongC

	print:
        add edx, 1

        mov eax, 4
        mov ebx, 1
        int 0x80

        mov eax, 4
        mov ebx, 1
        mov ecx, offset nextL
        mov edx, offset len
        int 0x80

    end:
		mov ebx, 0
		mov eax, 1
		int 0x80

.data
	nextL:	.asciz "\n"
			.equ len, $-nextL
