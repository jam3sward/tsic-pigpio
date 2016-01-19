.PHONY: all install clean distclean

all: main.cpp tsic.o
	g++ -o tsic-temp main.cpp tsic.o -lrt -pthread -lpigpio -std=c++0x

tsic.o: tsic.h tsic.cpp pigpiomgr.h
	g++ -c tsic.cpp -std=c++0x

install: all
	cp tsic-temp /usr/local/bin

clean:
	rm -rf *.o tsic-temp

distclean: clean
	rm -rf /usr/local/bin/tsic-temp
