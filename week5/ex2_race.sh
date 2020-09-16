#!/bin/bash 
                                                                      
if test ! -f numbers
then                                                
    echo 0 > numbers
fi

for i in `seq 1 1`;
do
	LAST=`tail -1 numbers`
	LAST=$((LAST+1))

	echo $LAST >> numbers
done
