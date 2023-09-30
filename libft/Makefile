################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := libft.a
CC        := cc
CFLAGS    := -Wall -Wextra -Werror 

################################################################################
#                                 LIBRARIES PATHS                              #
################################################################################

CHAR_LIB := ./src/char
MATH_LIB := ./src/math
MEM_LIB := ./src/memory
STR_LIB := ./src/strings
STDIO_LIB := ./src/stdio

################################################################################
#                                 INCLUDES                                     #
################################################################################

HEADERS   := $(addprefix ./includes/, ft_char.h ft_math.h ft_mem.h ft_strings.h ft_stdio.h libft.h)

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

CHAR_LIB_SRCS := $(addprefix $(CHAR_LIB)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
											ft_isprint.c ft_tolower.c ft_toupper.c ft_isspace.c)

MATH_LIB_SRCS := $(addprefix $(MATH_LIB)/, ft_atoi.c ft_itoa.c ft_atoi_base.c ft_itoa_base.c \
											ft_calc_nbr_digits.c ft_convert_base.c ft_abs.c \
											ft_itoa_base_u.c)

MEM_LIB_SRCS := $(addprefix $(MEM_LIB)/, ft_bzero.c ft_calloc.c ft_memcpy.c ft_memchr.c \
										ft_memcmp.c ft_memmove.c ft_memset.c ft_swap.c \
										ft_swap_ptrs.c)

STR_LIB_SRCS := $(addprefix $(STR_LIB)/, ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c)

STDIO_LIB_SRCS := $(addprefix $(STDIO_LIB)/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
											ft_putnbr_base_fd.c ft_gnl.c ft_putnbr_unsigned_fd.c \
											ft_putmem_fd.c)

SRCS        :=  $(CHAR_LIB_SRCS) $(MATH_LIB_SRCS) $(MEM_LIB_SRCS) $(STR_LIB_SRCS) $(STDIO_LIB_SRCS)
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	@echo "$(CYAN)Compiling $(YELLOW)$(notdir $<)$(CLR_RMV)..."
	@${CC} ${CFLAGS} -c $< -o $@ -I ./includes

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -rf

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			@echo "$(GREEN)Creating ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ar -rcs ${NAME} ${OBJS} ${HEADERS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
			@ ${RM} ${OBJS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@${RM} ${NAME}
			@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
