NAME := push_swap
BONUS := checker
LIB_DIR := ft_printf
LIB := $(LIB_DIR)/libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
SANFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -fno-sanitize-recover=all

COMMON_SRCS := parser.c \
            stack.c \
			has_duplicates.c \
			compute_disorder.c \
			rank_ints.c \
            ops_swap.c \
            ops_push.c \
            ops_rotate.c \
            ops_reverse_rotate.c \
            ops_emit.c \
            ops_stats.c \
            sort_simple.c \
            sort_medium.c \
            sort_complex.c \
            sort_adaptive.c \
            strategy.c \
            utils.c

SRCS := main.c $(COMMON_SRCS)

BONUS_SRCS := checker_bonus.c \
              checker_utils_bonus.c \
              checker_ops_bonus.c

OBJS := $(SRCS:.c=.o)
COMMON_OBJS := $(COMMON_SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
BONUS_TEST_OBJS := checker_ops_bonus.o

TEST_DIR := tests
TEST_SRCS := $(filter-out $(TEST_DIR)/test_%_bonus.c,$(wildcard $(TEST_DIR)/test_*.c))
TEST_BINS := $(TEST_SRCS:.c=)
BONUS_TEST_SRCS := $(wildcard $(TEST_DIR)/test_*_bonus.c)
BONUS_TEST_BINS := $(BONUS_TEST_SRCS:.c=)

all: $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIB_DIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(COMMON_OBJS) $(BONUS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) $(LIB) -o $(BONUS)

test: $(NAME)
	@for t in $(TEST_BINS); do \
		$(CC) $(CFLAGS) $(SANFLAGS) -I$(LIB_DIR) -I$(TEST_DIR) $$t.c $(TEST_DIR)/test.c $(COMMON_OBJS) $(LIB) -o $$t && $$t --report-error || exit 1; \
	done

test-bonus: $(COMMON_OBJS) $(BONUS_TEST_OBJS) $(LIB)
	@for t in $(BONUS_TEST_BINS); do \
		$(CC) $(CFLAGS) $(SANFLAGS) -I$(LIB_DIR) -I$(TEST_DIR) $$t.c $(TEST_DIR)/test.c $(COMMON_OBJS) $(BONUS_TEST_OBJS) $(LIB) -o $$t && $$t --report-error || exit 1; \
	done

clean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(TEST_BINS) $(BONUS_TEST_BINS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus test test-bonus clean fclean re
