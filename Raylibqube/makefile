cc = g++
SOURCES = ./src/*.cpp
LIBRARIES = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: CompileQube RunQube Clean

CompileQube:
	$(cc) $(SOURCES) -o main $(LIBRARIES)

RunQube:
	./main

Clean:
	rm main