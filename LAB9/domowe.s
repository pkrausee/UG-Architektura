.intel_syntax noprefix 
.global  main 
.text 

main:
	
	
	finit
	
	mov ecx, [esp+8]
	mov eax, [ecx+4]
	push eax
	call atof
	add esp, 4
	
	

	#fld qword ptr x  				#load x
	fabs
	fldpi
	fldpi
	faddp

reduce:
	fcom
	fstsw ax
	sahf
	ja continue	
	fsub ST(1), ST(0)
	jmp reduce





continue:
	

	fldz
	fcompp


	fmul ST(0), ST(0)	# x^2

	fldz				# n = 0
	fldz				# ret = 0
	fld1				# a = 1
	
	#all set

petla:

	fadd ST(1), ST(0) 	# ret += a
	

	fmul ST(0), ST(3)	# a*x^2

	fld1				# a/(n+1)
	faddp ST(3), ST(0)
	fdiv ST(0), ST(2)
	fld1				# a/(n+2)
	faddp ST(3), ST(0)
	fdiv ST(0), ST(2)




	#compare
	fldz					
	fadd ST(0), ST(1)	
	fabs
	fld qword ptr precission
	fcompp
	fstsw ax
	sahf
	
	fchs

	jb petla		

	
	
	fldz
	fcompp

	sub esp, 8
	fstp qword ptr [esp]
	push offset formatout
	call printf
	add esp, 12

	

	xor eax, eax

	ret

.data
	x: .double 40.0
	precission: .double 0.0000001
	formatout: .asciz "wynik = %f\n"
