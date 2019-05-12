# Yacc

## 程式碼說明
1. %union and yylval
* 當yacc需要從lex取得值時，需要在lex將值儲存在yylval中，比如這樣:
    ```
    [0-9]+ { 
     yylval = atoi(yytext);
     return INTEGER;
    }
    ```
    * 接著yacc就可以從yylval取得值
    * 這樣是可行的，因為yylval預設就是int
* 但是如果實際情況下不只int會被用到，因此可以在yacc這樣寫
    ```
    %union
    {
    int intValue;
    float floatValue;
    char *stringValue;
    }
    ```
    * 因為這樣在yacc寫的話，會在頭文件生成，此時yylval就變成一個union的type
    ```
    typedef union
    { 
    int intValue;
    float floatValue;
    char *stringValue;
    } YYSTYPE; 
    extern YYSTYPE yylval;
    ```
    * 接著在lex這樣寫
    ```
    [a-zA-Z][a-zA-Z0-9]* {
     yylval.stringValue = strdup(yytext);
     return IDENTIFIER;
    }

    [0-9]+ { 
     yylval.intValue = atoi(yytext);
     return INTEGER;
    }

    [0-9]*\.[0-9]+"f"? {
        yylval.floatValue = new atof(yytext);
     return FLOAT;
    }
    ```
    * 如此一來，yacc就可以從lex取得各種你需要的type(需要什麼type，就在union裡面加入什麼)
* [參考資料1](https://stackoverflow.com/questions/1853204/yylval-and-union) [參考資料2](https://www.cnblogs.com/rednodel/p/4500276.html)

2. %left %right %nonassoc
* 定義terminal的left or right associative(不需要再用%token定義)
* 比如1+2+3
    * %left時，解析成(1+2)+3
    * %right時，解析成1+(2+3)
    * %nonassoc時，syntax error
* 大部分時候都是用left，那什麼時候用right呢? 比如exponential
* 愈下面的優先序愈高，比如: 
    ```
    %left '+' '-'
    %left '*' '/'
    ```
* %token 宣告的那些terminal沒有指定precedence或是associative
    ```
    %token PRINT
    %token IF ELSE FOR
    %token ID SEMICOLON
    ```
* [參考資料](https://stackoverflow.com/questions/12876543/left-and-right-in-yacc)
