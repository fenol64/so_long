NAME=so_long
NAME_BONUS=so_long_bonus

RAW_SRCS= $(shell find src)
SRCS = $(filter %.c, $(RAW_SRCS))

OBJS = $(SRCS:.c=.o)

BONUS_ENABLED=0
COMPILER = cc
FLAGS = -Wall -Wextra -Werror

.c.o:
	$(COMPILER) -D BONUS_ENABLED=$(BONUS_ENABLED) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libs/libft
	make -C libs/mlx
	$(COMPILER) $(FLAGS) $(OBJS) libs/libft/libft.a -o $(NAME) -Llibs/mlx -lmlx -lX11 -lXext
	@ echo "compile complete\n"


$(NAME_BONUS): $(OBJS)
	make -C libs/libft
	make -C libs/mlx
	$(COMPILER) $(FLAGS) $(OBJS) libs/libft/libft.a -o $(NAME)_bonus -Llibs/mlx -lmlx -lX11 -lXext
	@ echo "compile complete\n"

bonus:	override BONUS_ENABLED = 1
bonus:	$(NAME_BONUS)

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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/$(if $(MAP),$(MAP),map.ber)
	@ echo "compile complete\n"
