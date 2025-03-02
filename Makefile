NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

SRC_SERVER = server.c \

SRC_CLIENT = client.c \

SRC_SERVER_BONUS = server_bonus.c \

SRC_CLIENT_BONUS = client_bonus.c \

SRC = utils/printf/ft_printf.c \
		utils/printf/ft_printf_utils.c \
		utils/ft_atoi.c

OBJS_SERVER = $(SRC_SERVER:.c=.o)

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

OBJS = $(SRC:.c=.o)

CC = cc
 
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(OBJS) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(OBJS) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(OBJS) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(OBJS) -o $(NAME_CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(OBJS)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus