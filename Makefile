# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 15:47:40 by nide-mel          #+#    #+#              #
#    Updated: 2021/07/23 11:53:28 by nide-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

CFLAGS	=	-Wall -Wextra -Werror -g

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=$(DIR_OBJS)%.o)

AR = ar -rcs

DIR_OBJS = obj/

SRCS	=	ft_conv_int.c ft_itoa_base.c ft_printf_utils.c ft_printf.c

SRCS_BONUS	=	ft_conv_int.c ft_itoa_base.c ft_printf_utils.c ft_printf.c

all:		$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)
		@echo "$(NAME) created and indexed"

$(DIR_OBJS)%.o: %.c
	gcc $(CFLAGS) -include $(HEADER) -c $< -o $@

$(OBJS):	| $(DIR_OBJS)
$(OBJS_BONUS):	| $(DIR_OBJS)
$(DIR_OBJS):
			mkdir $(DIR_OBJS)

clean:
			rm -rf $(DIR_OBJS)
			@echo "##### Removed lib object files #####"

fclean:		clean
			rm -f $(NAME)
			@echo "##### Removed $(NAME) #####"

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
