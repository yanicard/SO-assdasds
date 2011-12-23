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

/* Recibe por parámetro el código de carrera. Retorna el nombre de la carrera*/
char* grades(int carrera){
	char* carrerars;
	
	switch(carrera){
		case 04:
			carrerars = "PlanComun";
			break;
		case 73:
			carrerars = "Informatica";
			break;
			
		case 03:
			carrerars = "PPI";
			break;
		case 30:
			carrerars = "Telematica";
			break;
		case 21:
			carrerars = "Electronica";
			break;
		case 23:
			carrerars = "Electrica";
			break;
		case 90:
			carrerars = "Especial";
			break;
		case 51:
			carrerars = "Quimica";
			break;
		case 84:
			carrerars = "Ambiental";
			break;
		case 41:
			carrerars = "Mecanica";
			break;
		case 60:
			carrerars = "Industrial";
			break;
		case 66:
			carrerars = "Comercial";
			break;
		case 83:
			carrerars = "Ambiental";
			break;
		case 02:
			carrerars = "Especial";
			break;
		case 11:
			carrerars = "ObrasCiviles";
			break;
		case 44:
			carrerars = "IDP";
			break;
		case 43:
			carrerars = "MecanicaIndustrial";
			break;
		case 13:
			carrerars = "Arquitectura";
			break;
		case 12:
			carrerars = "ConstruccionCivil";
			break;	
		default: 
			carrerars = "nada";
			break;
	}
return carrerars;
}

/* Se crean las carpetas para los anios y carreras. Recibo por parámetro el largo del archivo, el puntero al directorio, 
	el tamanio de la dirección dada y ésta última */ 
