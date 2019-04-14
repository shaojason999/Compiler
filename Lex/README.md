## Lex
### 指令:
```
$ lex compiler_hw1.l
$ cc lex.yy.c -ll
$ ./a.out test.c
```

### Notes:
1. 最難的部分為/**/的comment: 可以先畫出NFA/DFA然後化簡成只有兩個state，再寫出RE  
``` 
\/\*[^\*]*\*(\**|[^\/\*][^\*]*\*)*\/	{ for(int i=0;i<yyleng;++i)if(yytext[i]=='\n')++cline; ++cline; printf("%s \t COMMENT\n", yytext); }
```
2. 如果是要辨識", \*, +, /, \等符號的話，需要在前面加上\(像是上例)  
