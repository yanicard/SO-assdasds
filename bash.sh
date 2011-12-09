#!/bin/bash
# -----------------------------------------------------------------------
# Tarea 1 Sistemas Operativos
# Yanara Rojas		2973057-1	yrojas@alumnos.inf.utfsm.cl
# Rodrigo Verdugo	2973061-k	rverdugo@alumnos.inf.utfsm.cl
# -----------------------------------------------------------------------

# function to write log
function log {
	echo "El archivo '$1' fue movido a la carpeta 'tareas/$2/$3/' ($4 KB)" >> log.txt
}
# funtion to check years and create folders
function checkYear {
	# 2000
	if [ $1 -eq 20 ]; then
		# check if folder is created
		if [ ! -d "2000" ]; then
			mkdir 2000
			folder='2000'
		else
		# if created, return folder name 
			folder='2000'
		fi
	# 2001
	elif [ $1 -eq 21 ]; then
		if [ ! -d "2001" ]; then
			mkdir 2001
			folder='2001'
		else
			folder='2001'
		fi	
	# 2002
	elif [ $1 -eq 22 ]; then
		if [ ! -d "2002" ]; then
			mkdir 2002
			folder='2002'
		else
			folder='2002'
		fi
	# 2003
	elif [ $1 -eq 23 ]; then
		if [ ! -d "2003" ]; then
			mkdir 2003
			folder='2003'
		else
			folder='2003'
		fi
	# 2004
	elif [ $1 -eq 24 ]; then
		if [ ! -d "2004" ]; then
			mkdir 2004
			folder='2004'
		else
			folder='2004'
		fi
	# 2005
	elif [ $1 -eq 25 ]; then
		if [ ! -d "2005" ]; then
			mkdir 2005
			folder='2005'
		else
			folder='2005'
		fi
	# 2006
	elif [ $1 -eq 26 ]; then
		if [ ! -d "2006" ]; then
			mkdir 2006
			folder='2006'
		else
			folder='2006'
		fi
	# 2007 
	elif [ $1 -eq 27 ]; then
		if [ ! -d "2007" ]; then
			mkdir 2007
			folder='2007'
		else
			folder='2007'
		fi
	# 2008
	elif [ $1 -eq 28 ]; then
		if [ ! -d "2008" ]; then
			mkdir 2008
			folder='2008'
		else
			folder='2008'
		fi
	# 2009
	elif [ $1 -eq 29 ]; then
		if [ ! -d "2009" ]; then
			mkdir 2009
			folder='2009'
		else
			folder='2009'
		fi
	# 2010
	elif [ $1 -eq 2010 ]; then
		if [ ! -d "2010" ]; then
			mkdir 2010
			folder='2010'
		else
			folder='2010'
		fi
	# 2011
	elif [ $1 -eq 2011 ]; then
		if [ ! -d "2011" ]; then
			mkdir 2011
			folder='2011'
		else
			folder='2011'
		fi
	fi
}
# function to check grade
# param $folder $grade  
function checkGrade {
	# 04 - Plan Comun
	if [ $2 -eq 04 ]; then
		if [ ! -d "PlanComun" ]; then
			mkdir $1/PlanComun
			grade='PlanComun'
		else
			grade='PlanComun'
		fi
	# 03 - PPI
	elif [ $2 -eq 03 ]; then
		if [ ! -d "PPI" ]; then
			mkdir $1/PPI
			grade='PPI'
		else
			grade='PPI'
		fi
	# 30 - Telematica
	elif [ $2 -eq 30 ]; then
		if [ ! -d "Telematica" ]; then
			mkdir $1/Telematica
			grade='Telematica'
		else
			grade='Telematica'
		fi
	# 21 - Electronica
	elif [ $2 -eq 21 ]; then
		if [ ! -d "Electronica" ]; then
			mkdir $1/Electronica
			grade='Electronica'
		else
			grade='Electronica'
		fi
	# 23 - Electrica
	elif [ $2 -eq 23 ]; then
		if [ ! -d "Electrica" ]; then
			mkdir $1/Electrica
			grade='Electrica'
		else
			grade='Electrica'
		fi
	# 90 - Especial
	elif [ $2 -eq 90 ]; then
		if [ ! -d "Especial" ]; then
			mkdir $1/Especial
			grade='Especial'
		else
			grade='Especial'
		fi
	# 73 - Informatica
	elif [ $2 -eq 73 ]; then
		if [ ! -d "Informatica" ]; then
			mkdir $1/Informatica
			grade='Informatica'
		else
			grade='Informatica'
		fi
	# 51 - Quimica
	elif [ $2 -eq 51 ]; then
		if [ ! -d "Quimica" ]; then
			mkdir $1/Quimica
			grade='Quimica'
		else
			grade='Quimica'
		fi

	# 84 - Ambiental
	elif [ $2 -eq 84 ]; then
		if [ ! -d "Ambiental" ]; then
			mkdir $1/Ambiental
			grade='Ambiental'
		else
			grade='Ambiental'
		fi

	# 41 - Mecanica
	elif [ $2 -eq 41 ]; then
		if [ ! -d "Mecanica" ]; then
			mkdir $1/Mecanica
			grade='Mecanica'
		else
			grade='Mecanica'
		fi	

	# 60 - Industrial
	elif [ $2 -eq 60 ]; then
		if [ ! -d "Industrial" ]; then
			mkdir $1/Industrial
			grade='Industrial'
		else
			grade='Industrial'
		fi

	# 66 - Comercial
	elif [ $2 -eq 66 ]; then
		if [ ! -d "Comercial" ]; then
			mkdir $1/Comercial
			grade='Comercial'
		else
			grade='Comercial'
		fi

	# 83 - Ambiental2
	elif [ $2 -eq 83 ]; then
		if [ ! -d "Ambiental2" ]; then
			mkdir $1/Ambiental2
			grade='Ambiental2'
		else
			grade='Ambiental2'
		fi

	# 02 - Especial2
	elif [ $2 -eq 02 ]; then
		if [ ! -d "Especial2" ]; then
			mkdir $1/Especial2
			grade='Especial2'
		else
			grade='Especial2'
		fi

	# 11 - ObrasCiviles 
	elif [ $2 -eq 11 ]; then
		if [ ! -d "ObrasCiviles" ]; then
			mkdir $1/ObrasCiviles
			grade='ObrasCiviles'
		else
			grade='ObrasCiviles'
		fi

	# 44 - IDP
	elif [ $2 -eq 44 ]; then
		if [ ! -d "IDP" ]; then
			mkdir $1/IDP
			grade='IDP'
		else
			grade='IDP'
		fi

	# 43 - MecanicaIndustrial
	elif [ $2 -eq 43 ]; then
		if [ ! -d "MecanicaIndustrial" ]; then
			mkdir $1/MecanicaIndustrial
			grade='MecanicaIndustrial'
		else
			grade='MecanicaIndustrial'
		fi

	# 41 - Arquitectura
	elif [ $2 -eq 41 ]; then
		if [ ! -d "Arquitectura" ]; then
			mkdir $1/Arquitectura
			grade='Arquitectura'
		else
			grade='Arquitectura'
		fi

	# 12 - ConstruccionCivil
	elif [ $2 -eq 12 ]; then
		if [ ! -d "ConstruccionCivil" ]; then
			mkdir $1/ConstruccionCivil
			grade='ConstruccionCivil'
		else
			grade='ConstruccionCivil'
		fi
		
	fi
}
# function to move file to folder
function moveFile {
	`mv $1 $2"/"$3"/"$1`
	log $1 $2 $3 $4
}
# ----------------- main -------------------------- 
# join to directory
cd $1
# extract name of file and move to file
for FILE in `ls`; do
	name=`stat -c %n $FILE`	# filename
	size=`stat -c %s $FILE`	# size

	size=`expr $size \/ 1024` # size in Byte

	length=$(echo $name | wc -m) # length of 
	# check length of filename 
	if [ $length -eq 15 ]; then
		year=${name:0:2}
		grad=${name:2:2}
	fi
	# ROL > 2009
	if [ $length -eq 17 ]; then
		year=${name:0:4}
		grad=${name:4:2}
	fi
	# create folders to years and grade
	checkYear $year # return $folder
	checkGrade $folder $grad # return $grade
	moveFile $name $folder $grade $size
done
