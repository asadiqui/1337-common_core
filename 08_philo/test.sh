#!/bin/bash

accuracy=1000
success='\r\033[K\e[42mSUCCESS\e[0m'
failed='\r\033[K\e[41mFailed\e[0m'

echo -e "Note: For better testing use the flag -fsanitize=thread -g3 at compilation"
echo -e "----------------------------------------"

echo -e "Norminette"
norm=$(norminette)
if ! echo "$norm" | grep -q "Error"; then
	echo -e $success
else
	echo -e $failed
fi
echo -e "----------------------------------------"

echo -e "Making the files"
make fclean > /dev/null 2>&1
if make > /dev/null 2>&1; then
    echo -e $success
else
    echo -e $failed
fi
make clean > /dev/null 2>&1
echo -e "----------------------------------------"

echo -e "0: Parsing tests"
test="./philo \t\t\t"; parse=$($test 2>&1 | tr -d '\0'); echo -e "$test: $parse"
test="./philo -1 -1 -1 -1 -1\t\t"; parse=$($test 2>&1 | tr -d '\0'); echo -e "$test: $parse"
test="./philo 0 200 100 100 8\t\t"; parse=$($test 2>&1 | tr -d '\0'); echo -e "$test: $parse"
test="./philo 2 200 100 100 8 2\t"; parse=$($test 2>&1 | tr -d '\0'); echo -e "$test: $parse"
echo -e "----------------------------------------"

echo -e "1ST TEST: ./philo 1 800 200 200"
echo -e "The philosopher should not eat and should die."
echo -n "waiting..."
output=$(./philo 1 800 200 200)
line_count=$(echo "$output" | wc -l)
if echo "$output" | grep -q "died" && [ "$line_count" -eq 2 ]; then
	echo -e "${success}"
else
	echo -e "${failed}"
fi
echo -e "----------------------------------------"

echo -e "2ND TEST: ./philo 5 800 200 200"
echo -e "No philosopher should die."
echo -n "waiting..."
output=$(./philo 5 800 200 200 | head -n "$accuracy")
line_count=$(echo "$output" | wc -l)
if ! echo "$output" | grep -q "died" && [ "$line_count" -eq "$accuracy" ]; then
	echo -e "$success"
else
	echo -e "$failed"
fi
echo -e "----------------------------------------"

echo -e "3RD TEST: ./philo 5 800 200 200 7"
echo -e "No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times."
echo -n "waiting..."
output=$(./philo 5 800 200 200 7)
line_count=$(echo "$output" | grep eating | wc -l)
if ! echo "$output" | grep -q "died" && [ "$line_count" -eq 35 ]; then
	echo -e "${success}"
else
	echo -e "${failed}"
fi
echo -e "----------------------------------------"

echo -e "4TH TEST: ./philo 4 410 200 200"
echo -e "No philosopher should die."
echo -n "waiting..."
output=$(./philo 4 410 200 200 | head -n "$accuracy")
line_count=$(echo "$output" | wc -l)
if ! echo "$output" | grep -q "died" && [ "$line_count" -eq "$accuracy" ]; then
	echo -e "${success}"
else
	echo -e "${failed}"
fi
echo -e "----------------------------------------"

echo -e "5th test: ./philo 4 310 200 100"
echo -e "One philosopher should die."
echo -n "waiting..."
output=$(./philo 4 310 200 100)
line_count=$(echo "$output" | wc -l)
if echo "$output" | grep -q "died"; then
	echo -e "${success}"
else
	echo -e "${failed}"
fi
echo -e "----------------------------------------"