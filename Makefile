TARGET = main
LIBS = `sdl-config --libs`
CFLAGS = -O3 `sdl-config --cflags`
CC = g++


all:
	$(CC) $(CFLAGS) -c go.cpp -o go.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) -o $(TARGET) go.o main.o $(LIBS)
	#$(CC) $(CFLAGS) -c GameObj.cpp -o GameObj.o
	#$(CC) -o $(TARGET) GameObj.o $(LIBS)  
	strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