int crear_carpetas(int length, char* sdir, int argc, char* argv){
    DIR *fdir, *fder;
    struct dirent *sder, *sdor;
    char year[5], grade[3];
    char aux[1], aux2[4],aux3[6];
    int i, flag=1, flag2=1, tamanio;
	char year_aux[argc];
	char grade_aux[argc];
	char* carrera, *dir_actual; 
	
	/* Se calcula el tamanio del directorio */
	tamanio = strlen(argv);
	
	/* Se abre el directorio */
	if ((fdir = opendir(argv)) == NULL)
    {
        perror("opendir");
        return 0;
    }
	
	/* Indicaciones para los rol del 2000 al 2009 */
    if (length == 14 ){
		strncpy(year,sdir,2);
        /* Swap carácteres, se deja listo el año */
        year[3] = year[1];
        year[1] = '0';
        year[2] = '0';
        year[4] = '\0';
            
        /* Se extrae el código de la carrera */
        strncpy(aux2,sdir,4);
        grade[0] = aux2[2];
        grade[1] = aux2[3];
        grade[2] = '\0';
        
        /* Se verifica si la carpeta de ese anio ya fue creada */      
        while ((sder = readdir(fdir)) != NULL){
			if( !strcpy(sder->d_name, year) )
				flag = 0;
		}
            
        /* Se verifica si la carpeta del anio ha crear ya existe */
        if(flag == 1){
			/* Se crea la dirección de la carpeta */
			strcpy(year_aux, argv);
			strcat(year_aux, "/");
			strcat(year_aux, year);
				
			/* Se crea la carpeta para el anio */
			mkdir(year_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		}
        
        /* Se abre el directorio del anio */    
        if ((fder = opendir(year_aux)) == NULL){
			perror("opendir");
			return 0;
		}
            
        carrera = (char*) malloc (30);
        dir_actual = (char*) malloc(tamanio + 200 );
        /* Se verifica a que carrera pertenece el archivo analizado */
		strcpy(carrera, grades(atoi(grade)));
        
        /* Se verifica que el archivo tenga un código de carrera válido */    
        if(strcmp("nada",carrera)){
			flag2 = 1;
			/* Se verifica si la carpeta de la carrera ha crear ya existe */
			while ((sdor = readdir(fder)) != NULL){
				if( !strcpy(sdor->d_name, carrera) )
					flag2 = 0;
			}
				
			if(flag2 == 1){
				/* Se crea la dirección para la carpeta */
				strcpy(grade_aux, year_aux);
				strcat(grade_aux, "/");
				strcat(grade_aux, carrera);
				/* Se crea la carpeta para la carrera */
				mkdir(grade_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
					
				strcpy(dir_actual, argv);
				strcat(dir_actual, "/");
				strcat(dir_actual, sdir);
				
				/* Se mueve el archivo a su carpeta correspondiente	*/
				mover_archivos(dir_actual, grade_aux, sdir, argv);
			}
		}
		
		/* Reset de variables */	
		for(i=0; i<30; i++)
			{year_aux[i]= 0;}
		for(i=0; i<30; i++)
			{grade_aux[i]= 0;}
		
		/* Liberación memoria dinámica */
		free(carrera);
		free(dir_actual);
		
		/* Se cierra el directorio abierto */
		if(closedir(fder) == -1){
			perror("closedir");
			return 0;
		}
	}
	
	/* Indicaciones para los rol del 2010 en adelante */
	if(length == 16){
		strncpy(year, sdir, 4);
        year[4] = '\0';
            
        strncpy(aux3,sdir,6);
        grade[0] = aux3[4];
        grade[1] = aux3[5];
        grade[2] = '\0';
            
        while ((sder = readdir(fdir)) != NULL){
			if( !strcpy(sder->d_name, year) )
				flag = 0;
		}
            
        if(flag == 1){
			strcpy(year_aux, argv);
			strcat(year_aux, "/");
			strcat(year_aux, year);
				
			mkdir(year_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }
            
        if((fder = opendir(year_aux)) == NULL){
			perror("opendir");
			return 0;
		}
            
		carrera = (char*) malloc (30);
		dir_actual = (char*) malloc(tamanio + 200);
		strcpy(carrera, grades(atoi(grade)));
            
        if(strcmp("nada",carrera)){
			flag2 = 1;
				
			while ((sdor = readdir(fder)) != NULL){
				if( !strcpy(sdor->d_name, carrera) )
					flag2 = 0;
			}
				
			if(flag2 == 1){
				strcpy(grade_aux, year_aux);
				strcat(grade_aux, "/");
				strcat(grade_aux, carrera);
				mkdir(grade_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
					
				strcpy(dir_actual, argv);
				strcat(dir_actual, "/");
				strcat(dir_actual, sdir);
				mover_archivos(dir_actual, grade_aux, sdir, argv);
			}
		}
		
		for(i=0; i<30; i++)
			{year_aux[i]= 0;}
		for(i=0; i<30; i++)
			{grade_aux[i]= 0;}
			
		free(carrera);
		free(dir_actual);
			
		if(closedir(fder) == -1){
			perror("closedir");
			return 0;
		}
	}

/* Se cierra el directorio abierto */
if(closedir(fdir) == -1){
	perror("closedir");
    return 0;
}	

return 0;
}

/* Se crea y/o escribe el archivo log.txt. Recibe por parámetro la dirección del archivo en donde se coloca, el nombre del archivo y 
	la dirección del directorio dada al principio */
int log_text(char *direccion, char *archivo, char *argv){
    struct stat buf;
    FILE *fp;
    char *cadena = (char*)malloc(200), *cadena2 = (char*)malloc(200);
    int tam;
        
    if(stat(argv, &buf) == -1){
	perror("stat");
	return 0;
    }
    
    /* Se calcula el tamaño en KB del archivo */
    tam = buf.st_size/1024;
    
    strcpy(cadena, "El archivo '");
    strcat(cadena, archivo);
    strcat(cadena, "' fue movido a la carpeta ");
    strcat(cadena, direccion);
    strcat(cadena, " (");
    strcpy(cadena2, " KB)\n");
    
    /* Se abre/crea el archivo log.txt para posteriormente escribirlo */
    fp = fopen("log.txt","a");
    fputs(cadena, fp);
    fprintf(fp, "%d",tam);
    fputs(cadena2, fp);
    fclose(fp);
	
    /* Liberación memoria dinámica */
    free(cadena);
    free(cadena2);
return 0;
}

/* Se mueven los archivos a sus respectivas carpetas. Recibe por parámetro la dirección actual en donde se encuentran, la dirección nueva a la que deben
	moverse, el nombre del archivo y la dirección del directorio dada inicialmente */
void mover_archivos(char *dir_actual, char *dir_nueva, char *archivo, char *argv){
	char *direccion;
	int tamanio;
	
	/* Se calcula el tamanio de carácteres del directorio */
	tamanio = strlen(argv);
	direccion = (char*)malloc (tamanio + 200);
	
	/* Se verficia que el archivo analizado no sea una carpeta */
	if(strcmp(archivo, "2000") && strcmp(archivo, "2001") && strcmp(archivo, "2002") && strcmp(archivo, "2003") && strcmp(archivo, "2004") && strcmp(archivo, "2005") && strcmp(archivo, "2006") && strcmp(archivo, "2007") && strcmp(archivo, "2008") && strcmp(archivo, "2009") && strcmp(archivo, "2010") && strcmp(archivo, "2011")){
		strcpy(direccion, dir_nueva);
		strcat(dir_nueva, "/");
		strcat(dir_nueva, archivo);
		
		/* Se mueve el archivo a su debida carpeta */
		rename(dir_actual, dir_nueva);
		
		/* Se escribe en el archivo log.txt */
		log_text(direccion, archivo, argv);
	}
	
	/* Liberación memoria dinámica */
	free(direccion);
}
