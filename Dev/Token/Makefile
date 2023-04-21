
####### BEGINNING #######

NAME := token

####### INGREDIENTS - BUILD VARIABLES #######

PATH_GNL := utils/gnl
PATH_LIST := utils/list_utils
PATH_SRCS := srcs
PATH_TOKEN_UTILS := utils/token_utils

# source files .c
# IN GNL
SRC += $(PATH_GNL)/get_next_line.c
SRC += $(PATH_GNL)/get_next_line_utils.c

# IN LIST UTILS
SRCS += $(PATH_LIST)/list_utils.c

# IN SRCS
SRCS += $(PATH_SRCS)/lexing.c
SRCS += $(PATH_SRCS)/main.c
SRCS += $(PATH_SRCS)/parenthesis_management.c
SRCS += $(PATH_SRCS)/quote_management.c
SRCS += $(PATH_SRCS)/token_structure_management.c

# IN TOKEN UTILS
SRCS += $(PATH_TOKEN_UTILS)/ft_split.c
SRCS += $(PATH_TOKEN_UTILS)/parsing_utils.c 
SRCS += $(PATH_TOKEN_UTILS)/lexing_utils.c

OBJS	:= $(SRCS:.c=.o)  # object files .o

CC := clang # compiler
CFLAGS := -Wall -Wextra -Werror -g3 # compiler flags

####### USTENSILS - SHELL COMMANDS #######

RM := rm -f # force remove
MAKEFLAGS += --no-print-directory # make flags

####### RECIPES - BUILD EXTRA RULES #######

all: $(NAME) # default goal

$(NAME): $(OBJS) # linking.o -> binary = .a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: # remove .o
	$(RM) $(OBJS)

fclean : clean #remove.o + binary .a
	$(RM) $(NAME)

re: # remake default goal
	$(MAKE) fclean
	$(MAKE) all

####### SPEC - SPECIAL TARGETS  #######

.PHONY: all clean fclean re

.SILENT:
