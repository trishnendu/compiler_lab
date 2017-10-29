bison -d -v clikeg.y
flex clikeg_lexer.l
gcc -w lex.yy.c clikeg.tab.c symt_hashmap.c -o parser
