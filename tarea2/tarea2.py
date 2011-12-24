#!/usr/bin/python
# -*- coding: iso-8859-15
# Tarea 2 Sistemas Operativos  
import sys 
import os

if len(sys.argv) == 3:
        if sys.argv[2] < 0:
        	print "La Profundidad no puede ser Negativa"
        else:
        	# cambia de directorio
        	# os.chdir(sys.argv[1])
        	print os.getpid()
        	# os.pipe()
        	# direcotrio actual
        	# print os.getcwd()
        	for file in os.listdir(sys.argv[1]):
        		print file
else:
        print "Este programa necesita un parámetro"