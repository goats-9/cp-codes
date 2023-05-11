#!/bin/bash

n=${#1}
p=''

if [[ $n == 0 ]]; then
	echo Problem number not supplied
	exit 1
fi

for (( i = 0 ; i < 5-$n ; i++ ))
do
	p=0$p
done
dir=${p:0:3}

if [[ ! -d $dir ]]; then
	echo Creating new directory $dir
	mkdir $dir
fi

if [[ ! -e $dir/$p ]]; then
	echo Creating file $dir/$p
	cp template.cpp $dir/$p
else 
	echo $dir/$p already exists
fi
