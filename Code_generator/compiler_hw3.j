.class public compiler_hw3
.super java/lang/Object
.field public static aaa I = 1
.field public static bbb F = 0.100000
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	getstatic compiler_hw3/aaa I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	getstatic compiler_hw3/bbb F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	ldc 0
	istore 0
	ldc 1.200000
	fstore 1
	ldc "abc"
	astore 2
	ldc 0
	istore 3
	fload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
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
	ldc 111.099998
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
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc 0
	istore 4
	iload 0
	iload 0
	ldc 1
	isub
	istore 0
	istore 4
	iload 4
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	ldc "hi!"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 0
	istore 5
	ldc 0
	istore 6
	iload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	aload 2
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Z)V
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
	ldc "hi!!"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 0
	iload 0
	ldc 1
	isub
	istore 0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 1
	fload 1
	ldc 1
	i2f
	fsub
	fstore 1
	iload 0
	fload 1
	fload 1
	ldc 1
	i2f
	fsub
	fstore 1
	swap
	i2f
	swap
	fadd
	fstore 1
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method
