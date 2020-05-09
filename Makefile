SOURCE = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SOURCE))
 
CC = g++
CFLAGS = -Wall -g -lpthread

all:$(TARGETS)
 
$(TARGETS):%:%.cpp
	$(CC) $(CFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -rf $(TARGETS)
