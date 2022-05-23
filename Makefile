##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE file.
##

PROJECT_FILES = src/*.c

LIBRARY_FILES = lib/*.c

BINARY_FILE = navy

all:
	gcc $(PROJECT_FILES) $(LIBRARY_FILES) -o $(BINARY_FILE)

clean:
	rm -f $(BINARY_FILE)

fclean: clean

re: fclean all
