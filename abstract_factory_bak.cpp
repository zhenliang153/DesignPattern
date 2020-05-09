#include <iostream>

using namespace std;

/*
AbstractFactory construct!
ConCreteFactory1 construct!
AbstractProductA construct!
ProductA1 construct!
AbstractProductB construct!
ProductB1 construct!
AbstractFactory construct!
ConCreteFactory2 construct!
AbstractProductA construct!
ProductA2 construct!
AbstractProductB construct!
ProductB2 construct!
*/

//抽象工厂模式

class AbstractProductA {
protected:
	AbstractProductA() {
		cout << "AbstractProductA construct!" << endl;
	}
public:
	virtual ~AbstractProductA();
};

AbstractProductA::~AbstractProductA() {
	cout << "AbstractProductA destruct!" << endl;
}

class AbstractProductB {
protected:
	AbstractProductB() {
		cout << "AbstractProductB construct!" << endl;
	}
public:
	virtual ~AbstractProductB();
};

AbstractProductB::~AbstractProductB() {
	cout << "AbstractProductB destruct!" << endl;
}

class ProductA1: public AbstractProductA {
public:
	ProductA1() {
		cout << "ProductA1 construct!" << endl;
	}
	~ProductA1() {
		cout << "ProductA1 destruct!" << endl;
	}
};

class ProductA2: public AbstractProductA {
public:
	ProductA2() {
		cout << "ProductA2 construct!" << endl;
	}
	~ProductA2() {
		cout << "ProductA2 destruct!" << endl;
	}
};

class ProductB1: public AbstractProductB {
public:
	ProductB1() {
		cout << "ProductB1 construct!" << endl;
	}
	~ProductB1() {
		cout << "ProductB1 destruct!" << endl;
	}
};

class ProductB2: public AbstractProductB {
public:
	ProductB2() {
		cout << "ProductB2 construct!" << endl;
	}
	~ProductB2() {
		cout << "ProductB2 destruct!" << endl;
	}
};

class AbstractFactory {
protected:
	AbstractFactory() {
		cout << "AbstractFactory construct!" << endl;
	}
public:
	virtual ~AbstractFactory() {
		cout << "AbstractFactory destruct!" << endl;
	}
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class ConCreteFactory1: public AbstractFactory {
public:
	ConCreteFactory1() {
		cout << "ConCreteFactory1 construct!" << endl;
	}
	~ConCreteFactory1() {
		cout << "ConCreteFactory1 destruct!" << endl;
	}
	AbstractProductA* createProductA() {
		return new ProductA1();
	}
	AbstractProductB* createProductB() {
		return new ProductB1();
	}
};

class ConCreteFactory2: public AbstractFactory {
public:
	ConCreteFactory2() {
		cout << "ConCreteFactory2 construct!" << endl;
	}
	~ConCreteFactory2() {
		cout << "ConCreteFactory2 destruct!" << endl;
	}
	AbstractProductA* createProductA() {
		return new ProductA2();
	}
	AbstractProductB* createProductB() {
		return new ProductB2();
	}
};

int main(void) {
	AbstractFactory* cf1 = new ConCreteFactory1();
	AbstractProductA* a1 = cf1->createProductA();
	AbstractProductB* b1 = cf1->createProductB();
	AbstractFactory* cf2 = new ConCreteFactory2();
	AbstractProductA* a2 = cf2->createProductA();
	AbstractProductB* b2 = cf2->createProductB();

	delete a1;
	delete b1;
	delete a2;
	delete b2;
	delete cf1;
	delete cf2;

	return 0;
}
