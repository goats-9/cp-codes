#!/bin/bash

n=${#1}
p=''

for (( i = 0 ; i < 5-$n ; i++ ))
do
	p=0$p
done
p=p$p$1.cpp
dir=${p:1:3}

if [[ ! ${PWD:(-3)} == 'des' ]]; then
	cd ~/Documents/repos/uva-codes
fi

if [[ ! -d $dir ]]; then
	echo Creating new directory $dir
	mkdir $dir
fi

if [[ ! -e $dir/$p ]]; then
	echo Creating file $dir/$p
	cp template.cpp $dir/$p
	cd $dir
	nvim $p
else 
	echo $dir/$p already exists
	cd $dir
	nvim $p
fi
