INICIO
	IMPRIMIR("==== PROGRAMA FACTORIAL ====")
	NUMERO A, B
	LEER(A, B)
	SI A > B ENTONCES
		IMPRIMIR(A, "es mayor que ", B)
	FINSI
	MIENTRAS B > A HACER
		A = A + 1
		IMPRIMIR("Acercando A a B...")
	FINMIENTRAS
	IMPRIMIR("Multiplos de", B)
	DESDE I = 0 HASTA B
		IMPRIMIR(I * B)
	FINDESDE
	IMPRIMIR("Multiplos de", B)
	factorial = 1;
	DESDE I = 0 HASTA A
		factorial = factorial * I
	FINDESDE
	IMPRIMIR("Factorial de A:", factorial)
FIN
