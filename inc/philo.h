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

//Estates
# define SLEEP "is sleeping"
# define FORK "has taken a fork"
# define THINK "is thinking"
# define EAT "is eating"
# define DIED "is dead"
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
    pthread_t monitor;
    int philo_nb;
    long time_eat;
    long time_sleep;
    long time_die;
    int meals_nb;
    bool dead_flag;
    long start_time;
    bool all_ready;
    pthread_mutex_t print;
    pthread_mutex_t dead;
    pthread_mutex_t meals;
    pthread_mutex_t time;
    pthread_mutex_t syncro;
}t_data;

// utils
long	ft_atol(const char *nptr);
long get_date_time();
void ft_usleep(int miliseconds);
bool ft_isnumber(char c);
void ft_print_state(t_philo *philo,char *state);
//void ft_print_state(t_philo *philo,char *state, int forknb);
// init
bool init_data(t_data *data, char **argv, int arc);
// threads
bool start_simulation(t_data *data);
void *philo_rutine(void *philos);
bool dead_checker(t_philo *philo);
void *monitor_rutine(void *data);
//getter & setter
long get_safe_long(pthread_mutex_t *mutex, long *var);
void set_safe_long(pthread_mutex_t *mutex, long *var, long value);
bool get_safe_bool(pthread_mutex_t *mutex, bool *boolean);
void set_safe_bool(pthread_mutex_t *mutex, bool *var,bool value);


#endif