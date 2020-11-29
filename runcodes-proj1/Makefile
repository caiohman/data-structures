exec = exec_name
lib = dictionary
main = main
dir = src

all: $(lib).o $(main).o
	gcc -g -o $(exec) $(main).o $(lib).o

$(main).o: $(dir)/$(main).c
	gcc -c $(dir)/$(main).c -Wall -g

$(lib).o: $(dir)/$(lib).c $(dir)/$(lib).h
	gcc -c $(dir)/$(lib).c -Wall -g

clean:
	rm -rf *.o

run:
	./$(exec)
