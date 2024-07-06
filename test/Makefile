# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:35:33 by tkondo            #+#    #+#              #
#    Updated: 2024/07/06 13:02:48 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCDIR = ../include
LIBDIR = ..
LIBNAME = ftprintf
LIB = libftprintf.a
CFLAGS = -I$(INCDIR) -L$(LIBDIR) -l$(LIBNAME) -g -fsanitize=address

SRCDIR = src
OUTDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.c)
OUTS = $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.test)
NAMES = $(SRCS:$(SRCDIR)/%.c=%)

.PHONY = test all clean fclean re $(NAMES)

test: all
	@./test_all.sh

all: $(OUTS)

$(NAMES): %: $(OUTDIR)/%.test
	./$<

$(OUTDIR)/%.test: $(SRCDIR)/%.c $(LIBDIR)/$(LIB)
	@mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -r $(OUTDIR)

fclean: clean

re: fclean all
