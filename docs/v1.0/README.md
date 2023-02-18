# Especificación del lenguaje (v1.0)
## Convenciones generales y lineamientos:
- Los nombres de variables e identificadores NO pueden ser escritos con carácteres con tilde.
- Se pueden utilizar barras bajas/underlines (_) para escribir dichos nombres.
- El lenguaje distingue entre mayúscules y minúsculas (case-sensitive).
- Se pueden utilizar números naturales para la escritura de nombres de variables e identificadores.
- Los nombres de variables o identificadores NUNCA pueden iniciar con un número.
- Los nombres de variables e identificadores NUNCA deben ser palabras reservadas del lenguaje (keywords).
- Las variables son de tipado fuerte y dinámico/estático, como TypeScript. 
## Tipos de datos:
- ENTERO (Enteros)
- NUMERO (Números Reales)
- TEXTO (Texto)
- BOOLEANO (Booleano)
## Sentencias:
- SI/ENTONCES/FINSI (Condicionales)
- MIENTRAS/HACER/FINMIENTRAS (Bucles simples)
- REPETIR/HASTA (Repeticiones)
- DESDE/HASTA/PASO/FINDESDE (Bucles "DO-FOR")
- FUNCION/RETORNAR (Funciones y subrutinas)
- ENCASOQUE/SEAIGUALQUE/FINCASO/FINENCASOQUE (Condicional "Switch-Case")
- LEER (Leer variables por teclado)
- IMPRIMIR (Mostrar texto o variables por pantalla)
- CLASE/PRIVADO/PUBLICO/CONSTRUCTOR/EXTIENDEA/FINCLASE (Clases)
## Operadores aritméticos:
- \+ (Suma)
- \- (Diferencia)
- \* (Producto)
- / (Cociente)
- % (Módulo)
## Operadores lógicos:
- ! (Negación)
- == (Igual que)
- != (No igual que, distinto de)
- \> (Mayor que)
- < (Menor que)
- \>= (Mayor o igual que)
- <= (Menor o igual que)
## Operadores de asignación:
- = (Asignación)
## Operadores especiales:
- \<tipo\>\* (Puntero a \<tipo\>)
- &\<variable\> (Referencia a \<variable\>)
- \<objeto\>.\<miembro\> (\<miembro\> de \<objeto\>)
- \<objeto\>\-\>\<miembro\> (\<miembre\> de \<objeto\>. \<objeto\> debe ser del mismo tipo que el objeto que accede a \<miembro\>)
- \<variable\>\+\+ (Incremento en uno del valor de \<variable\>)
- \<variable\>\-\- (Decremento en uno del valor de \<variable\>)
## Valores especiales:
- VERDADERO (verdadero en expresiones booleanas. 0 en números)
- FALSO (falso en expresiones booleanas. 1 o -1 en números)
- NULO (nulo o cero. También representa objetos, arrays y textos vacíos)
## Comentarios:
- \# (Línea de comentario)
