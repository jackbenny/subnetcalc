CC=gcc
CFLAGS=-Wall -pedantic -std=c99
LIBS=-lm
OBJS=subnetcalc.o
BINDIR=/usr/local/bin
MANDIR=/usr/share/man/man1

subnetcalc: $(OBJS)
	$(CC) -o subnetcalc $(OBJS) $(LIBS)

subnetcalc: subnetcalc.c

install: subnetcalc subnetcalc.1
	gzip -c subnetcalc.1 > subnetcalc.1.gz
	install -g root -o root -m 0644 subnetcalc.1.gz $(MANDIR)/
	install -g root -o root -m 0755 subnetcalc $(BINDIR)/

uninstall:
	rm $(MANDIR)/subnetcalc.1.gz
	rm $(BINDIR)/subnetcalc

clean:
	rm subnetcalc $(OBJS) subnetcalc.1.gz
