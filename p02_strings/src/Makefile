CXX = g++
CXXFLAGS = -Wall -std=c++11 

TARGET = cya-P02-strings

SOURCES = alfabeto.cc cadena.cc funciones.cc intermediario_ficheros.cc lenguaje.cc simbolo.cc cya-P02-strings.cc

OBJECTS = $(SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

cleano:
	rm -f $(OBJECTS)

.PHONY: all clean cleano