CC		= g++
CFLAGS	= -std=c++11 -Wall
OBJ 	= main.o card.o game_state.o
DEPS	= card.h game_state.h
TARGET	= test

%.o : %.cpp
	$(CC) -c $< $(CFLAGS)
	
$(TARGET) : $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm -f $(OBJ) $(TARGET)
