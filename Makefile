NAME=so_long

RAW_SRCS= $(shell find src)
SRCS = $(filter %.c, $(RAW_SRCS))

OBJS = $(SRCS:.c=.o)

COMPILER = clang -Wall -Wextra -Werror

.c.o:
	$(COMPILER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libs/libft
	make -C libs/mlx
	$(COMPILER) $(OBJS) libs/libft/libft.a -o $(NAME) -Llibs/mlx -lmlx -lX11 -lXext
	make clean
	@ echo "compile complete\n"

clean:
	rm -f $(OBJS)
	make clean -C libs/libft
	make clean -C libs/mlx

fclean:	clean
	rm -f $(NAME)
	make fclean -C libs/libft

re:	fclean all

e: re
	./$(NAME)

em: re
	./$(NAME) maps/large_map.ber

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/min_map.ber

norm:
	norminette src libs/libft