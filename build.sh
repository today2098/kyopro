#!/bin/bash

echo '> git update-index --assume-unchanged ./*.cpp'
git update-index --assume-unchanged ./*.cpp

echo '> ./copy_snippet_files.sh'
./copy_snippet_files.sh

echo 'complete building'
