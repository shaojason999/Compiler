# Compiler
## Lex
1. 最難的部分為/**/的comment: 可以先畫出NFA/DFA然後化簡成只有兩個state，再寫出RE  
2. 如果是要辨識", *, +, /, \等符號的話，需要在前面加上\  
