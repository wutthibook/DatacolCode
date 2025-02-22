# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2 -std=c99

# Target executables
TARGETS = sum_numbers sum_numbers_clean sum_numbers_3 sum_numbers_5 sum_numbers_6

# Source files for each target
SRCS_sum_numbers = sum_numbers.c
SRCS_sum_numbers_clean = sum_numbers_clean.c
SRCS_sum_numbers_3 = sum_numbers_3.c
SRCS_sum_numbers_5 = sum_numbers_5.c
SRCS_sum_numbers_6 = sum_numbers_6.c

# Object files for each target
OBJS_sum_numbers = $(SRCS_sum_numbers:.c=.o)
OBJS_sum_numbers_clean = $(SRCS_sum_numbers_clean:.c=.o)
OBJS_sum_numbers_3 = $(SRCS_sum_numbers_3:.c=.o)
OBJS_sum_numbers_5 = $(SRCS_sum_numbers_5:.c=.o)
OBJS_sum_numbers_6 = $(SRCS_sum_numbers_6:.c=.o)

# Default target (build all executables)
all: $(TARGETS)

# Rule to build sum_numbers
sum_numbers: $(OBJS_sum_numbers)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build sum_numbers_clean
sum_numbers_clean: $(OBJS_sum_numbers_clean)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build sum_numbers_3
sum_numbers_3: $(OBJS_sum_numbers_3)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build sum_numbers_5
sum_numbers_5: $(OBJS_sum_numbers_5)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build sum_numbers_6
sum_numbers_6: $(OBJS_sum_numbers_6)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS_sum_numbers) $(OBJS_sum_numbers_clean) $(OBJS_sum_numbers_3) $(OBJS_sum_numbers_5) $(OBJS_sum_numbers_6) $(TARGETS)

# Phony targets (not actual files)
.PHONY: all clean