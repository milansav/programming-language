

all : build

build : main.o dynarr.o lexer.o parser.o
	gcc main.o dynarr.o lexer.o parser.o -o quark.out

remake : clear clean build

main.o : main.c
	gcc -c main.c

dynarr.o : ./dynarr/dynarr.c 
	gcc -c ./dynarr/dynarr.c 

lexer.o : ./lexer/lexer.c 
	gcc -c ./lexer/lexer.c 

parser.o : ./parser/parser.c 
	gcc -c ./parser/parser.c

clean:
	if test -f "*.o"; then rm *.o; fi
	if test -f "quark.out"; then rm quark.out; fi

clear:
	clear
