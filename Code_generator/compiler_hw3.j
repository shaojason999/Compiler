.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0
	istore 0
	ldc 1.200000
	fstore 1
	ldc "abc"
	astore 2
	ldc 0
	istore 3
	fload 1
	iload 0
	i2f
	fadd
	fstore 1
	ldc 1
	ldc 2
	imul
	fload 1
	swap
	i2f
	swap
	fadd
	fstore 1
	iload 0
	ldc 0.100000
	swap
	i2f
	swap
	fmul
	ldc 1.100000
	ldc 2
	i2f
	fmul
	fadd
	fload 1
	swap
	fadd
	fstore 1
	iload 0
	ldc 0.100000
	swap
	i2f
	swap
	fmul
	ldc 1.100000
	ldc 2
	i2f
	fmul
	fadd
	iload 0
	swap
	swap
	i2f
	swap
	fmul
	f2i
	istore 0
	ldc 1.200000
	iload 0
	swap
	swap
	i2f
	swap
	fmul
	f2i
	istore 0
	ldc 1
	iload 0
	swap
	irem
	istore 0
	iload 0
	ldc 1
	iadd
	fload 1
	swap
	i2f
	fdiv
	fstore 1
	ldc 15.900000
	iload 0
	swap
	swap
	i2f
	swap
	fadd
	f2i
	istore 0
	iload 0
	fload 1
	swap
	i2f
	fsub
	fstore 1
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	ldc 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 1.200000
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	ldc "hi"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method
