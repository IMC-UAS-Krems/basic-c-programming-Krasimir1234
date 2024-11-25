
CC = gcc
CFLAGS = -Wall -Wextra -O2

ASSIGNMENT = assignment
TEST = test

ASSIGNMENT_SRC = assignment.c
TEST_SRC = test.c

$(ASSIGNMENT): $(ASSIGNMENT_SRC)
	$(CC) $(CFLAGS) -o $(ASSIGNMENT) $(ASSIGNMENT_SRC)

test: $(ASSIGNMENT) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_SRC)
	./$(ASSIGNMENT) 5 10
	./$(TEST)

clean:
	rm -f $(ASSIGNMENT) $(TEST) matrix.txt
