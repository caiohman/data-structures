exec = exec_name
lib = revision
lib2 = string_stack
main = main
dir = src

all: $(lib2).o $(lib).o $(main).o
	gcc -o $(exec) $(main).o $(lib).o $(lib2).o

$(main).o: $(dir)/$(main).c
	gcc -c $(dir)/$(main).c -Wall

$(lib).o: $(dir)/$(lib).c $(dir)/$(lib).h
	gcc -c $(dir)/$(lib).c -Wall

$(lib2).o: $(dir)/$(lib2).c $(dir)/$(lib2).h
	gcc -c $(dir)/$(lib2).c -Wall

run:
	./$(exec)

clean:
	rm -rf *.o
