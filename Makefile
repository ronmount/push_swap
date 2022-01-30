PUSH_SWAP	= push_swap
CHECKER		= checker

PS_SRCS = ps_src/basic_operations.c \
		  ps_src/big_sort.c \
		  ps_src/push_swap.c \
		  ps_src/small_sort.c \
		  ps_src/stack_operations_1.c \
		  ps_src/stack_operations_2.c \
		  ps_src/stack_operations_3.c \
		  ps_src/stacks_utils_1.c \
		  ps_src/stacks_utils_2.c \
		  ps_src/utils_1.c \
		  ps_src/utils_2.c \
		  ps_src/validators.c
PS_OBJS = $(PS_SRCS:.c=.o)


C_SRCS	= c_src/checker.c \
	      gnl/get_next_line.c \
	      gnl/get_next_line_utils.c \
	      ps_src/basic_operations.c \
          ps_src/big_sort.c \
          ps_src/small_sort.c \
          ps_src/stack_operations_1.c \
          ps_src/stack_operations_2.c \
          ps_src/stack_operations_3.c \
          ps_src/stacks_utils_1.c \
          ps_src/stacks_utils_2.c \
          ps_src/utils_1.c \
          ps_src/utils_2.c \
          ps_src/validators.c
C_OBJS = $(C_SRCS:.c=.o)

PS_HEADER		= push_swap.h
GNL_HEADER		= get_next_line.h

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I include

%.o:%.c	$(PS_HEADER) $(GNL_HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@


all: $(PUSH_SWAP)

$(PUSH_SWAP) : $(PS_OBJS)
	@$(CC) $(CFLAGS) $(PS_OBJS) -o $(PUSH_SWAP)
	@echo "push_swap is done"

bonus: $(CHECKER)

$(CHECKER) : $(C_OBJS)
	@$(CC) $(CFLAGS) $(C_OBJS) -o $(CHECKER)
	@echo "checker is done"


clean:
		@$(RM) $(PS_OBJS) $(C_OBJS)
		@echo "clean is done"

fclean: clean
		@$(RM) $(PUSH_SWAP) $(CHECKER)
		@echo "fclean is done"

re: fclean all

.PHONY : all clean fclean re bonus