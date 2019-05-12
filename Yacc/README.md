# Yacc

## 程式碼說明
### 1. %union and yylval
* 當yacc需要從lex取得值時，需要在lex將值儲存在yylval中，比如這樣:
    ```
    [0-9]+ { 
     yylval = atoi(yytext);
     return INTEGER;
    }
    ```
    * 接著yacc就可以從yylval取得值(透過$記號，下面有說明)
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
        * 因此需要在lex裡這樣寫到(因為定義在頭文件裡): extern YYSTYPE yylval;
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
* yacc取得yylval的值
    * 比如說在yacc這樣寫
    ```
    expr : expr '+' term  { $$ = $1 + $3; }
         | term           { $$ = $1; }
    ;
    ```
    * $$=$1+$3; 意思是把expr(右)的值跟term的值相加，儲存給expr(左)，接著這個算出來的值就會回傳給parse tree的上一層呼叫expr(左)的那條規則
    * 那expr(右)的值怎麼來呢? 一樣是往下呼叫parse tree的下一層透過類似的式子算得
    * 往下走到terminal時，terminal的值就是從lex的yylval來(因此type很重要)
* [參考資料1](https://stackoverflow.com/questions/1853204/yylval-and-union) [參考資料2](https://www.cnblogs.com/rednodel/p/4500276.html)

### 2. %left %right %nonassoc
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

## 觀念釐清
1. 沒有被 %token 或是 %left 等方式定義的grammar rule裡出現的符號，都會被當成nonterminal
    * 也就是說nonterminal不需要特別定義
2. $$ = $1 + $3; 是什麼意思?
    ```
    expr : expr '+' term  { $$ = $1 + $3; }
         | term           { $$ = $1; }
    ;
    ```
    * 這裡的意思是把parse tree中expr(右)的值跟term的值相加給expr(左)回傳上去
    * 如果是terminal的話，值就是從lex的yylval取得
    * 一般來說可能不需要計算，只有當你可能想要在parse的某個時候print出來目前算到的值時，才會需要。不過，這不是parser本來應該有的功能
    * 可以參考以下這個很清楚的範例[UVa 11291](http://morris821028.github.io/2014/05/12/oj/uva/uva-11291-with-yacc/)
3. (我猜)在yacc中terminal或nonterminal就算有return，也不一定要指定是哪一種形式啦，比如說:
    * 除非有做一些$$ = $1 + $3; 這種運算可能才要
    ```
    %token <string> STRING
    %type <f_val> stat
    ```
