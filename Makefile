NAME := push_swap
BONUS := checker
LIB_DIR := ft_printf
LIB := $(LIB_DIR)/libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
SANFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -fno-sanitize-recover=all

SRCS := main.c \
            parser.c \
            stack.c \
            ops_swap.c \
            ops_push.c \
            ops_rotate.c \
            ops_reverse_rotate.c \
            sort_simple.c \
            sort_medium.c \
            sort_complex.c \
            sort_adaptive.c \
            strategy.c \
            utils.c

BONUS_SRCS := checker_bonus.c \
              checker_utils_bonus.c

OBJS     := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

TEST_DIR := tests
TEST_SRCS := $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINS := $(TEST_SRCS:.c=)

all: $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIB_DIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus: $(NAME) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIB) -o $(BONUS)

test: $(NAME)
	@for t in $(TEST_BINS); do \
		$(CC) $(CFLAGS) $(SANFLAGS) -I$(LIB_DIR) -I$(TEST_DIR) $$t.c $(filter-out main.o,$(OBJS)) $(LIB) -o $$t && $$t || exit 1; \
	done

clean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(TEST_BINS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus test clean fclean re
