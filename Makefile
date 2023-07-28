################################################################################
#                                    CONFIG	                                   #
################################################################################

NAME	:= libftprintf.a
CC	:= cc
FLAGS    := -Wall -Wextra -Werror -g
LIB = ar -rcs

################################################################################
#                             LIBFT                                            #
################################################################################

LIBFT_PATH  :=  ./libft
LIBFT 	:=  $(LIBFT_PATH)/libft.a

################################################################################
#                           PROGRAM'S SRCS                                     #
################################################################################

SRC_DIR	:= 	src/
SRC_FILES	:= ft_printf.c specifier_handler.c flags_handler.c \
			flags_and_specifiers_verifiers.c \

SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))
	
OBJS	:= $(SRC:.c=.o)

INCLUDES := ./includes/ft_printf.h

src/%.o: src/%.c
	@echo "$(GREEN)Compiling $(CYAN)$< $(CLR_RMV)to $(YELLOW)$@ $(CLR_RMV)..."
	${CC} ${FLAGS} -c $< -o $@

################################################################################
#                           Makefile  objs                                     #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS} ${LIBFT} ${INCLUDES}
			@echo "$(GREEN)Creating lib ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@cp ${LIBFT} ${NAME}
			${LIB} ${NAME} ${OBJS} ${INCLUDES}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

clean:
			@${RM} *.o */*.o */*/*.o
			@make -C $(LIBFT_PATH) clean
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@make -C $(LIBFT_PATH) fclean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

${LIBFT}:
	@echo "$(GREEN)Making LIBFT..."
	@make -C $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) clean

run: 		all
			@echo "$(GREEN)Running...\n$(CLR_RMV)"
			@${CC} ${FLAGS} -o ft_printf main.c ./src/*.c ${LIBFT_PATH}/src/*/*.c
			@./ft_printf

.PHONY:		all clean fclean re run


