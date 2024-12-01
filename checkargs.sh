#!/bin/bash

# Capture the command and expected output
program=$1
expected_output=$2

if [ ! -x $program ]; then
  chmod +x $program
fi

# Run the program and capture its output
output=$($program)

# Compare the output with the expected string
if [ "$output" == "$expected_output" ]; then
  exit 0
else
  echo "Expected: $expected_output"
  echo "Actual: $output"
  exit 1
fi