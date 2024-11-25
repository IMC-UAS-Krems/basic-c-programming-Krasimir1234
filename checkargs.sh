#!/bin/bash

EXPECTED_OUTPUT=$(echo -e "$2")
PROGRAM_OUTPUT=$($1 2>&1 | tr -d '\r')

echo "Expected output: '$EXPECTED_OUTPUT'"
echo "Program output: '$PROGRAM_OUTPUT'"

if [ "$PROGRAM_OUTPUT" = "$EXPECTED_OUTPUT" ]; then
    echo "Test passed"
    exit 0
else
    echo "Test failed"
    echo "Expected: '$EXPECTED_OUTPUT'"
    echo "Got: '$PROGRAM_OUTPUT'"
    exit 1
fi
