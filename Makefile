NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

FILES = push_swap \
		swap_functions \
		push_functions \
		rotate_functions \
		rev_rotate_functions \
		utilities_1 \
		utilities_2 \
		utilities_3 \
		validation \
		ft_split \
		clear_and_free \
		main_sorting \
		sorting_3 \
		sorting_5 \
		indexing \

BONUS_FILES = checker \
				swap_functions \
				push_functions \
				rotate_functions \
				rev_rotate_functions \
				utilities_1 \
				utilities_2 \
				utilities_3 \
				validation \
				ft_split \
				clear_and_free \
				main_sorting \
				sorting_3 \
				sorting_5 \
				indexing \
				get_next_line \
				get_next_line_utils \
				checker_utils \

HEADERS = push_swap.h

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

B_SRCS = $(addsuffix .c, $(BONUS_FILES))
B_OBJS = $(addsuffix .o, $(BONUS_FILES))

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS): $(B_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(SRCS) $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: clean all bonus

.PHONY: all bonus clean fclean re
