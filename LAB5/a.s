.intel_syntax noprefix ; #komentarz

.global main ; #symbole widoczne na zewn

.text ; #tutaj kod

	main: 
		mov eax, offset msg ; # offset - daj adres do msg
		push eax
		call printf
			#pop eax ; # zdejmij eax ze stosu
		add esp, 4 ; # przesun wskaznik stosu / zamiast pop
			#mov eax, 0
		ret ; # powrot do proc

.data ; #input

	msg: .asciz "Hello, world\n" 
		#typ danych kolejne znaki asci z - zakonczone 0 / i - zwykly ciag


