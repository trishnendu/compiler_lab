bison -d testbison.y
flex lexer.l
gcc -w lex.yy.c testbison.tab.c symt_hashmap.c -o parser
