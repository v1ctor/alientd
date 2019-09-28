TARGET = alientd
# LIBS = `sdl-config --libs` -lSDL_ttf -lSDL_image
# CFLAGS = -O2 -ggdb `sdl-config --cflags`
LIBS = -framework SDL -framework SDL_Image
HEADERS = -I/Library/Frameworks/SDL.framework/Headers
CC = g++


all:
	$(CC) $(CFLAGS) -c go.cpp -o go.o
	$(CC) $(CFLAGS) -c tools.cpp -o tools.o
	$(CC) $(CFLAGS) -c enemy.cpp -o enemy.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -c tower.cpp -o tower.o
	$(CC) $(CFLAGS) -c pathfinder.cpp -o pathfinder.o
	$(CC) $(CFLAGS) -c spisok.cpp -o spisok.o
	$(CC) -o $(TARGET)  pathfinder.o enemy.o tower.o tools.o go.o main.o $(LIBS) $(HEADERS)
	#strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
