echo 'copy these snippet files'
ls -a -1 ~/prog/algorithm/.vscode/*.code-snippets
ls -1 ~/prog/algorithm/src/Utils/debug.hpp

cp ~/prog/algorithm/.vscode/*.code-snippets .vscode/
cp ~/prog/algorithm/src/Utils/debug.hpp .
