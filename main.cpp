#include <iostream>

class Callback
{
public:
	Callback() {}
	~Callback() {}

	static int func(int a, int b) {
		return a + b;
	}
};

typedef int(*CallBackPtr)(int, int);

class Register
{
public:
	Register(){}
	~Register() {}

	void setCallback(CallBackPtr ptr)
	{
		p = ptr;
	}

	void run()
	{
		for (int i = 0; i < 10; i++) {
			std::cout << p(i, i) << "\n";
		}
	}
private:
	CallBackPtr p;

};

int main()
{
	Register reg;
	Callback add;
	reg.setCallback(add.func);
	reg.run();
	return 0;
}
