NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTPATH = libft
LIBFT = $(LIBFTPATH)/libft.a



SRCS = main.c map_validation.c set_map.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

HEADERS = cub.h

RM = rm -f

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

.PHONY: all clean fclean re