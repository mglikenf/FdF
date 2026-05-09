# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 18:38:13 by mglikenf          #+#    #+#              #
#    Updated: 2024/10/10 16:02:11 by mglikenf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft
LIBNAME = libft.a
LIBFT = $(LIBDIR)/$(LIBNAME)
MLXDIR = minilibx-linux
MLXLIB = $(MLXDIR)/libmlx.a
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
MATHFLAG = -lm

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

SRCS =	fdf.c \
		utils.c \
		mlx.c \
		parse.c \
		project.c \
		draw.c \
		purge_gnl.c \

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(MLXLIB):
	@$(MAKE) -C $(MLXDIR)
	@echo "$(GREEN)[minilibx]	built$(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(MLXLIB)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(MATHFLAG) -L$(LIBDIR) -l:libft.a -o $(NAME)
	@echo "$(GREEN)[fdf]		compiled successfully$(RESET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Iminilibx-linux -I$(LIBDIR) -I$(GNL_DIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) clean
	@echo "$(YELLOW)[clean]		objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean
	@$(MAKE) -C $(MLXLIB) clean
	@echo "$(YELLOW)[fclean]	binaries removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
