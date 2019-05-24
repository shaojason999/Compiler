# Yacc

## 程式碼執行方式
```
$ make

$ ./myparser < input/zero_error.c > temp
$ diff temp output/zero_error.out
```

## 程式碼說明
#### 1. %union and yylval
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

#### 2. %left %right %nonassoc(這我沒用到)
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

#### 3. precedence
* precedence藉由grammar rule一層一層往下來達成
* [參考網站](https://en.cppreference.com/w/c/language/operator_precedence)

#### 4. declaration規則
* global跟local跟差別
    * global declaration只能給常數，不能有變數運算
        ```C
        /*legal*/
        int a=3+3;

        /*error: initializer element is not constant*/
        int a;
        int b=a+3;
        ```
    * local declaration可以有變數運算
        ```C
        /*legal*/
        int a=b=c=d+1;

        /*error: const can only occur in the rightmost assignment*/
        int a=b+1=5;
        ```
    * 為了處理以上的不同，grammar分開寫
        * global的用const_logical_or_expression系列去完成(等號右邊不會去用到任何variable)
* assignment: 第一個一定要用=
    ```C
    /*legal*/
    int a=5;
    int b=b*5; /* only legal in local */
    int c=a*=5; /* only legal in local */

    /* error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘*=’ token */
    int a*=5; /* you can replace it by: int a=a*5; */
    ```

#### 5. 這個作業的print不同於平常C裡面的printf
* printf被視為function call
* 但在這個作業print被視為一個專門的語法，所以我的處理方式就不用function call去處理

#### 6. void的部分我沒有特別去處理，比如我沒處理以下這個: 
```C
/* error: void value not ignored*/
void a(){}
int b=a();
```
* 這個應該要是error的，但我的這個作業中沒有去處理這個部分

#### 7. 其他說明
* 程式碼到最後其實寫得有點亂，但也懶得改了。我前面盡量維持一致性與整齊性，直到最後加入了幾個flag(像是Error, Function_status, dump_flag, function_flag等等)
* 這個compiler跟C還是有一點差距，比如function declare的檢查、define的檢查等等，不過基本上跟C的常見用法差不了多少
* semantic error錯誤訊息為印出一整行，然後繼續parser。syntactic error錯誤訊息為印到錯誤token為止，然後程式終止。兩者同時發生時，先印semantic
    * 我沒有處理一行內有任一錯誤超過一次的狀況

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
    * 可以參考以下這個很清楚的範例[UVa 11291](http://morris821028.github.io/2014/05/12/oj/uva/uva-11291-with-yacc/)
3. 在yacc中terminal或nonterminal只要有return，就一定要指定是哪一種形式啦，比如說:
    ```
    global_declarator
                : ID {strcpy(Variable,$1);}
    ```
    * 因為strcpy只接受char*的type，所以你需要事先在最yacc delcarations區打上類似以下的宣告
    ```
    %token <string> ID
    ```
    * 如果是nonterminal，則是如下
    ```
    %type <string> stat
    ```
    * 以上兩種<>裡的東西是定義在union裡的variable
  
4. conflict rules(這有點難講，我自己也不是非常了解)
    ```
    global_declaration
                : type SEMICOLON
                | type {printf("%d\n");}
                    global_declarator_list SEMICOLON
    ;
    ```
    * 像這樣$ yacc .y檔會出現warning: rule useless in parser due to conflicts。
    * 我覺得是因為有ambiguous。因為一旦print，就表示只能走這條了(無法去check其他rule)，而這樣的情況yacc不允許，因此這條rule會被yacc丟掉，因此不會用到
        * 比如: 輸入 int a... 可能會走global_dec或是function，因為兩者都可能先讀到int再讀到a，因此有ambiguous，此時不能有action(print)，因為一旦做了這件事，就只能走其中一條了
            * 如果有ambiguos的發生，則自動保留最上面那條
        * 因為是LR(1)，所以會先去check {action} 的下一個token，如果符合，才會回來做這個 {action}

    解決方法:  
    * 解決ambiguous(改寫規則)
    * 或是把{action}加在別的地方，比如加在最後面也許就不會有ambiguous的問題
  
5. const (以下這些我都有特別處理)
* a\++; 的回傳值為數字，不是變數
    ```C
    /*illegal*/
    int a;
    a++=5;
    ```
* a*=1;
    ```C
    /*legal*/
    int a,b,c;
    a*=b*=c*=1;
    ```
* string的比較特別
    ```C
    char a,b;

    /* warning: assignment makes integer from pointer without a cast */
    a*=b="a";

    /* error: invalid operands to binary * (have ‘int’ and char *’) */
    a*="a";
    ```
## 其他注意事項
1. lex檔裡的return要放在BEGIN後面
```
"/*"                    { BEGIN COMMENT; }
<COMMENT>[^*\n]+        {  }
<COMMENT>\n             {  }
<COMMENT>"*"            {  }
<COMMENT>"*/"           { BEGIN INITIAL; return C_COMMENT;}
```

2. 即使文法沒有完全符合，還是有可能執行{}的指令，比如:
* input為: 
    ```
    while (n > m) {
        n--;
    ```
* grammar為: 
    ```
    iteration_statement
        : WHILE{printf("%d\n",yylineno);} LB expression_list RB loop_compound_statement
    ```
* 結果輸出為0(第0行)
* 這可能跟yacc為LALR(1)，只看下一個terminal有關

3. lex檔裡的<<EOF>>要特別處理:  [參考資料](http://dinosaur.compilertools.net/flex/flex_13.html)
    * 其中一個方法是yyterminate();

4. grammar參考 [ANSI C Yacc grammar](http://www.quut.com/c/ANSI-C-grammar-y.html#jump_statement)
    * 可是這個範例裡面問題超多，參考就好
    * 主要還是自己寫及修改

---
### 主要參考資料
[symbol table](https://www.iis.sinica.edu.tw/~tshsu/compiler/2005/slides/slide5.pdf)
[ANSI C Yacc grammar](http://www.quut.com/c/ANSI-C-grammar-y.html#jump_statement)
[UVa 11291](http://morris821028.github.io/2014/05/12/oj/uva/uva-11291-with-yacc/)
[Precedence](https://en.cppreference.com/w/c/language/operator_precedence)
