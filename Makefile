subnetcalc: subnetcalc.c
	gcc -Wall -pedantic subnetcalc.c -lm -o subnetcalc

clean: subnetcalc
	rm subnetcalc
