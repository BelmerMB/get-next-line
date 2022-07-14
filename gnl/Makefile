
PARAMENTS	= -Wall -Wextra -Werror -g3 -I

BUFFER		=  -D BUFFER_SIZE=1

FILES		= get_next_line.h get_next_line.c get_next_line_utils.c

all:
	@cc main.c ${PARAMENTS} ${FILES}

clean:
	rm a.out
	rm vgcore.*

run: all
	./a.out

buff:
	cc main.c -Wall -Wextra -Werror ${BUFFER} -g3 -I ${FILES}
	@./a.out
check: all
	valgrind --leak-check=full ./a.out
