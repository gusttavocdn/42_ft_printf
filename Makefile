################################################################################
#                                    CONFIG	                                   #
################################################################################

NAME	:= libftprintf.a
CC	:= cc
CFLAGS    := -Wall -Wextra -Werror
LIB = ar -rcs

################################################################################
#                             LIBFT                                            #
################################################################################

LIBFT 	:=  libft/libft.a
MAKE_LIBFT = @make -C libft --no-print-directory

################################################################################
#                           MANDATORY SRCS   CONFIG                            #
################################################################################

MANDATORY_SRC_DIR := ./mandatory/src

MANDATORY := $(addprefix $(MANDATORY_SRC_DIR)/, apply_flags_and_specifiers.c ft_printf.c handle_flags_and_specifiers.c)

MANDATORY += $(addprefix $(MANDATORY_SRC_DIR)/flags/, hash.c minus.c plus.c space.c \
													width.c zero.c is_flag.c)
MANDATORY += $(addprefix $(MANDATORY_SRC_DIR)/specifiers/, char.c hex.c int.c octal.c percent.c pointer.c \
															string.c unsigned_int.c is_specifier.c fmt_specifiers.c)

MANDATORY_OBJS	:= ${MANDATORY:$(MANDATORY_SRC_DIR)%.c=$(MANDATORY_SRC_DIR)%.o}
MANDATORY_INCLUDES := ./mandatory/includes

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

LOCAL_OBJS = ${MANDATORY_OBJS}

all:		$(NAME)

$(MANDATORY_SRC_DIR)%.o: $(MANDATORY_SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(MANDATORY_INCLUDES)

$(NAME):	$(LIBFT) $(LOCAL_OBJS)
			@echo "$(GREEN)Creating ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@echo "$(GREEN)Copying ${YELLOW}libft.a ${GREEN}to $(NAME)${CLR_RMV}"
			@cp ${LIBFT} ${NAME}
			@${LIB} ${NAME} ${LOCAL_OBJS} 
			@echo "$(GREEN)$(NAME) created[0m ✔️"

$(LIBFT):
	$(MAKE_LIBFT)

bonus:		$(NAME)
	
clean:
			@${RM} ${BONUS_OBJ_DIR} ${MANDATORY_OBJS}
			@make -C libft clean --no-print-directory
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@make -C libft fclean --no-print-directory
			@${RM} ${NAME}
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

compile: 		all
			@echo "$(GREEN)Running...\n$(CLR_RMV)"
			@${CC} ${CFLAGS} -o ft_printf ${MAIN} $(MANDATORY_DIR)/*.c $(MANDATORY_DIR)/flags/*.c $(MANDATORY_DIR)/specifiers/*.c libft/src/*/*.c
			@#./${PROGRAM}

.PHONY:		all clean fclean re compile bonus
