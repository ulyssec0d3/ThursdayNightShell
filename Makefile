#############################################

NAME := minishell

#############################################

#############################################

SRC_DIR     := srcs
OBJ_DIR     := obj
SRCS        := \
	main.c          \
	print_ast.c   \
	utils/ast_utils/ft_strjoin.c     \
	utils/ast_utils/is_something.c     \
	utils/ast_utils/libft_utils.c      \
	utils/ast_utils/list_utils.c     \
	utils/structures_management/free_structures.c     \
	utils/structures_management/init_structures.c     \
	lexing/lexing_type.c     \
	lexing/lexing.c     \
	lexing/parenthesis_management.c     \
	lexing/quote_management.c     \
	lexing/utils.c     \
	parsing/parse_cmd_node.c     \
	parsing/parse_operator_node.c \
	parsing/parsing.c     \
	parsing/utils.c		\
	expand/env.c	\
	# expand/expand.c

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