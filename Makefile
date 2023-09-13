

# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	src/parsing.c src/index.c \
					algo/solve.c algo/radix.c \
					instructions/swap.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c \
					utils/list.c utils/list_utils.c utils/number.c utils/put_str_fd.c \
                    main.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	push_swap
HEAD_DIR		=	INCLUDES/

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3
FLAGS			+=	-MMD -MP


# RULES -------------------------------------------------------------
all:                $(NAME)

run:				all
					./$(NAME) 0 2 1 8 99 7 6

norm:
					norminette

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.c | dir
					$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/src
					@mkdir -p $(OBJS_DIR)/algo
					@mkdir -p $(OBJS_DIR)/instructions
					@mkdir -p $(OBJS_DIR)/utils

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BON)

re:					fclean all

.PHONY:				all run norm dir clean fclean re