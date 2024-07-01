
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 13:34:40 by lucas             #+#    #+#              #
#    Updated: 2024/06/25 13:34:40 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fdf

SRCDIR      = src
OBJDIR      = obj
INCDIR      = inc

# LIBFTDIR    = $(INCDIR)/libft
# LIBFT       = $(LIBFTDIR)/libft.a

SRC         = main.c

# Conditional inclusion based on the platform
MLXDIR   = $(INCDIR)/my_minilibx-linux
INCFLAGS = -L$(LIBFTDIR) -lft -lXext -lX11 -lm


SRC         := $(addprefix $(SRCDIR)/, $(SRC))
OBJ         := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

MLX         = $(MLXDIR)/libmlx.a

CC          = gcc -g3
# CFLAGS      = -Wall -Wextra -Werror

########### COLORS ##########
RED         := "\033[1;31m"
GREEN       := "\033[1;32m"
RESET       := "\033[0m"

all: $(NAME)

$(OBJDIR):
		@mkdir -p $(OBJDIR)

-include $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile | $(OBJDIR)
		$(CC) $(CFLAGS) -MMD -I$(INCDIR) -I$(MLXDIR) -c $< -o $@

$(MLX):
		@echo $(GREEN)"\n\tCOMPILING MLX"$(RESET)
		@make -sC $(MLXDIR)
		@echo $(GREEN)"\n\tMLX COMPILED\n"$(RESET)

# $(LIBFT):
# 		@echo $(GREEN)"\n\tCOMPILING LIBFT"$(RESET)
# 		@make -sC $(LIBFTDIR)
# 		@echo $(GREEN)"\n\tLIBFT COMPILED"$(RESET)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
		@echo $(GREEN)"LINKING objects to create $(NAME)"
		$(CC) $(OBJ) $(CFLAGS) -L$(MLXDIR) -lmlx $(INCFLAGS) -o $(NAME)
		@printf $(RESET)

clean:
		@echo $(RED)"CLEANING OBJS"
		rm -f $(OBJ)
		rm -f $(OBJ:.o=.d)
		rm -rf $(OBJDIR)
		@make -sC $(MLXDIR) clean
#		@make -sC $(LIBFTDIR) clean

fclean: clean
		@echo $(RED)"CLEANING OBJS + NAME"
		rm -f $(NAME)
		rm -rf *.dSYM
#		@make -sC $(LIBFTDIR) fclean
		@echo $(RESET)

re: fclean
		@make all

.PHONY: all clean fclean re
