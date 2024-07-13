#!/bin/bash

echo '> git update-index --assume-unchanged' \
    '*.cpp' \
    'input.txt output.txt'
git update-index --assume-unchanged \
    *.cpp \
    input.txt output.txt

echo 'complete building'
