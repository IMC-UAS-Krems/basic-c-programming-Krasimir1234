#!/bin/bash

# Debugging: Print inputs
echo "Running checkargs.sh"
echo "Expected output: $2"

# Capture program output
PROGRAM_OUTPUT=$($1 2>&1)

# Debugging: Print the actual program output
echo "Program output: $PROGRAM_OUTPUT"

# Compare outputs
if [ "$PROGRAM_OUTPUT" == "$2" ]; then
    echo "Test passed"
    exit 0
else
    echo "Test failed"
    echo "Expected: $2"
    echo "Got: $PROGRAM_OUTPUT"
    exit 1
fi
