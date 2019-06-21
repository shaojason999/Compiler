.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0
	istore 0
	iload 0
	ldc 2
	isub
	ifgt Label_0
	ldc 0
	goto Exit_1
Label_0:
	ldc 1
Exit_1:
	ifeq Label_1
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
Label_1:
	goto Exit_0
Exit_0:
	return
.end method
