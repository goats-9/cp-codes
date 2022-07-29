#!/bin/bash

if [[ ! ${PWD} == '/home/gautam/Documents/repos/uva-codes' ]]; then
	cd ~/Documents/repos/uva-codes
fi

for file in ./*/*.txt ; do
	rm $file
done

for file in ./*/*.out ; do
	rm $file
done
