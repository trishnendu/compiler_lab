bison -d testbison.y
flex lexer.l
gcc -w lex.yy.c testbison.tab.c -o parser
