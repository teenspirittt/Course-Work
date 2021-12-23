FLAGS = -c -Wall -Wextra -Werror

all: main.o 
	g++ main.o -o ../build/all

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o ../build/all

rebuild:
	$(MAKE) clean
	$(MAKE) all

.PHONY: clean all rebuild
