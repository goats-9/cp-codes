#!/bin/bash

for file in *.cpp; do
	dir="${file:0:3}"
	echo Moving to directory $dir
	if [[ ! -d $dir ]]; then
		echo Creating new directory $dir
		mkdir $dir
	fi
	mv $file $dir/$file
done
