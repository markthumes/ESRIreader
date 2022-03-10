CFLAGS=-Wall -Wextra -ggdb
INC=-I.
LIBS=
target=a.out
default:
	g++ -c main.cpp -o main.o $(CFLAGS) $(INC)
	g++ -c hfile.cpp -o hfile.o $(CFLAGS) $(INC)
	g++ -o $(target) main.o hfile.o $(LIBS)

clean:
	rm -f *.o $(target)
	
