# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:35:33 by tkondo            #+#    #+#              #
#    Updated: 2024/07/06 03:04:41 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCDIR = ../include
LIBDIR = ..
LIBNAME = ftprintf
LIB = libftprintf.a
CFLAGS = -I$(INCDIR) -L$(LIBDIR) -l$(LIBNAME)

SRCDIR = src
OUTDIR = bin
SRCS = $(wildcard $(SRCDIR)/*.c)
OUTS = $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.test)
NAMES = $(SRC:$(SRCDIR)/%.c=%)

all: $(OUTS)

$(OUTDIR)/%.test: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $< -o $@
	./$@
	@rm $@
