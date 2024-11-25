# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Targets
ASSIGNMENT = assignment
TEST = test

# Source files
ASSIGNMENT_SRC = assignment.c
TEST_SRC = test.c

# Build assignment executable
$(ASSIGNMENT): $(ASSIGNMENT_SRC)
	$(CC) $(CFLAGS) -o $(ASSIGNMENT) $(ASSIGNMENT_SRC)

# Build and run test
test: $(ASSIGNMENT) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_SRC)
	./$(ASSIGNMENT) 5 10
	./$(TEST)

# Clean up
clean:
	rm -f $(ASSIGNMENT) $(TEST) matrix.txt
