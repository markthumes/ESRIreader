CFLAGS=-Wall -Wextra -ggdb
INC=-I.
LIBS=
target=a.out
default:
	g++ -c main.cpp -o main.o $(CFLAGS) $(INC)
	g++ -c hfile.cpp -o hfile.o $(CFLAGS) $(INC)
	g++ -c ersi.cpp -o ersi.o $(CFLAGS) $(INC)
	g++ -c shpfile.cpp -o shpfile.o $(CFLAGS) $(INC)
	g++ -c shxfile.cpp -o shxfile.o $(CFLAGS) $(INC)
	g++ -c dbffile.cpp -o dbffile.o $(CFLAGS) $(INC)
	g++ -o $(target) main.o hfile.o ersi.o shpfile.o shxfile.o dbffile.o $(LIBS)

clean:
	rm -f *.o $(target)
	
