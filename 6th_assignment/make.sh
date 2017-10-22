bison -d -v clikegrammer.y
flex lexer.l
gcc -w lex.yy.c clikegrammer.tab.c symt_hashmap.c -o parser
