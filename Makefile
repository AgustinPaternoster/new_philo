CC = gcc
FLAGS = -Wall -Werror -Wextra  -I /inc/ 
MODE = none

CFILES = main.c\
		utils.c\
		init.c\
		philo.c\
		threads.c\
		utils_2.c\
		monitor.c\
		utils_3.c
HEADER = inc/philo.h
NAME = philo
DIRF = src/
SRC_FILES = $(addprefix $(DIRF),$(CFILES))

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SRC_FILES) -g -o $(NAME)

clean:


fclean:
	rm -rf $(NAME)

re: fclean all

