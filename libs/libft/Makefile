NAME = libft.a

RAW_SRCS= $(shell find .)
SRCS = $(filter %.c, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

COMPILER = cc -Wall -Wextra -Werror -I ./includes

.c.o:
	$(COMPILER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	@ echo "compile complete\n"

clean:
	rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: clean fclean $(NAME)


