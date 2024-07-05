# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 08:09:35 by tkondo            #+#    #+#              #
#    Updated: 2024/07/06 03:05:12 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = build
INCDIR = include

# Source files
SRC_MND = \
  $(SRCDIR)/ft_printf.c\
  $(SRCDIR)/ft_vfprintf.c\
  $(SRCDIR)/ft_fwrite.c\

SRC_BNS = \
  $(SRCDIR)/ft_printf.c\
  $(SRCDIR)/ft_vfprintf.c\
  $(SRCDIR)/ft_fwrite.c\

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
	ar rcs $(NAME) $(OBJ)

bonus: ## Create Bonus Library
	@make ADD_BONUS=1

$(OBJDIR)/%.o: $(SRCDIR)/%.c ## Compile Source Files
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean: ## Clean Only Object File Directory
	rm -f $(OBJ_MND) $(OBJ_BNS)

fclean: clean ## Full Clean 
	rm -f $(NAME)

re: fclean all ## Re-Make

test: all ## Run Test Code
	make -C test

.PHONY: all clean fclean re test
