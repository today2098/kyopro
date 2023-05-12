#!/bin/bash

RNG_FILE_PATH='make_random_case.cpp'
INPUT_FILE_PATH='input.txt'
N=50


# Terminate for error.
function terminate_execution () {
    echo 'Terminate execution'
    exit 1
}


# Check number of arguments.
if (( $# != 2 )); then
    echo 'Number of arguments is wrong';
    terminate_execution
fi

# Check necessary files.
flag=false
for file in $1 $2 $RNG_FILE_PATH; do
    if [[ ! -e $file ]]; then
        echo "$file does not exist"
        flag=true
    fi
done
if $flag; then
    terminate_execution
fi

# Compile.
g++ $1 -o 'a.out' -std=c++17
if (( $? != 0 )); then
    echo "Fail to compile $1"
    terminate_execution
fi

g++ $2 -o 'b.out' -std=c++17
if (( $? != 0 )); then
    echo "Fail to compile $2"
    terminate_execution
fi

g++ $RNG_FILE_PATH -o 'c.out' -std=c++17
if (( $? != 0 )); then
    echo "Fail to compile $RNG_FILE_PATH"
    terminate_execution
fi

# Test random cases by two ways until the two answers are difference.
for (( i=0; i < $N; ++i )) {
    echo -n "[test $i] "

    echo -n "c.out "
    ./c.out > $INPUT_FILE_PATH
    echo -n "a.out "
    ans1=$(./a.out < $INPUT_FILE_PATH)
    echo "b.out"
    ans2=$(./b.out < $INPUT_FILE_PATH)
    
    if [[ $ans1 != $ans2 ]]; then
        echo 'Different Answer!'
        
        if (( $(wc -c < $INPUT_FILE_PATH) <= 10000 )); then
            echo '[IN]'
            cat $INPUT_FILE_PATH
            echo ''
        fi
        
        echo '[OUT a]'
        echo $ans1
        echo ''
        echo '[OUT b]'
        echo $ans2
        exit
    fi
}
echo "Finish testing $N times"
