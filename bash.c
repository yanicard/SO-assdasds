#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* Prototipo de funciones */
char* grades(int carrera);
int crear_carpetas(int length, char* sdir, int argc, char* argv);
void mover_archivos(char *direccion, char *archivo);

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
	
	//Se debe ingresar el nombre de la carpeta
    if (argc < 2){
        printf("Usage: %s <directory>\n", argv[0]);
        return 0;
    }

    /* DIR *opendir(const char *name); abre el directorio a leer
     *
     * Open a directory stream to argv[1] and make sure
     * it's a readable and valid (directory)
     */
    if ((fdir = opendir(argv[1])) == NULL){
        perror("opendir");
        return 0;
    }

    /* struct dirent *readdir(DIR *dir);
     *
     * Read in the files from argv[1] and print
     *Se dejan listo el año de los archivos*/
    while ((sdir = readdir(fdir)) != NULL){
        // reset var
        for(i=0; i<4; i++)
			{year[i] = 0;}
        for(i=0; i<2; i++)
			{grade[i] = 0;}

        // tam nombre
        length = strlen(sdir->d_name);
		
        crear_carpetas(length, sdir->d_name, argc, argv[1]);
    }
    
    /* int closedir(DIR *dir);  Cierra el directorio abierto con opendir.
     *
     * Close the stream to argv[1]. And check for errors.  
     */
    if (closedir(fdir) == -1){
        perror("closedir");
        return 0;
    }
return 0;
}

/* Funciones */
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
			carrerars = "Ambiental2";
			break;
		case 02:
			carrerars = "Especial2";
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

int crear_carpetas(int length, char* sdir, int argc, char* argv){
    DIR *fdir, *fder;
    struct dirent *sder, *sdor;
    char year[5], grade[3];
    char aux[1], aux2[4],aux3[6];
    int i, flag=1, flag2=1;
	char year_aux[argc];
	char grade_aux[argc];
	char* carrera; 
	
	if ((fdir = opendir(argv)) == NULL)
    {
        perror("opendir");
        return 0;
    }
	
	// verificaciones
        if (length == 14 ) {
			strncpy(year,sdir,2);
            // swap caracteres, se deja listo el año
            year[3] = year[1];
            year[1] = '0';
            year[2] = '0';
            year[4] = '\0';
            
            //Se extrae el código de la carrera
            strncpy(aux2,sdir,4);
            grade[0] = aux2[2];
            grade[1] = aux2[3];
            grade[2] = '\0';
             
            while ((sder = readdir(fdir)) != NULL){
				if( !strcpy(sder->d_name, year) )
					flag = 0;
			}
            
            //Se verifica si la carpeta del anio ha crear ya existe
            if(flag == 1){
				//Se crea la dirección de la carpeta
				strcpy(year_aux, argv);
				strcat(year_aux, "/");
				strcat(year_aux, year);
				
				//Se crea la carpeta para el anio
				mkdir(year_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            }
            
            if ((fder = opendir(year_aux)) == NULL)
			{
				perror("opendir");
				return 0;
			}
            
            carrera = (char*) malloc (30);
			strcpy(carrera, grades(atoi(grade)));
            
            if(strcmp("nada",carrera)){
				flag2 = 1;
				//Se verifica si la carpeta de la carrera ha crear ya existe
				while ((sdor = readdir(fder)) != NULL){
					if( !strcpy(sdor->d_name, carrera) )
						flag2 = 0;
				}
				
				if(flag2 == 1){
					strcpy(grade_aux, year_aux);
					strcat(grade_aux, "/");
					strcat(grade_aux, carrera);
					//Se crea la carpeta para la carrera
					mkdir(grade_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
					
					mover_archivos(grade_aux, sdir);
				}
			}
			
			for(i=0; i<30; i++)
				{year_aux[i]= 0;}
			for(i=0; i<30; i++)
				{grade_aux[i]= 0;}
			
			free(carrera);
			
			if(closedir(fder) == -1){
				perror("closedir");
				return 0;
			}
		}

        if (length == 16) {
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
				//Se crea la ruta para la creación de carpetas
				strcpy(year_aux, argv);
				strcat(year_aux, "/");
				strcat(year_aux, year);
				
				//Se crea la carpeta para los anios
				mkdir(year_aux, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            }
            
            if ((fder = opendir(year_aux)) == NULL)
			{
				perror("opendir");
				return 0;
			}
            
			carrera = (char*) malloc (30);
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
				}
			}
			
			for(i=0; i<30; i++)
				{year_aux[i]= 0;}
			for(i=0; i<30; i++)
				{grade_aux[i]= 0;}
			
			free(carrera);
			
			if(closedir(fder) == -1){
				perror("closedir");
				return 0;
			}
	}

if(closedir(fdir) == -1){
	perror("closedir");
    return 0;
}	

return 0;
}

void mover_archivos(char *direccion, char *archivo){
		if(strcmp(archivo, "2000") || strcmp(archivo, "2001") || strcmp(archivo, "2002") || strcmp(archivo, "2003") || strcmp(archivo, "2004") || strcmp(archivo, "2005") || strcmp(archivo, "2006") || strcmp(archivo, "2007") || strcmp(archivo, "2008") || strcmp(archivo, "2009") || strcmp(archivo, "2010") || strcmp(archivo, "2011")){
			// mover archivo xD
		}
}
