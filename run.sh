#!/bin/bash

g++ -o src src.cpp
if [ $? -ne 0 ]; then
    echo "Compilation error!"
    exit 1
fi

start_time=$(date +%s.%N)
./src < input.in > output.out
end_time=$(date +%s.%N)

execution_time=$(echo "$end_time - $start_time" | bc)
printf "Done. Execution time: %.6fs\n" "$execution_time"