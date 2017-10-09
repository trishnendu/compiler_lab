bison -d clikegrammer.y
flex lexer.l
gcc -w lex.yy.c clikegrammer.tab.c -o parser
