#!/bin/bash

output1=$(./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" 2>&1)
output2=$(./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" 2>&1)
output3=$(./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" 2>&1)
output4=$(./RPN "1 2 + 2 - * 2 +" 2>&1)
output5=$(./RPN "1 + 1" 2>&1)

# Test 1
if [ "$output1" == "42" ]; then
  echo "Result: $output1"
  echo "✓ Output is calculated correctly"
else
  echo "Result: $output1"
  echo "✗ Output is NOT correct, should be 42"
fi

# Test 2
if [ "$output2" == "42" ]; then
  echo "Result: $output2"
  echo "✓ Output is calculated correctly"
else
  echo "Result: $output2"
  echo "✗ Output is NOT correct, should be 42"
fi

# Test 3
if [ "$output3" == "15" ]; then
  echo "Result: $output3"
  echo "✓ Output is calculated correctly"
else
  echo "Result: $output3"
  echo "✗ Output is NOT correct, should be 15"
fi

# Test 4
if [[ "$output4" == *"Error"* ]]; then
  echo "Result: $output4"
  echo "✓ Output has thrown an error"
else
  echo "Test 4"
  echo "Result: $output4"
  echo "✗ Output is NOT correct, should be an error"
fi

# Test 5
if [[ "$output5" == *"Error"* ]]; then
  echo "Result: $output5"
  echo "✓ Output has thrown an error"
else
  echo "Result: $output5"
  echo "✗ Output is NOT correct, should be Error"
fi