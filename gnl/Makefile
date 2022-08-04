
PARAMENTS	= -Wall -Wextra -Werror -g

SIZE		= 1

BUFFER		= -D BUFFER_SIZE=${SIZE}

FILES		= get_next_line.h get_next_line.c get_next_line_utils.c

m:
	cc main.c ${PARAMENTS} main.c -iquote ./Mandatory/${FILES}

clean:
	rm a.out
	rm vgcore.*

run: all
	./a.out

buff:
	cc main.c -Wall -Wextra -Werror ${BUFFER} -g3 -I ${FILES}
	@./a.out

check: all
	valgrind --leak-check=full --show-leak-kinds=all ./a.out
