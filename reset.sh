#!/bin/bash

echo '> git update-index --no-assume-unchanged ./*.cpp'
git update-index --no-assume-unchanged ./*.cpp

echo "complete resetting"
