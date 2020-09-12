subnetcalc: subnetcalc.c
	gcc -std=c99 -Wall -pedantic subnetcalc.c -lm -o subnetcalc

clean: subnetcalc
	rm subnetcalc
