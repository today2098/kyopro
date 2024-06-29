#!/bin/bash

echo '> git update-index --no-assume-unchanged ./*.cpp ./*.py ./input.txt ./output.txt'
git update-index --no-assume-unchanged ./*.cpp ./*.py ./input.txt ./output.txt

echo "complete resetting"
