# pseudocode-compiler
Un compilador de pseudocódigo que apunta a ser un estándar en los países de habla hispana y en la enseñanza 
en general de la algoritmia y la programación.
## Estado del proyecto:
* Se ha hecho posible utilizar el programa como una especie de "comando cat mejorado", es decir, muestra el contenido de un archivo de texto y su 
tamaño en número de bytes. En UNIX/Linux, debe mostrar caracteres UTF-8. No hay pruebas en Windows.
* Se ha incluido un archivo de prueba en la carpeta build/assets, llamado "test.psc". GitHub lo detecta como un archivo en formato "papyrus",
por lo que podría causar confusión.
## Compilación:
Para compilar el programa, simplemente ejecute el siguiente comando en un terminal (Linux):
> ./build.sh
>
Si está en Windows, ejecute el siguiente comando desde PowerShell o el CMD:
> build.bat
>
Listo! El programa ya ha sido compilado. El ejecutable ha sido generado en la carpeta build con el nombre de "psc".
Si necesita modificar de alguna manera el proceso de compilación, edite el archivo CMakeLists.txt con su editor de texto favorito.
## Ejecución:
Para ejecutar el programa, simplemente ejecute el siguiente comando en un terminal:
> ./build/psc assets/test.psc
>
Si está en Windows, ejecute el siguiente comando:
> build/psc assets\\tests.psc
>
Y listo! Debería ver el resultado de la ejecución en su consola/terminal.
## ¡Colabora!
¿No te gusta la especificación del lenguaje?
¿No te gusta la extensión del archivo?
¿Crees que lo puedes hacer mejor?
¡Escucho todas tus dudas y sugerencias!
Si desea colaborar, puede escribirme un email, abrir un issue, o realizar un pull-request.
