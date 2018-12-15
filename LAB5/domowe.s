.intel_syntax noprefix ; #komentarz

.global main ; #symbole widoczne na zewn

.text ; #tutaj kod

	main: 	
		
		push offset x
		push offset formatIn
		
		call scanf

		add esp, 8	
		
		mov eax, x
		add eax, eax
		push eax
		push offset formatOut

		call printf

		add esp, 8

		xor eax, eax

		ret

.data ; #input

	x: .int 0
	formatIn: .asciz "%i"
	formatOut: .asciz "%i\n"

