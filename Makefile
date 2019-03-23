# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:29:57 by aljacque          #+#    #+#              #
#    Updated: 2019/03/23 22:06:00 by coremart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
NAME = ft_push_swap
FLAGS = -Werror -Wall -Wextra

### INCLUDES ###
LIB = libft
LIBH = $(LIB)/include
HDIR = headers
LIBA = $(LIB)/libft.a

### SOURCES ###
SDIR = sources
_SRCS = main.c get_lis.c parsing.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRCS))

### OBJECTS ####
ODIR = objects
_OBJ = $(_SRCS:.c=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

### RULES ###
all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc -g -o $(NAME) $(LIBA) $(OBJ) $(FLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	gcc $(FLAGS) -g -o $@ -c $^ -I $(HDIR) -I $(LIBH)

asan :
	make -C $(LIB)
	gcc -g -fsanitize=address -o $(NAME) $(LIBA) $(SDIR)/*.c $(FLAGS) -I $(HDIR) -I $(LIBH)
	$(MAKE) clean

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
