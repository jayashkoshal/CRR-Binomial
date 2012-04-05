## I use g++ but any other compiler can be used
CC = g++

## compiler options
CFLAGS = -c -Wall

## set linker library flags
LDFLAGS =

### add all the source file here
SOURCES = americanontree.cpp europeanontree.cpp payoffbridge.cpp \
productontree.cpp binomialtree.cpp maintree.cpp payoff.cpp

## the object will be named after the cpp file
OBJECTS = $(SOURCES:.cpp=.o)

## the name of the executable
EXECUTABLE = tree_output

## doxygen documentation will be generated autmatically
DOXYGEN = doxygen
Doxyfile = option_pricing 

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

	$(DOXYGEN) option_pricing

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

## clean the object files
clean : 
	rm $(OBJECTS)
