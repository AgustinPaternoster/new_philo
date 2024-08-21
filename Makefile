CC = gcc
FLAGS = -Wall -Werror -Wextra -g -I /inc/ -fsanitize=thread
#FLAGS = -I /inc/ -fsanitize=leak
CFILES = main.c\
		utils.c\
		init.c
HEADER = inc/philo.h
NAME = philo
DIRF = src/
SRC_FILES = $(addprefix $(DIRF),$(CFILES))

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SRC_FILES) -g -o $(NAME)

library:
	@ make -C libft
	@ make -C printf


clean:


fclean:


re: fclean all

