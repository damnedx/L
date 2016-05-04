FLAGS= -Wall -Werror -g
OBJ= obj/automate.o obj/L.o obj/util.o


main: $(OBJ)
	gcc -o bin/L $(OBJ) $(FLAGS)

obj/L.o: src/main.c include/automate.h
	gcc -c src/main.c -o $@ -g

obj/automate.o: src/automate.c include/automate.h
	gcc -c src/automate.c -o $@ -g

obj/util.o: src/util.c include/util.h
	gcc -c src/util.c -o $@ -g

clean:
	rm obj/*.o bin/L
