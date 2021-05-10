# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max <max@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 17:05:38 by max               #+#    #+#              #
#    Updated: 2021/05/01 21:42:45 by max              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -framework OpenGL -framework AppKit

NAME = cub3D

SRCS	=	parse.c \
		parse2.c \
		parse3.c \
		parse4.c \
		raycast_sprites.c \
		raycast_wall.c \
		raycast_wall2.c \
		raycast_floor.c \
		sprites.c \
		bmp.c \
		main.c \
		init.c \
		tex.c \
		keyboard.c \
		errors.c \
		map.c \
		utils.c \
		gnl/get_next_line.c

OBJSRCS = $(SRCS:.c=.o) 

CFLAGS 	= -Wall -Wextra -Werror -I. -g

$(NAME) : $(OBJSRCS)
	@rm -rf Cub3D
	@$(MAKE) bonus -C ./libft
	@$(MAKE) -C ./mlx
	@gcc  $(OBJSRCS) $(CFLAGS)  $(MLX) ./libft/libft.a ./mlx/libmlx.a -o $(NAME)

all : $(NAME)

.c.o:
		gcc ${CFLAGS} -g -c $< -o ${<:.c=.o}

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx

fclean : clean
	rm -rf $(NAME)
	rm -rf screenshot.bmp

re : fclean all

bonus : $(NAME)