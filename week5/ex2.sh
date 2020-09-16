#!/bin/bash
if test ! -f numbers
then                                               
    echo 0 > numbers
fi

if ln numbers numbers.lock
	then
	LAST=`tail -1 numbers`
	LAST=$((LAST+1))
	echo $LAST >> numbers
	rm numbers.lock
fi
