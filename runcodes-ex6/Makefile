exec = exec_name
lib = bignumber
main = main
dir = src

all: $(lib).o $(main).o
	gcc -o $(exec) $(main).o $(lib).o

$(main).o: $(dir)/$(main).c
	gcc -c $(dir)/$(main).c -Wall

$(lib).o: $(dir)/$(lib).c $(dir)/$(lib).h
	gcc -c $(dir)/$(lib).c -Wall

clean:
	rm -rf *.o

run:
	./$(exec)
