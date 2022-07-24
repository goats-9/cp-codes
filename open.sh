#!/bin/bash

dir=${1:0:4}

if [[ ! ${PWD:(-3)} == 'sts' ]]; then
	cd ..
fi

if [[ ! -d $dir ]]; then
	echo Creating new directory $dir
	mkdir $dir
fi

cp template.cpp $dir/$1.cpp
cd $dir
nvim $1.cpp
