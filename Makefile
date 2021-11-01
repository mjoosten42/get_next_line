SRC = main.c get_next_line.c get_next_line_utils.c
BONUS = main.c get_next_line_bonus.c get_next_line_utils_bonus.c

make:
	@gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 $(SRC)
	@./a.out | cat -e