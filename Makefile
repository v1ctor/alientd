TARGET = main
LIBS = -framework SDL -framework SDL_Image
HEADERS = -I/Library/Frameworks/SDL.framework/Headers
CC = g++


all:
	$(CC) -c go.cpp -o go.o
	$(CC) -c tools.cpp -o tools.o
	$(CC) -c enemy.cpp -o enemy.o
	$(CC) -c main.cpp -o main.o
	$(CC) -o $(TARGET) enemy.o tools.o go.o main.o $(LIBS) $(HEADERS)
clean:
	rm *.o 
	rm $(TARGET)
