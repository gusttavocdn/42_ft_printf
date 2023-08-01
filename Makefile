################################################################################
#                                    CONFIG	                                   #
################################################################################

NAME	:= libftprintf.a
CC	:= cc
FLAGS    := -Wall -Wextra -Werror
LIB = ar -rcs

################################################################################
#                             LIBFT                                            #
################################################################################

LIBFT 	:=  libft/libft.a
MAKE_LIBFT = make -C libft

################################################################################
#                           MANDATORY SRCS   CONFIG                            #
################################################################################

MANDATORY_DIR	:= 	mandatory/
MANDATORY_SRC_DIR := $(MANDATORY_DIR)src/

MANDATORY := $(addprefix $(MANDATORY_SRC_DIR), ft_printf.c specifier_handler.c)

MANDATORY_OBJS	:= ${MANDATORY:$(MANDATORY_SRC_DIR)%.c=$(MANDATORY_SRC_DIR)%.o}
MANDATORY_INCLUDES := $(MANDATORY_DIR)includes/

################################################################################
#                           BONUS SRCS CONFIG                              	   #
################################################################################

BONUS_DIR	:= 	bonus/
BONUS_OBJ_DIR := $(BONUS_DIR)objects/
BONUS_SRC_DIR := $(BONUS_DIR)src/
BONUS_SRC_FLAGS_DIR := $(BONUS_SRC_DIR)flags_utils/
BONUS_SRC_SPECIFIERS_DIR := $(BONUS_SRC_DIR)specifier_utils/

BONUS_MAIN := $(addprefix $(BONUS_SRC_DIR), ft_printf_bonus.c)

BONUS_SPECIFIER_UTILS := $(addprefix $(BONUS_SRC_SPECIFIERS_DIR), is_specifier_bonus.c \
							specifier_with_flags_bonus.c specifier_without_flags_bonus.c)

BONUS_FLAG_UTILS := $(addprefix $(BONUS_SRC_FLAGS_DIR), width_bonus.c \
					precision_bonus.c space_bonus.c plus_bonus.c is_flag_bonus.c \
					hash_bonus.c flags_handler_bonus.c apply_flags_bonus.c)

BONUS_OBJS_1 := ${BONUS_MAIN:$(BONUS_SRC_DIR)%.c=$(BONUS_OBJ_DIR)%.o}
BONUS_OBJS_2 := ${BONUS_SPECIFIER_UTILS:$(BONUS_SRC_SPECIFIERS_DIR)%.c=$(BONUS_OBJ_DIR)%.o}
BONUS_OBJS_3 := ${BONUS_FLAG_UTILS:$(BONUS_SRC_FLAGS_DIR)%.c=$(BONUS_OBJ_DIR)%.o}

BONUS_OBJS := ${BONUS_OBJS_1} ${BONUS_OBJS_2} ${BONUS_OBJS_3}
BONUS_INCLUDES_DIR := $(BONUS_DIR)includes/

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
RM		    := rm -rf

all:		$(NAME)

$(MANDATORY_SRC_DIR)%.o: $(MANDATORY_SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(MANDATORY_INCLUDES)

$(NAME):	$(LIBFT) $(MANDATORY_OBJS)
			@echo "$(GREEN)Creating lib ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@cp ${LIBFT} ${NAME}
			${LIB} ${NAME} ${MANDATORY_OBJS} ${MANDATORY_INCLUDES}/ft_printf.h
			@echo "$(GREEN)$(NAME) created[0m ✔️"

$(LIBFT):
	$(MAKE_LIBFT)
	
bonus:	${BONUS_OBJS} ${LIBFT} ${BONUS_INCLUDES}
		@echo "$(GREEN)Creating lib ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		@cp ${LIBFT} ${NAME}
		${LIB} ${NAME} ${BONUS_OBJS} ${BONUS_INCLUDES_DIR}ft_printf_bonus.h
		@echo "$(GREEN)$(NAME) created[0m ✔️"

$(BONUS_OBJ_DIR)%.o:	$(BONUS_SRC_DIR)%.c
						@mkdir -p $(BONUS_OBJ_DIR)
						$(CC) $(FLAGS) -c $< -o $@ -I $(BONUS_INCLUDES_DIR)

$(BONUS_OBJ_DIR)%.o:	$(BONUS_SRC_FLAGS_DIR)%.c
						@mkdir -p $(BONUS_OBJ_DIR)
						$(CC) $(FLAGS) -c $< -o $@ -I $(BONUS_INCLUDES_DIR)

$(BONUS_OBJ_DIR)%.o:	$(BONUS_SRC_SPECIFIERS_DIR)%.c
						@mkdir -p $(BONUS_OBJ_DIR)
						$(CC) $(FLAGS) -c $< -o $@ -I $(BONUS_INCLUDES_DIR)

clean:
			@${RM} ${BONUS_OBJ_DIR} ${MANDATORY_OBJS}
			@make -C libft clean
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@make -C libft fclean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

run: 		all
			@echo "$(GREEN)Running...\n$(CLR_RMV)"
			@${CC} ${FLAGS} -o ft_printf ${MAIN} $(MANDATORY_DIR)/src/*.c ${LIBFT_PATH}/src/*/*.c
			@./${PROGRAM}

run_b: 		all
			@echo "$(GREEN)Running...\n$(CLR_RMV)"
			@${CC} ${FLAGS} -o ft_printf ${MAIN} $(BONUS_DIR)/src/*.c  $(BONUS_DIR)/src/*/*.c ${LIBFT_PATH}/src/*/*.c
			@./${PROGRAM}

.PHONY:		all clean fclean re run bonus run_b
