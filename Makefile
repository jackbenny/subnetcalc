subnetcalc: subnetcalc.c
	gcc subnetcalc.c -lm -o subnetcalc

clean: subnetcalc
	rm subnetcalc
