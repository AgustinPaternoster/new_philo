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

ifeq ($(MODE), debug1)
	FLAGS += -g -fsanitize=thread
endif

ifeq ($(MODE), debug2)
	FLAGS += -g -fsanitize=leak
endif

ifeq ($(MODE), noflag)
	FLAGS = -g
endif

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SRC_FILES) -g -o $(NAME)

clean:


fclean:
	rm -rf $(NAME)

re: fclean all

