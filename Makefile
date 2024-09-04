# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 08:09:35 by tkondo            #+#    #+#              #
#    Updated: 2024/09/04 23:06:21 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = build
INCDIR = include

# Source files
SRC_MND = \
  $(SRCDIR)/ft_printf.c\
  $(SRCDIR)/ft_vfprintf.c\
  $(SRCDIR)/ft_fwrite.c\
  $(SRCDIR)/ft_fputc.c\
  $(SRCDIR)/ft_fileno.c\

SRC_BNS = \
  $(SRCDIR)/ft_printf.c\
  $(SRCDIR)/ft_vfprintf.c\
  $(SRCDIR)/ft_fwrite.c\
  $(SRCDIR)/ft_fputc.c\
  $(SRCDIR)/ft_fileno.c\

# Object files
OBJ_MND = $(SRC_MND:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJ_BNS = $(SRC_BNS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

ifndef ADD_BONUS
  OBJ = $(OBJ_MND)
else
  OBJ = $(OBJ_BNS)
endif

# Name of the library
NAME = libftprintf.a


all: $(NAME) ## Create the Library

$(NAME): $(OBJ) ## Create the Library
	make -C libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

bonus: ## Create Bonus Library
	@make ADD_BONUS=1

$(OBJDIR)/%.o: $(SRCDIR)/%.c ## Compile Source Files
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean: ## Clean Only Object File Directory
	rm -f $(OBJ_MND) $(OBJ_BNS)
	make -C libft clean

fclean: clean ## Full Clean 
	rm -f $(NAME)
	make -C libft fclean

re: fclean all ## Re-Make

test: all ## Run Test Code
	make -C test

.PHONY: all clean fclean re test
