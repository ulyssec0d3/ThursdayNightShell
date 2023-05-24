#############################################

NAME := minishell

#############################################

#############################################

SRC_DIR     := srcs
OBJ_DIR     := obj
SRCS        := \
	main.c          \
	utils/ast_utils/ft_split.c     \
	utils/ast_utils/is_something.c     \
	utils/ast_utils/lexing_utils.c     \
	utils/ast_utils/parsing_utils.c      \
	utils/ast_utils/utils.c     \
	utils/list_utils/list_utils.c     \
	utils/structures_management/free_structures.c     \
	utils/structures_management/init_structures.c     \
	lexing/lexing.c     \
	lexing/new_token.c     \
	lexing/parenthesis_management.c     \
	lexing/quote_management.c     \
	parsing/parsing.c     \

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g3
CPPFLAGS    := -I include

#############################################

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#############################################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#############################################

.PHONY: clean fclean re

.SILENT:

#############################################