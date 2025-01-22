# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 17:42:00 by dmusulas          #+#    #+#              #
#    Updated: 2025/01/22 16:43:11 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
CC           = cc
CFLAGS       = -Wall -Wextra -Werror -g -Iinclude -Isrc 
NAME         = philo 
MAKE_LIB     = make -C
RM			 = rm -rf

# Sources
VPATH        = src:include
INCLUDES     = philo.h
PHILO_SRCS  = checker.c\
			  eat_pray_love.c\
			  forks.c\
			  free.c\
			  getters.c\
			  getters_time.c\
			  init.c\
			  io.c\
			  main.c\
			  routines.c\
			  setters.c\
			  threads.c\
			  time.c\
			  utils.c
PHILO_OBJS = $(PHILO_SRCS:%.c=obj/%.o)
PHILO_DEPS = $(PHILO_OBJS:%.o=%.d)

all: $(NAME)

$(NAME): $(PHILO_OBJS)
	$(CC) $(CFLAGS) $(PHILO_OBJS) -o $@


$(PHILO_OBJS): obj/%.o : src/%.c
				@mkdir -p obj
				$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

-include $(PHILO_DEPS)

.PHONY: clean fclean all re
