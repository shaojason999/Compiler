void main()
{
	int a=0;
	float b=1.2;
	string c="abc";
	bool d;

	b=b+a;
	b=1*2+b;
	b+=a*0.1+1.1*2;
	a*=a*111.1+1.1*2;

	print(a);
	{
		int e;
		e=a--;
		print(e);
		print(a);
	}

	a*=1.2;
	a%=1;
	b/=a+1;
	b-=a+=15.9;

	print(a);
	print(b);
	print(1);
	print(1.2);
	print("hi");

	a--;
	print(a);
	b--;
	b=a+b--;
	print(a);
	print(b);

	return;
}
