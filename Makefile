LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=main.o
NAME="Sierpinski triangle"

run: $(OBJECTS)
	g++ $(OBJECTS) -o $(NAME) $(LIBS)
	./$(NAME)

main.o: main.cpp
	g++ -c main.cpp
