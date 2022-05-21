#!/bin/bash

for file in *.cpp; do
	x=${#file}
	if [[ $x == 8 ]]; then
		new_file=${file:0:1}00${file:1}
		mv $file $new_file
		file=$new_file
	elif [[ $x == 9 ]]; then
		new_file=${file:0:1}0${file:1}
		mv $file $new_file
		file=$new_file
	fi
	dir="${file:1:3}"
	echo Moving to directory $dir
	if [[ ! -d $dir ]]; then
		echo Creating new directory $dir
		mkdir $dir
	fi
	mv $file $dir/$file
done
