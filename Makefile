CC = cc
CFLAGS = -Wextra -Wall -Werror
NAME = push_swap
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
FT_PRINTF_A = $(FT_PRINTF_DIR)/ft_printf.a
SRC = operations1.c operations2.c main.c lst_utils.c
OBJ = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
	git clone git@github.com:beapfalmeida/libft.git $(LIBFT_DIR); \
	fi

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A) -o $(NAME)

$(LIBFT_A): libft
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	@if [-d "$(LIBFT_DIR)"]; then \
	$(MAKE) -C $(LIBFT_DIR) clean; \
	fi

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then \
	$(MAKE) -C $(LIBFT_DIR) fclean; \
	fi

libclean:
	rm -rf 	$(LIBFT_DIR)

re: fclean all