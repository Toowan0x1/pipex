NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC =	./pipex.c \
		./utils/file_opener.c \
		./utils/error_manager.c \
		./funcs/split.c   ./funcs/strichr.c ./funcs/strchr.c \
		./funcs/strlen.c ./funcs/substr.c ./funcs/strdup_sep.c \
		./funcs/strncmp.c ./funcs/putstr_fd.c ./funcs/strdup.c \
		./funcs/strjoin.c

OBJ = $(SRC:c=o)

SRCB =	./bonus.c \
		./gnl/gnl.c \
		./utils/file_opener.c \
		./utils/error_manager.c \
		./utils/heredoc_utils.c \
		./funcs/split.c   ./funcs/strichr.c ./funcs/strchr.c \
		./funcs/strlen.c ./funcs/substr.c ./funcs/strdup_sep.c \
		./funcs/strncmp.c ./funcs/putstr_fd.c ./funcs/strdup.c \
		./funcs/strjoin.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean:
	@rm -f $(OBJ) $(OBJB)
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB)
