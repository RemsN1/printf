NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

SRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_calloc.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_putstr_fd.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_putendl_fd.c \
		ft_itoa_base.c \
		ft_putnbr_base_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_fd_long.c \
		ft_putnbr_fd_u.c \
		ft_putchar_fd.c
		
OBJ = $(SRC:.c=.o)

BNS_SRC = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	\
			ft_lstadd_back.c	ft_lstclear.c	ft_lstlast.c	\
			ft_lstmap.c		ft_lstdelone.c		ft_lstiter.c

BNS = $(BNS_SRC)

OBJBNS = $(BNS:.c=.o)

INCLUDES = ../includes

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

bonus :	$(OBJBNS)
	ar rc libft.a $(OBJBNS)
	ranlib libft.a

so :
	$(CC) -c -fPIC $(CFLAGS) $(SRC) $(BNS)
	clang -shared -o libft.so $(OBJ) $(OBJBNS)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean :
	rm -rf $(OBJ) $(OBJBNS)

fclean : clean
	rm -f libft.a

re : fclean all

main : $(NAME)
	$(CC) -I. -L. -lft -o test

mclean : fclean
	rm -f test

.PHONY : all bonus clean fclean re so main mclean
