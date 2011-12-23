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
# function to check years and create folders
function checkYear {
	if [ ! -d $1 ]; then
		mkdir -p $1
	fi
}
# function to check grade [param $folder $grade]
function checkGrade {
	case $2 in
		"04")
			grade="PlanComun";;
		"03")
			grade="PPI";;
		"30")
			grade="Telematica";;
		"21")
			grade="Electronica";;
		"23")
			grade="Electrica";;
		"90")
			grade="Especial";;
		"73")
			grade="Informatica";;
		"51")
			grade="Quimica";;
		"84")
			grade="Ambiental";;
		"41")
			grade="Mecanica";;
		"60")
			grade="Industrial";;
		"66")
			grade="Comercial";;
		"83")
			grade="Ambiental";;
		"02")
			grade="Especial";;
		"11")
			grade="ObrasCiviles";;
		"44")
			grade="IDP";;
		"43")
			grade="MecanicaIndustrial";;
		"13")
			grade="Aquitectura";;
		"12")
			grade="ConstruccionCivil";;
   		*)
			grade=0;;
	esac
	if [[ ! -d $grade ]] && [[ $grade != "0" ]]; then
			mkdir -p $1/$grade
	fi
}
# function to move file to folder
function moveFile {
	`mv $1 $2"/"$3"/"$1`
	log $1 $2 $3 $4
}
# ---------------- MAIN -------------------
cd $1
for FILE in `ls`; do
	name=`stat -c %n $FILE`	# filename
	tam=`stat -c %s $FILE`	# size
	# calculating size of file
	size=`expr $tam \/ 1024`
	if (( ("$tam" % 1024) != 0 )); then
		size=`expr $size + 1`
	fi
	length=$(echo $name | wc -m) # length of 
	# check length of filename -> ROL < 2010
	if [ $length -eq 15 ]; then
		year=${name:0:2}
		grad=${name:2:2}
		# extract first digit
		first=${year:0:1}
		second=${year:1:1}
		year="${first}00${second}"
	else
		year=${name:0:4}
		grad=${name:4:2}
	fi
	# create folders to years and 
	if [ $year -ge "2000" ] && [ $year -le "2011" ]; then
		checkYear $year # return $folder
		checkGrade $year $grad # return $grade
		if [ $grade != 0 ]; then
			moveFile $name $year $grade $size
		fi
	fi
done