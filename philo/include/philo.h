/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:44:22 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 18:49:25 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H 
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

# define MSG_STATUS_TAKE "has taken a fork"
# define MSG_STATUS_EAT "is eating"
# define MSG_STATUS_THINK "is thinking"
# define MSG_STATUS_SLEEP "is sleeping"
# define MSG_STATUS_DIE "died"
# define SLEEP_BUFFER 50

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_philo_state;

typedef enum e_fork
{
	RIGHT = 0,
	LEFT = 1,
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	t_philo_state	state;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_meals_eaten;
	pthread_mutex_t	mut_last_eat_time;
	time_t			last_eat_time;
	struct s_params	*params;
}					t_philo;

typedef struct s_params
{
	bool			run;
	int				num_of_philos;
	int				num_times_to_eat;
	int				num_of_full_philos;
	time_t			time_start;
	time_t			time_eat;
	time_t			time_die;
	time_t			time_sleep;
	pthread_mutex_t	mut_run;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_num_of_philos;
	pthread_mutex_t	mut_time_start;
	pthread_mutex_t	mut_time_eat;
	pthread_mutex_t	mut_time_die;
	pthread_mutex_t	mut_time_sleep;
	pthread_mutex_t	*forks;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_threads;
	t_philo			*philos;
}					t_params;

// INIT
int				init_program(t_params *params, int argc, char **argv);
int				validate_input(char *argv[]);

// TIME
time_t			get_time(void);
void			ft_usleep(time_t time_to_sleep);

// SETTERS
void			set_philo_state(t_philo *philo, t_philo_state state);
void			set_run(t_params *params, bool set_to);
void			set_all_states(t_philo *philo, t_philo_state state);
void			set_last_eat_time(t_philo *philo);
void			set_meals_eaten(t_philo *philo);

// GETTERS 
bool			get_run(t_params *params);
int				get_num_of_philos(t_params *params);
t_philo_state	get_philo_state(t_philo *philo);
int				get_meals_eaten(t_philo *philo);

time_t			get_time_param(pthread_mutex_t *mutex, time_t *field);
time_t			get_time_die(t_params *params);
time_t			get_time_sleep(t_params *params);
time_t			get_time_eat(t_params *params);
time_t			get_last_eat_time(t_philo *philo);
time_t			get_time_start(t_params *params);

// CHECKER
bool			is_philo_full(t_philo *philo);
bool			is_philo_dead(t_philo *philo);

// THREADS
int				run_threads(t_params *params);
int				join_threads(t_params *params);

// FORKS
int				take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);

// EAT PRAY LOVE aka what else to do huh

int				_eat(t_philo *philo);
int				_sleep(t_philo *philo);
int				_think(t_philo *philo);

// ROUTINES
void			*routine_main(void *philo_p);
void			*routine_check_full(void *params_p);
void			*routine_check_dead(void *params_p);

// UTILS
void			help_msg(char *err);
void			print_msg(t_params *params, int id, char *msg);
long			ft_atoi(const char *nptr);
void			free_params(t_params *params);
#endif
