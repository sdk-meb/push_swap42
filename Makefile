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

CFLAGS = -Wall -Wextra -Werror

OBJ_SRC = ft_atoi.o instruction.o push_swap.o call_instruction/call_inst.o

OBJ_LIST = list/ft_lstadd_back.o  list/ft_lstclear.o  list/ft_lstnew.o \
			list/ft_lstadd_front.o list/ft_lstlast.o

all: $(NAME)

$(NAME) : $(OBJ_LIST) $(OBJ_SRC)
	@ar -cr $(NAME) $(OBJ_SRC) $(OBJ_LIST)

clean :
	rm -rf $(OBJ_LIST) $(OBJ_SRC)

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all re clean fclean
