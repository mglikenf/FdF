# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mglikenf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 17:52:47 by mglikenf          #+#    #+#              #
#    Updated: 2023/11/20 20:50:28 by mglikenf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
GNLDIR = get_next_line

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_strtrim.c \
		ft_split.c \
		$(GNLDIR)/get_next_line_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)[libft] built$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(GNLDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)[libft] objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)[libft] cleaned$(RESET)"

re: fclean all

so:
	@$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) -c
	@$(CC) -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re so