#!/bin/bash
numbers=""
for i in {1..3000}; do
  numbers="$numbers $((RANDOM % 10000 + 1))"
done

output=$(./PmergeMe $numbers)

# -o only mathing parts
#-E use extended Regular Expression (allow + ? |)
# match one or more of the prev character clas
sorted_result=$(echo "$output" | grep "^After: "| grep -oE '[0-9]+')



if echo "$sorted_result" | tr ' ' '\n' | sort -n -c > /dev/null 2>&1; then
  echo "$output"
  echo "✓ Output is correctly sorted!"
  
else
  echo "Result: $sorted_result"
  echo "✗ Output is NOT sorted!"
fi


