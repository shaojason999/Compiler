# Code_Generator

## 程式目的與流程
1. 將scanner與parser的功能擴展至 code generator
2. 這個 code generator 是把 C-lik e的語言編譯成 Java assembly code (use Jasmin instructions)
3. 使用 Jasmin 把 Java assembly code 編譯成 Java bytecode
4. 最後把 Java bytecode 給 JVM 後就可以執行並得到程式結果了
* 
1. 這次作業是去實作第2步的地方: Code generaotr
2. 前面的scanner 與 parser是前兩次作業的部分，我放在上一層資料夾中
3. 這次作業選用 Jasmin 作為 Java assembler

## 執行方式
```
$ make    /*編譯parser*/
$ make test    /*使用parser 產生assembly code*/
$ make clean    /*清除從執行 $ make 之後產生的檔案*/
```

## 程式細節說明
1. 這次作業有點懶的寫Readme，所以只在這簡單寫一下小細節
1. data type
    * [primitive data types](http://www.cs.sjsu.edu/faculty/pearce/modules/lectures/co/jvm/jasmin/data.html)
    * global會有string嗎?
2. 使用stack_type這個變數作為stack，紀錄每個scope的stack的所有type，這樣做運算時方便: type casting(取最上面兩個type), assign operation(取最上面一個type)等等
    * 記得每次ldc完要push一個type到stack_type
    * store完要從stack_type pop一個type
    * 做其他運算也要注意stack_type的變化
4. return的部分一定會給值(除了void)
5. f2i指令會把小數點無條件捨去
6. global variable 沒有做type-casting
7. global float不能給初始值為0.0
8. 不處理正負號(懶得用)
9. 不處理global string
10. 我的compiler接受的code的每個function都一定要寫return，而且return後面需要有值(除非是void)
    * Jasmin規定main的type一定是void
12. C語言中 a=(1,2,3)+(4,5,6); => a=9
    * if(a,b,c) => 看的是c的值
    * 所以像是(1,2,3); 之後的TOS是3
    * a=1,2,3; => a=1
        * 因為是看作a=1, 然後 ,2,3;
        * 三個同層級的expression
    * 我的code沒去處理這部分，比如第一句a會變成11(5+6)
13. 可以處理像是 a=b+3>2;
14. goto label的部分也是用一個stack紀錄每個層級的label應該是多少，這樣才可以在有if裡面又有if時，回到上一層的if時還記得label應該是多少
15. 同一個層級的離開label使用同一個，比如說: 
    ```
    if(){
        statement1;
    }
    else if(){
        statement2;
    }
    else{
        statement3;
    }
    ```
    * 概念上會變成: 
    ```
        .
        .
        .
        ifeq Label_1
            statement1
            goto Exit_1
    Label_1: 
        ifeq Label_2
            statement2
            goto Exit_1
    Label_2:
            statement3
    Exit_1:
        .
        .
        .
    ```
14. 比較的部分會先去計算是1還是0(true of false)，所以像是a>1; 會變成
    ```
        iload 0
        ldc 1
        isub
        ifgt Label_0
        ldc 0
        goto Exit_0
    Label_0:
        ldc 1
    Exit_0
    ```
    * 所以可以去做像是 a=1>3-5<=3; 這種計算
    * 所以if或while判斷式也是先去計算true of false，所以像是if(a>2){}會變成
    ```
        /*先做比較*(還沒有做if)/
        iload 0
        ldc 2
        isub
        ifgt Label_0
        ldc 0
        goto Exit_1
    Label_0:
        ldc 1
    Exit_1:
        /*開始if。根據true of flase去決定執行的程式碼*/
        ifeq Label_1
        .
        .
        .
    Label_1:   
        goto Exit_0
    Exit_0:
        .
        .
        .
    ```
15. a++
    * 會先load a兩次，因為
    * 第二次的會去加1後store回a，因此從TOS(top-of_stack)消失
    * 那第一次load的a還在，而且是本來的值
    * 所以可以做像這樣的運算a=c+a++;
    * 我猜一般的compiler也是這樣寫的
16. a=b=c+=5;
    * 向這些運算，b跟c算完之後又要賦值給左邊的variable，因此store回變數後，又要load回來。只有最左邊的a不用再load
    * 因此我有用一個變數去紀錄由左往右進到第幾個=，如果不是最左邊的，那都要load
18. 因為最後寫得有點趕，所以像是function call之類的地方，程式碼寫得有點亂
19. 跟hw2的parser一樣，為了解決只有loop裡面可以有return;的這個狀況，因此多加了一些loop_相關的grammar，而這部份跟本來的不是loop的grammar幾乎一樣
20. 一些semantic的錯誤我沒有去處理，時間不太夠

17. 可能會出現像這樣的Error
    ```
    $ java compiler_hw3
    Error: A JNI error has occurred, please check your installation and try again
    Exception in thread "main" java.lang.VerifyError: (class: compiler_hw3, method: main signature: ([Ljava/lang/String;)V) Inconsistent stack height 1 != 0
    ```
    * 看說明可以得知stack height不一至所造成，而這是發生在當你可以由不同的地方 goto 同一個Label時，stack高度不同造成，有人說這算是java的一個bug(但我覺得不算是bug啦，只是一個避免錯誤的驗證機制，雖然我寫的程式應該是不會造成錯誤)
    * 解決辦法，關掉verify
    ```
    $ java -Xverify:none compiler_hw3
    /*或是*/
    $ java -noverify compiler_hw3
    ```
    
## 小心得
* 這三次作業學到的東西不少，雖然不是直接去建一個compiler(雖然我也覺得沒有必要，太累了)，而是透過lex跟yacc協助完成scanner以及parser的部分，但是對於整個compiler的運作流程有一定的理解，而且也學會symbol table的作用
* 而這個HW3的 Code generator算是比較直接的去建一個compiler(跟HW2以及HW2不同)，讓我對組合語言的產生有一定的了解，並且我用到蠻多stack的運作去完成像是type-cast的部分，覺得受益蠻多

## 解決長久以來的疑惑
1. 以前大一寫程式時就很好奇電腦怎麼知道變數a是甚麼datatype，是儲存在ram的記憶體位置上嗎? 比如32 bit的前4個bit是記錄這是甚麼型態。 但是卻教我們說32 bit全部是拿來儲存變數的值，那麼到底是哪裡紀錄variable的type呢?
2. 原來是這樣: (假設a為int，變數index為0)
    * code中的a=a+1; 的後面的a會變成assembly的iload 0，那我們在run執行檔時，他只要看指令iload 0就知道變數0的type是int，因此不用額外的記憶體去記錄每個變數的type (原來是assembly就可以去記錄變數的type了!)
    * 那產生assembly時怎麼知道是產生iload而不是fload呢?
    * compiler中的code generator遇到variable時，會去symbol table找a的type，因此就可以知道a的type為int，因此產生iload
3. 不過我也產生了一個疑問，如果我做了轉型 a=(float)a; 那assembly code要怎麼產生?
    * 比如這樣要怎麼知道最後的a=a+1; 應該是iload還是其他?
    ```
        int a;
        if(a>0)
            a=(float)a;
        a=a+1;
    ```
    * 這問題留給以後有機會再去了解吧
    * 不過我猜可能是這樣: runtime時如果發現有做type-casting，則會用一塊記憶體去記錄，之後只要遇到iload 0之類的(假設a是0)，則都變成fload 0的方式去load記憶體
        * 不過這樣runtime時的負擔會加重不少，因為每一行都要去檢查，所以我覺得不太可能
    * 如果有人知道答案，請您寄到我的信箱 shaojason999@gmail.com 告訴我，謝謝
## 參考資料
1. [The Java Virtual Machine Instruction Set](https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-6.html)
