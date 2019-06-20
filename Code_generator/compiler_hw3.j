.class public compiler_hw3
.super java/lang/Object
.method public static a()V
.limit stack 50
.limit locals 50
	ldc 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	invokestatic compiler_hw3/a()V
	return
.end method
