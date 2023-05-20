#!/bin/bash

for file in *.cpp; do
	dir="${file:0:3}"
	if [[ ! -d $dir ]]; then
		echo Creating new directory $dir
		mkdir $dir
	fi
	echo Moving $file to directory $dir
	mv $file $dir/$file
done
