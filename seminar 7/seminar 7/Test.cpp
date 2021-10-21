class MyClass1;

class MyClass1
{
public:
	MyClass1();
	~MyClass1();
	class New
	{
	public:
		New();
		MyClass1& C;
		int B = C.value2; 
	};

	New A;
	int value2 = 2;
private:
	int value1 = 1;
};

int main()
{
	MyClass1 C;
	MyClass1::New A;
}

