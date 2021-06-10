# pipex
Este proyecto es útil para descubrir el funcionamiento de un mecanismo de UNIX. Consiste en replicar en el lenguaje C el comportamiento de pipes y redireciones simples entre dos ficheros y dos comandos. 

**Ejmplo en una terminal shel**

` $> < archivo1 comando1 | comando2 > archivo2`
` $> < initfile grep a1 | wc > outfile`

**Nota final:  100%** 

**Hacer:** 

`make`

**Para ejecutar:** 

**1** `./pipex archivo1 comando1 comando2 archivo2` 
**1** `./pipex initfile "greap a1" "wc" outfile` 



