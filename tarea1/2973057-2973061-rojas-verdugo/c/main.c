#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "crear_directorio.h"

/* main */
int main(int argc, char *argv[]){
    DIR *fdir;
    struct dirent *sdir;
    char year[5], grade[3];
    char aux[1], aux2[4],aux3[6];
    int length, i;
	char year_aux[argc];
	char grade_aux[argc];
	char* carrera;
	char *redir = (char*)malloc(100); 
	
	/* Se debe ingresar el nombre de la carpeta */
    if (argc < 2){
        printf("Usage: %s <directory>\n", argv[0]);
        return 0;
    }

    /* Se abre el directorio a leer */
    if ((fdir = opendir(argv[1])) == NULL){
        perror("opendir");
        return 0;
    }

    /* Se leen cada unos de los archivos del directorio abierto */
    while ((sdir = readdir(fdir)) != NULL){
        /* Reseteo de variables */
        for(i=0; i<4; i++)
			{year[i] = 0;}
        for(i=0; i<2; i++)
			{grade[i] = 0;}

        /* Tamanio del nombre del archivo */
        length = strlen(sdir->d_name);
		
		/* Se llama a la creación de las carpetas */
        crear_carpetas(length, sdir->d_name, argc, argv[1]);
    }
    
    /* Se mueve el archivo log.txt al directorio pasado por parámetro */
    strcpy(redir, argv[1]);
    strcat(redir, "/log.txt");
    rename("log.txt", redir);
    
    /* Liberación memoria dinámica */
    free(redir);
    
    /* Se cierra el directorio abierto con opendir */
    if (closedir(fdir) == -1){
        perror("closedir");
        return 0;
    }
return 0;
}
