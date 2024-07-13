#!/bin/bash

echo 'copy these snippet files'
ls -a -1 ../algorithm/.vscode/*.code-snippets
ls -1 ../algorithm/src/Utils/debug.hpp

echo '> cp ../algorithm/.vscode/*.code-snippets .vscode/'
cp ../algorithm/.vscode/*.code-snippets .vscode/

echo '> cp ../algorithm/src/Utils/debug.hpp .'
cp ../algorithm/src/Utils/debug.hpp .

echo 'complete copying snippet files'
