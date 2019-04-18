## Lex
### 指令:
```
$ lex compiler_hw1.l
$ cc lex.yy.c -ll
$ ./a.out test.c

或是用make
$ make compile
$ make scanner
$ ./myscanner "inputfile"
```

### Notes:
1. 最難的部分為/\*\*/ 的comment: /\*\*/之間不能出現\*/  
可以先畫出NFA/DFA然後化簡成只有兩個state，再寫出RE  
``` 
\/\*[^\*]*\*(\**|[^\/\*][^\*]*\*)*\/	{ for(int i=0;i<yyleng;++i)if(yytext[i]=='\n')++cline; ++cline; printf("%s \t COMMENT\n", yytext); }
```
2. 如果是要辨識", \*, +, /, \等符號的話，需要在前面加上\(像是上例)  
3. comment計行數時，最後要把一般的line--，不然會重複計算
4. 如果多個/\*\*/的comment在同一行，會重複計算cline，尚未解決此問題
