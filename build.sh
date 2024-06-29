#!/bin/bash

echo '> git update-index --assume-unchanged ./*.cpp'
git update-index --assume-unchanged ./*.cpp

echo '> bash ./copy_snippet_files.sh'
bash ./copy_snippet_files.sh

echo 'complete building'
