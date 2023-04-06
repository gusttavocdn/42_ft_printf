LIBFT_PATH = ./libft
LIBFT = libft.a
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
HEADER_PATH = ./include
HEADER = ${HEADER_PATH}/ft_printf.h
SRC_PATH = ./src
SRCS = ${SRC_PATH}/ft_printf.c	${SRC_PATH}/ft_print_hex_memory.c \
	${SRC_PATH}/ft_putunbr_fd.c	${SRC_PATH}/ft_print_hex_nbr.c
OBJS = ${SRCS:.c=.o}
RM = rm -rf

all:	${NAME}

#To run the main for test quickly
run:
	@clear
	${CC} main.c -lftprintf -L ./ -lft -L ${LIBFT_PATH} -o main
	./main

${NAME}: ${LIBFT} ${OBJS} ${HEADER}
	@echo "Creating the library"
	ar -rcs ${NAME} ${OBJS} ${HEADER}
	@echo "Library sucessfuly created"

${LIBFT}:
	@echo "Making Libft objects files"
	@make -C ${LIBFT_PATH}
	@echo "Removing libft.o files remaining"
	@make -C ${LIBFT_PATH} clean

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${LIBFT_PATH}/${LIBFT}

.PHONY: run clean fclean all libft