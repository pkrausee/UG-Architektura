.intel_syntax noprefix ; #komentarz

.global main ; #symbole widoczne na zewn

.text ; #tutaj kod

	main: 	
		mov eax, [esp + 8]
		push [eax + 4]  	
		call atoi
		add esp, 4

		call fibbo

		push eax
		push offset formatOut 
		call printf

		add esp, 8
		xor eax, eax
		ret

	fibbo:
		cmp eax, 2
		jle except

		push eax		; # n
		dec eax
		call fibbo		; # fibbo dla (n-1)
		push eax		; # fibbo(n-1)

		mov eax, [esp + 4]	; # n
		sub eax, 2
		call fibbo		; # fibo dla (n-2)
		pop ebx			; # fibbo(n-1)
		add esp, 4

		add eax, ebx		; # fibbo(n-2) + fibbo(n-1)	
		ret

	except:
		mov eax, 1
		ret

.data ; #input
	formatOut: .asciz "%i\n"
