NAME=so_long

RAW_SRCS= $(shell find src)
SRCS = $(filter %.c, $(RAW_SRCS))

OBJS = $(SRCS:.c=.o)

COMPILER = cc
FLAGS = -Wall -Wextra -Werror

.c.o:
	$(COMPILER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libs/libft
	make -C libs/mlx
	$(COMPILER) $(FLAGS) $(OBJS) libs/libft/libft.a -o $(NAME) -Llibs/mlx -lmlx -lX11 -lXext -D BONUS_ENABLED=0
	make clean
	@ echo "compile complete\n"

bonus: $(OBJS)
	make -C libs/libft
	make -C libs/mlx
	$(COMPILER) $(FLAGS) $(OBJS) libs/libft/libft.a -o $(NAME)_bonus -Llibs/mlx -lmlx -lX11 -lXext -D BONUS_ENABLED=1
	make clean
	@ echo "compile complete\n"

clean:
	rm -f $(OBJS)
	make clean -C libs/libft
	make clean -C libs/mlx

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	make fclean -C libs/libft

re:	fclean all

val: $(OBJS)
	make -C libs/libft
	make -C libs/mlx
	$(COMPILER) $(FLAGS) $(OBJS) libs/libft/libft.a -o $(NAME) -Llibs/mlx -lmlx -lX11 -lXext -D BONUS_ENABLED=0 -g
	make clean
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map.ber
	@ echo "compile complete\n"
