#!/bin/bash

echo '> git update-index --no-assume-unchanged ./*.cpp ./*.go ./input.txt ./output.txt'
git update-index --no-assume-unchanged ./*.cpp ./*.go ./input.txt ./output.txt

echo "complete resetting"
