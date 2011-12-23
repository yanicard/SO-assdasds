all: 
	gcc -c crear_directorio.c -o crear_directorio.o
	ar rcs libcrear_directorio.a crear_directorio.o
	gcc main.c -L. -lcrear_directorio -o organize
clean:
	$(RM) libcrear_directorio.a libcrear_directorio.o crear_directorio.o organize
