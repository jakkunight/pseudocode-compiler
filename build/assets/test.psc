INICIO
	NÚMERO A, B
	LEER(A, B)
	SI A > B ENTONCES
		IMPRIMIR(A, "es mayor que ", B)
	FINSI
	MIENTRAS B > A HACER
		A = A + 1
		IMPRIMIR("Acercando A a B...")
	FINMIENTRAS
	IMPRIMIR("Múltiplos de", B)
	DESDE I = 0 HASTA B
		IMPRIMIR(I * B)
	FINDESDE
	IMPRIMIR("Múltiplos de", B)
	factorial = 1;
	DESDE I = 0 HASTA A
		factorial = factorial * I
	FINDESDE
	IMPRIMIR("Factorial de A:", factorial)
FIN
