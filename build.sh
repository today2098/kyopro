#!/bin/bash

echo '> git update-index --assume-unchanged' \
    '*.cpp' \
    'input.txt output.txt'
git update-index --assume-unchanged \
    *.cpp \
    input.txt output.txt

echo '> ./copy_snippet_files.sh'
./copy_snippet_files.sh

echo 'complete building'
