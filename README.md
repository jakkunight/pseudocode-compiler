# pseudocode-compiler
Un compilador de pseudocódigo que apunta a ser un estándar en los países de habla hispana y en la enseñanza 
en general de la algoritmia y la programación.
## Estado del proyecto:
* Se ha podido implementar un lexer, una rutina que descompone el código en tokens y extrae la información relevante del código. 
El programa debería mostrar el código del archivo de pruebas descompuesto y analizado. En UNIX/Linux, debe mostrar caracteres UTF-8. No hay pruebas en Windows.
* Se ha incluido un archivo de prueba en la carpeta build/assets, llamado "test.psc". GitHub lo detecta como un archivo en formato "papyrus",
por lo que podría causar confusión.
* Se está trabajando en una implementación del lenguaje que admita carácters con acento y nasales, propias del español y el castellano, así como
del guaraní, idioma oficial del país en el que resido, y del público al que va orientado este programa.
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
¿No te gusta la especificación del lenguaje?\n
¿No te gusta la extensión del archivo?\n
¿Crees que lo puedes hacer mejor?\n
¡Escucho todas tus dudas y sugerencias!\n
Si desea colaborar, puede escribirme un email, abrir un issue, o realizar un pull-request.
