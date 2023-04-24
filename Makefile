#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME	=	pipex
LIBFT	= 	libft.a
LDIR	=	libft/

# Color
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
WHITE	=	\033[0m

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	pipex.c\
			pipex_utils.c\
			ft_pipex_split.c\


OBJS	=	$(SRCS:.c=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling . . .$(WHITE)\n"
	@printf "$(BLUE)LIBFT: $(WHITE)"; cd LIBFT/ && make && cd ..
	@$(CC) $(CFLAGS) $(SRCS) $(LDIR)$(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "$(BLUE)Create objects$(WHITE)"

# Removes objects
clean:
	@$(RM) $(OBJS)
	@cd LIBFT/ && make clean && cd ..
	@echo "$(RED)Removes objects$(WHITE)"
# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LDIR)$(LIBFT)
	@echo "$(RED)Removes executables$(WHITE)"

# Removes objects and executables and remakes
re: fclean all
	@echo "\n$(GREEN)Remake complete$(WHITE)"