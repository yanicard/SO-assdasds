#!/usr/bin/python
# -*- coding: iso-8859-15
# Tarea 2 Sistemas Operativos  
import sys

if len(sys.argv) == 3:
        if sys.argv[2] < 0:
        	print "La Profundidad no puede ser Negativa"
        else:
        	print "hola mundo"
else:
        print "Este programa necesita un parámetro"