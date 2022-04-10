#!/bin/bash

# Terminate for error.
function terminate_execution () {
    echo "Terminate execution"
    exit 1
}


# Check necessary files.
flag=false
if [ ! -e "a.out" ]; then
    echo "\"a.out\" does not exist"
    flag=true
fi

if [ ! -e "b.out" ]; then
    echo "\"b.out\" does not exist"
    flag=true
fi

if [ ! -e "make_random.cpp" ]; then
    echo "\"make_random.cpp\" does not exist"
    flag=true
fi

if "${flag}"; then
    terminate_execution
fi


# Compile "make_random.cpp".
g++ "make_random.cpp" -o "c.out"
if [ ! "$?" == 0 ]; then
    echo "Fail in compiling make_random.cpp"
    terminate_execution
fi


# Test random cases by two ways until the two answers are not same.
while true; do
    ./c.out > input.txt
    ans1=$(./a.out < input.txt)
    ans2=$(./b.out < input.txt)
    
    if [ "$ans1" != "$ans2" ]; then
        printf "Wrong Answer!\n\n"
        printf "[IN]\n"
        cat input.txt
        printf "\n"
        printf "[OUT a]\n${ans1}\n\n"
        printf "[OUT b]\n${ans2}\n"
        exit
    fi
done
