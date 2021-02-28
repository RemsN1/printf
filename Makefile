NAME    		= libftprintf.a

SRCS_LIST		= handle_conversion.c handle_conversion2.c handle_flags.c \
				  handle_flags2.c printf_utils.c printf.c ft_putchar_fd.c \
				  ft_putnbr_fd.c ft_putnbr_fd_u.c ft_putnbr_base_fd.c main.c \

SRCS            = $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS            = ${SRCS:.c=.o}

HEADER            = includes
FOLDER            = src

LIBFT             = src/libft

CC                = gcc
CFLAGS            = -Wall -Wextra -Werror
RM                = rm -f

all:            ${NAME}

$(NAME):        ${OBJS}
				@make -C $(LIBFT)
				@cp src/libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)

fclean:            clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
				rm -f main

re:                fclean all

main: $(NAME)
	$(CC) -I $(HEADER) -L. -lftprintf -o test

.PHONY: all clean fclean re main
