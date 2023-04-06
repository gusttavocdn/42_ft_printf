NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlcpy.c \
	ft_strlen.c ft_atoi.c \
	ft_bzero.c ft_calloc.c \
	ft_itoa.c ft_memchr.c \
	ft_memmove.c ft_memcmp.c \
	ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c \
	ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c \
	ft_toupper.c ft_strlcat.c \
	ft_memcpy.c ft_strmapi.c \
	ft_striteri.c ft_lstnew.c \
	ft_lstadd_front.c  ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c  ft_lstclear.c  \
	ft_lstmap.c ft_lstiter.c \
	ft_split.c get_next_line.c \

SRC_B = ft_lstnew.c ft_lstadd_front.c \
		ft_lstsize.c  ft_lstlast.c \
		ft_lstadd_back.c  ft_lstdelone.c \
		ft_lstmap.c ft_lstiter.c \
		ft_lstclear.c get_next_line.c \

B_OBJS = ${SRC_B:.c=.o}

OBJS = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all:	${NAME}

${NAME}: ${OBJS} ${B_OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS} ${B_OBJS} ${HEADER}

# bonus: ${NAME} ${B_OBJS}
# 	ar -rcs ${NAME} ${B_OBJS}

# Tell make how to transform a .c file into a object file
.c.o:
	@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} libft.so a.out

fclean: clean
	${RM} ${NAME}

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: clean all fclean re so