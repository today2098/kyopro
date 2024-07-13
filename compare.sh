#!/bin/bash

RNG_FILE_PATH='./create_random_case.cpp'
INPUT_FILE_PATH='./input.txt'
N=50

# Terminate with error.
function terminate_execution() {
    echo '[error] terminate execution'
    exit 1
}

# Compile cpp.
function compile_cpp() {
    g++ -std=gnu++20 -D=DEBUG -O2 -o $2 $1
    if (($? != 0)); then
        echo "[error] failed to compile $1"
        return 1
    fi
    return 0
}

# Check number of arguments.
if (($# != 2)); then
    echo '[error] number of arguments must be two'
    echo "[usage] $0 <file1> <file2>"
    terminate_execution
fi

# Check necessary files.
flag=false
source_codes=($1 $2 $RNG_FILE_PATH)
for file in ${source_codes[@]}; do
    if [[ ! -e $file ]]; then
        echo "[error] $file does not exist"
        flag=true
    fi
done
if $flag; then
    terminate_execution
fi

if [[ ! -e $INPUT_FILE_PATH ]]; then
    touch $INPUT_FILE_PATH
fi

# Compile.
output_files=('a.out' 'b.out' 'c.out')
for ((i = 0; i < 3; ++i)); do
    compile_cpp ${source_codes[i]} ${output_files[i]}
    if (($? != 0)); then
        terminate_execution
    fi
done

# Test random cases by two ways until the two answers are difference.
for ((i = 1; i <= $N; ++i)); do
    echo -n "[test $i]"
    echo -n ' c.out'
    ./c.out >$INPUT_FILE_PATH
    echo -n ' a.out'
    ans1=$(./a.out <$INPUT_FILE_PATH)
    echo ' b.out'
    ans2=$(./b.out <$INPUT_FILE_PATH)

    if [[ $ans1 != $ans2 ]]; then
        echo 'Different Answer!'

        if (($(wc -c <$INPUT_FILE_PATH) <= 10000)); then
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
done

echo "finish testing $N times"
