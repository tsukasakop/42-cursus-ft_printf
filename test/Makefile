# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:35:33 by tkondo            #+#    #+#              #
#    Updated: 2024/09/04 23:21:50 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCDIR = ../include
LIBDIR = ..
LIBNAME = ftprintf
LIB = ../libftprintf.a
CFLAGS = -I$(INCDIR) -L$(LIBDIR) -l$(LIBNAME) -g -fsanitize=address

SRCDIR = src
CASEDIR = case
SRCS = $(wildcard $(SRCDIR)/*.c)
NAMES = $(SRCS:$(SRCDIR)/%.c=%)
CSVS = $(wildcard $(CASEDIR)/*.csv)
CASES = $(CSVS:$(CASEDIR)/%.csv=%)

OUT = ./bin/test-printf
.PHONY = test all clean fclean re $(CASES)

test: all

all: $(CASES)

$(CASES): %: $(OUT)
	$(OUT) $(CASEDIR)/$@.csv

$(OUT): $(LIB) $(SRCS)
	$(CC) $^ -o $@ $(CFLAGS)

$(LIB):
	make -C ..

clean:

fclean: clean
	rm $(OUT) || true

re: fclean all
