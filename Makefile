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

LIBFT_PATH  :=  libft
LIBFT 	:=  $(LIBFT_PATH)/libft.a

${LIBFT}:
	@echo "$(GREEN)Making LIBFT..."
	@make -C $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) clean

################################################################################
#                           MANDATORY SRCS                                     #
################################################################################

MANDATORY_DIR	:= 	mandatory
MANDATORY_FILES := 	ft_printf.c specifier_handler.c flags_handler.c \
					flags_and_specifiers_verifiers.c apply_flags_and_specifier.c \
					flags_initializer.c

MANDATORY := $(addprefix $(MANDATORY_DIR)/src/, $(MANDATORY_FILES))

MANDATORY_OBJS	:= $(MANDATORY:.c=.o)
MANDATORY_INCLUDES := $(MANDATORY_DIR)/includes/ft_printf.h

################################################################################
#                           BONUS SRCS                                     	   #
################################################################################

BONUS_DIR	:= 	bonus
BONUS_FILES := 	ft_printf_bonus.c specifier_handler_bonus.c flags_handler_bonus.c \
				flags_and_specifiers_verifiers_bonus.c apply_flags_and_specifier_bonus.c \
				flags_initializer_bonus.c

BONUS := $(addprefix $(BONUS_DIR)/src/, $(BONUS_FILES))

BONUS_OBJS	:= $(BONUS:.c=.o)
BONUS_INCLUDES := $(BONUS_DIR)/includes/ft_printf_bonus.h

################################################################################
#                          DEBUG PROGRAM'S SRCS                                #
################################################################################

MAIN := main.c
PROGRAM := ft_printf

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


all:		${NAME}

${NAME}:	${MANDATORY_OBJS} ${LIBFT} ${MANDATORY_INCLUDES}
			@echo "$(GREEN)Creating lib ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@cp ${LIBFT} ${NAME}
			${LIB} ${NAME} ${MANDATORY_OBJS} ${MANDATORY_INCLUDES}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

bonus:	${BONUS_OBJS} ${LIBFT} ${BONUS_INCLUDES}
			@echo "$(GREEN)Creating lib ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@cp ${LIBFT} ${NAME}
			${LIB} ${NAME} ${BONUS_OBJS} ${BONUS_INCLUDES}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

src/%.o: src/%.c
	@echo "$(GREEN)Compiling $(CYAN)$< $(CLR_RMV)to $(YELLOW)$@ $(CLR_RMV)..."
	${CC} ${FLAGS} -c $< -o $@

clean:
			@${RM} *.o */*.o */*/*.o
			@make -C $(LIBFT_PATH) clean
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@make -C $(LIBFT_PATH) fclean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

run: 		all
			@echo "$(GREEN)Running...\n$(CLR_RMV)"
			@${CC} ${FLAGS} -o ft_printf ${MAIN} $(MANDATORY_DIR)/src/*.c ${LIBFT_PATH}/src/*/*.c
			@./${PROGRAM}

run_b: 		all
			@echo "$(GREEN)Running...\n$(CLR_RMV)"
			@${CC} ${FLAGS} -o ft_printf ${MAIN} $(BONUS_DIR)/src/*.c ${LIBFT_PATH}/src/*/*.c
			@./${PROGRAM}

.PHONY:		all clean fclean re run bonus


