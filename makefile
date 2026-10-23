students: address.o date.o main.o
	g++ -g address.o date.o main.o -o students

main.o: address.h date.h main.cpp
	g++ -c -g main.cpp

address.o: address.h address.cpp
	g++ -c -g address.cpp

date.o: date.h date.cpp
	g++ -c -g date.cpp

clean:
	rm *.o
	rm students

run: students
	./students

debug: students
	gdb students

valgrind: students
	valgrind --leak-check=full ./students
