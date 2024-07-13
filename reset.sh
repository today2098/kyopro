#!/bin/bash

echo '> rm .vscode/*.code-snippets' \
    'debug.hpp' \
    '*.out'
rm .vscode/*.code-snippets \
    debug.hpp \
    *.out

echo '> git update-index --no-assume-unchanged' \
    '*.cpp' \
    'input.txt output.txt'

git update-index --no-assume-unchanged \
    *.cpp \
    input.txt output.txt

echo "complete resetting"
