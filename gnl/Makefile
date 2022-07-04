
PARAMENTS	= -Wall -Wextra -Werror -g -I

FILES		= get_next_line.h get_next_line.c get_next_line_utils.c

all:
	cc main.c ${PARAMENTS} ${FILES}

clean:
	rm a.out

run: all
	./a.out

check: all
	valgrind --leak-check=full ./a.out
