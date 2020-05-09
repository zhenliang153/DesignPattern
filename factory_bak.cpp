#include <iostream>

/*
Factory construct!
ConcreteFactory construct!
CreateProduct!
Product construct!
ConcreteProduct construct!
ConcreteProduct destruct!
Product destruct!
ConcreteFactory destruct!
Factory construct!
*/

//工厂模式

class Product {
//屏蔽构造函数
protected:
	Product() {
		std::cout << "Product construct!" << std::endl;
	}
public:
	//父类的析构函数不是虚函数，这种情况下，将只会调用A的析构函数而不会调用子类的析构函数。
	//父类的析构函数是普通的虚函数，这种情况下，会很正常，从子类一直析构到基类，最后完成析构。
	virtual ~Product() = 0;
};

Product::~Product() {
	std::cout << "Product destruct!" << std::endl;
}

class ConcreteProduct: public Product {
public:
	ConcreteProduct() {
		std::cout << "ConcreteProduct construct!" << std::endl;
	}
	~ConcreteProduct() {
		std::cout << "ConcreteProduct destruct!" << std::endl;
	}
};

class Factory {
protected:
	Factory() {
		std::cout << "Factory construct!" << std::endl;
	}
public:
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;
};

Factory::~Factory() {
	std::cout << "Factory construct!" << std::endl;
}

class ConcreteFactory: public Factory {
public:
	ConcreteFactory() {
		std::cout << "ConcreteFactory construct!" << std::endl;
	}
	~ConcreteFactory() {
		std::cout << "ConcreteFactory destruct!" << std::endl;
	}
	Product* CreateProduct() {
		std::cout << "CreateProduct!" << std::endl;
		return new ConcreteProduct();
	}
};

int main(void) {
	Factory* f = new ConcreteFactory();
	Product* p = f->CreateProduct();
	delete p;
	delete f;
	return 0;
}
