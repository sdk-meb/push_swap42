# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:40:35 by mes-sadk          #+#    #+#              #
#    Updated: 2022/02/15 17:56:05 by mes-sadk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
check= checker.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_SRC = ft_atoi.o ft_split.o instruction.o push_swap.o call_instruction/call_inst.o

OBJ_LIST = list/ft_lstadd_back.o  list/ft_lstclear.o  list/ft_lstnew.o \
			list/ft_lstadd_front.o list/ft_lstlast.o  list/ft_lstsize.o

OBJ_MATH = math/math.o

OBJ_CHECKER =  my_checker/check.o	 my_checker/f_atoi.o	 my_checker/instru.o \
				 my_checker/my_checker_sort.o	 my_checker/f_split.o	my_checker/stack.o	\
				 my_checker/list/f_lstadd_back.o   my_checker/list/f_lstadd_front.o \
				 my_checker/list/f_lstclear.o      my_checker/list/f_lstlast.o \
				 my_checker/list/f_lstnew.o        my_checker/list/f_lstsize.o

all: $(NAME)

$(NAME) : $(OBJ_LIST) $(OBJ_SRC) $(OBJ_MATH)
	@ar -r $(NAME) $(OBJ_SRC) $(OBJ_LIST) $(OBJ_MATH)

bonus: $(NAME) ${OBJ_CHECKER}
	@ar -r ${check} ${OBJ_CHECKER}

clean :
	@rm -rf $(OBJ_LIST) $(OBJ_SRC) $(OBJ_MATH) ${OBJ_CHECKER}

fclean : clean
	@rm -rf ${NAME} ${check}

re : fclean all

.PHONY : all re clean fclean
