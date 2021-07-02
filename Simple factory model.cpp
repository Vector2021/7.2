#include<iostream>
using namespace std;

//抽象水果
class AbstractFruit {
public:
	virtual void ShowName() = 0;
};

class Apple : public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是苹果" << endl;
	}
};

class Pear : public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是鸭梨" << endl;
	}
};

class Banana : public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "我是香蕉" << endl;
	}
};

//水果工厂
class FruitFactor {
public:
	static AbstractFruit* CreatFruit(string flag) {
		if (flag == "apple")
		{
			return new Apple;
		}
		else if (flag == "pear")
		{
			return new Pear;
		}
		else if (flag == "banana")
		{
			return new Banana;
		}
		else
		{
			return NULL;
		}
	}
};

void test01() {
	FruitFactor* factor = new FruitFactor;
	AbstractFruit* fruit = factor->CreatFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = factor->CreatFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = factor->CreatFruit("pear");
	fruit->ShowName();
	delete fruit;

	delete factor;
}

int main() {
	test01();
	return 0;
}