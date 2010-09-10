TARGET = alientd
LIBS = `sdl-config --libs` -lSDL_ttf -lSDL_image
CFLAGS = -O2 -ggdb -pedantic `sdl-config --cflags`
CC = g++


all:
	$(CC) $(CFLAGS) -c go.cpp -o go.o
	$(CC) $(CFLAGS) -c tools.cpp -o tools.o
	$(CC) $(CFLAGS) -c enemy.cpp -o enemy.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -c tower.cpp -o tower.o
	$(CC) $(CFLAGS) -c pathfinder.cpp -o pathfinder.o
	$(CC) $(CFLAGS) -c spisok.cpp -o spisok.o
	$(CC) -o $(TARGET)  pathfinder.o spisok.o enemy.o tower.o tools.o go.o main.o $(LIBS)
	#strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
