TARGET = main
LIBS = `sdl-config --libs`
CFLAGS = -O2 -ggdb `sdl-config --cflags`
CC = g++


all:
	$(CC) $(CFLAGS) -c go.cpp -o go.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) -o $(TARGET) go.o main.o $(LIBS)
	strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
