.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0
	istore 0
	ldc 0
	istore 1
	ldc 1
	ldc 2
	isub
	ifgt Label_0
	ldc 0
	goto Exit_0
Label_0:
	ldc 1
Exit_0:
	ldc 2
	ldc 3
	isub
	ifge Label_1
	ldc 0
	goto Exit_1
Label_1:
	ldc 1
Exit_1:
	istore 0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	ldc 1
	ldc 2
	isub
	iflt Label_2
	ldc 0
	goto Exit_2
Label_2:
	ldc 1
Exit_2:
	iadd
	istore 1
	iload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
