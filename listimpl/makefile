CC = gcc
FLAGS := -g -pthread -Wpedantic -Wall -Werror -pedantic-errors -std=c11
OUT = bin_kompilation_success

SRC = $(wildcard *.c)
INC = $(wildcard *.h)

$(OUT): $(SRC) $(INC)
	$(CC) $(FLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)

test: $(OUT)
	./$(OUT)
	valgrind -q --leak-check=full ./$(OUT) 

full: $(OUT) test
	cat file_1.txt
	./$(OUT) file_1.txt
	cat file_2.txt
	./$(OUT) file_2.txt
	cat file_3.txt
	./$(OUT) file_3.txt
	cat file_all.txt
	./$(OUT) file_all.txt

