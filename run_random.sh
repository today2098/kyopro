#!/bin/bash

# Terminate for error.
function terminate_execution () {
    echo "Terminate execution"
    exit 1
}


# Check number of arguments.
if (( "$#" != 2 )); then
    echo "Number of arguments is wrong";
    terminate_execution
fi


# Check necessary files.
flag=false
if [[ ! -e "$1" ]]; then
    echo "$1 does not exist"
    flag=true
fi

if [[ ! -e "$2" ]]; then
    echo "$2 does not exist"
    flag=true
fi

if [[ ! -e "make_random.cpp" ]]; then
    echo "make_random.cpp does not exist"
    flag=true
fi

if "$flag"; then
    terminate_execution
fi


# Compile.
g++ "$1" -o "a.out"
if (( "$?" != 0 )); then
    echo "Fail in compiling $1"
    terminate_execution
fi

g++ "$2" -o "b.out"
if (( "$?" != 0 )); then
    echo "Fail in compiling $2"
    terminate_execution
fi

g++ "make_random.cpp" -o "c.out"
if (( "$?" != 0 )); then
    echo "Fail in compiling make_random.cpp"
    terminate_execution
fi


# Test random cases by two ways until the two answers are not same.
while true; do
    ./c.out > input.txt
    ans1=$(./a.out < input.txt)
    ans2=$(./b.out < input.txt)
    
    if [[ "$ans1" != "$ans2" ]]; then
        echo "Wrong Answer!"
        echo ""
        
        if (( $(wc -c < input.txt) <= 10000 )); then
            echo "[IN]"
            cat input.txt
            echo ""
        fi
        
        echo "[OUT a]"
        echo "${ans1}"
        echo ""
        echo "[OUT b]"
        echo "${ans2}"
        exit
    fi
done

# Do not reach.
