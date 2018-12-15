.intel_syntax noprefix ; #komentarz

.global main ; #symbole widoczne na zewn

.text ; #tutaj kod

	main: 	
		mov eax, [esp + 8]
		push [eax + 4]  	
		call atoi
		add esp, 4
		push eax # n

		call fibbo
		add esp, 4

		push eax
		push offset formatOut 
		call printf

		add esp, 8
		xor eax, eax
		ret

	fibbo:
		mov eax, [esp + 4] 
		cmp eax, 2
		jle except
		sub eax, 1		
		push eax # n - 1
		call fibbo		
		add esp, 4
		push eax # fibbo(n-1)
		mov eax, [esp + 8] # n
		sub eax, 2
		push eax
		call fibbo
		add esp, 4
		add eax, [esp]
		add esp, 4		
		ret

	except:
		mov eax, 1
		ret

.data ; #input
	formatOut: .asciz "%i\n"
