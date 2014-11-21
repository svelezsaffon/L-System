echo %1
flex system_analyzer.l
bison -dy system_parser.y
gcc lex.yy.c y.tab.c -o l_system.exe
start l_system.exe "tree.svs"

