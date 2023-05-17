
####### BEGINNING #######

NAME := token

####### INGREDIENTS - BUILD VARIABLES #######

PATH_LEXING := srcs/lexing
PATH_PARSING := srcs/parsing
PATH_AST_UTILS := utils/ast_utils
PATH_GNL := utils/gnl
PATH_LIST := utils/list_utils
#PATH_STRUCTURES_MANAGEMENT := utils/structures_management 

## In utils folder

# In ast_utils
SRCS += $(PATH_AST_UTILS)/ft_split.c
SRCS += $(PATH_AST_UTILS)/is_something.c
SRCS += $(PATH_AST_UTILS)/lexing_utils.c
SRCS += $(PATH_AST_UTILS)/parsing_utils.c 
SRCS += $(PATH_AST_UTILS)/utils.c

# In gnl
SRCS += $(PATH_GNL)/get_next_line.c
SRCS += $(PATH_GNL)/get_next_line_utils.c

# In list_utils
SRCS += $(PATH_LIST)/list_utils.c

# In structures_management
SRCS += utils/structures_management/free_structures.c
SRCS += utils/structures_management/init_structures.c

## In srcs folder
SRCS += srcs/main.c

# In lexing
SRCS += $(PATH_LEXING)/lexing.c
SRCS += $(PATH_LEXING)/new_token.c
SRCS += $(PATH_LEXING)/parenthesis_management.c
SRCS += $(PATH_LEXING)/quote_management.c

# In parsing
SRCS += $(PATH_PARSING)/parsing.c

####################################################

OBJS	:= $(SRCS:.c=.o)  # object files .o

CC := clang # compiler
CFLAGS := -Wall -Wextra -Werror -g3 # compiler flags
# VALGRIND := valgrind --leak-check=full -q 

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
