#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

#define RULES \
    "Error\n" \
    "1. The number of arguments must be 4 or 5.\n" \
    "2. Only positive integers are allowed.\n" \
    "3. The number of philosophers must be greater than 1.\n"\
    "4. The number of meals must be greater than 0.\n"

typedef enum
{
    FALSE,
    TRUE
}bool;

typedef struct s_forks
{
    int fork_nb;
    pthread_mutex_t fork;
}t_forks;

typedef struct c_philo
{
    pthread_t thread_id;
    int philo_id;
    int meals;
    long last_meal;
    //bool is_full;
    t_forks *right_fork;
    t_forks *left_fork;
    struct s_data *data; 
}t_philo;

typedef struct s_data
{
    t_philo *philo;
    t_forks *forks;
    int philo_nb;
    long time_eat;
    long time_sleep;
    long time_die;
    int meals_nb;
    bool dead_flag;
    size_t start_time;
    pthread_mutex_t print;
    pthread_mutex_t dead;
    pthread_mutex_t meals;
}t_data;

// utils
long	ft_atol(const char *nptr);
long get_date_time();
void ft_usleep(int miliseconds);
bool ft_isnumber(char c);
// init
bool init_data(t_data *data, char **argv, int arc);


#endif