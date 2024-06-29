#!/bin/bash

echo '> git update-index --no-assume-unchanged ./*.cpp ./*.go ./*.py ./input.txt ./output.txt'
git update-index --no-assume-unchanged ./*.cpp ./*.go ./*.py ./input.txt ./output.txt

echo "complete resetting"
