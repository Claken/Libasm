CC			= nasm

CFLAGS		= -f elf64

NAME		= libasm.a

SRC1		= ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \

SRC2		= ft_list_size_bonus.s

OBJ1		= ${SRC1:.s=.o}

OBJ2		= ${SRC2:.s=.o}

%.o: %.s
			$(CC) $(CFLAGS) $< -o $@


$(NAME):	$(OBJ1)
			ar -rcs $@ $^

all:		$(NAME)

bonus:		$(NAME) $(OBJ2)
			ar -rcs $(NAME) $^

clean:
			rm -rf $(OBJ1)
			rm -rf $(OBJ2)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

re2:		fclean bonus

run:
			@make re && make clean
			@gcc testasm.c libasm.a -o testasm
run2:
			@make re2 && make clean
			@gcc testlst.c libasm.a
			@./a.out
mod:
			vi main.c

.PHONY: all clean fclean re
