.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1
	istore 0
Label_0:
	iload 0
	ldc 6
	isub
	iflt Label_1
	ldc 0
	goto Exit_1
Label_1:
	ldc 1
Exit_1:
	ifeq Exit_0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	iload 0
	ldc 1
	iadd
	istore 0
	goto Label_0
Exit_0:
	return
.end method
