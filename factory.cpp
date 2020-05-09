#include <iostream>

using namespace std;

//工厂模式

class Car//车类
{
public:
    virtual void createdCar(void) = 0;
	virtual ~Car()
	{
		cout << "virtual ~Car()" << endl;
	}
};

class BenzCar : public Car //奔驰车
{
public:
    BenzCar()
    {
        cout << "Benz::Benz()" << endl;
    }
    virtual void createdCar(void)
    {
        cout << "BenzCar::createdCar()" << endl;
    }
    ~BenzCar()
    {

    }
};

class BmwCar : public Car //宝马车
{
public:
    BmwCar()
    {
        cout << "Bmw::Bmw()" << endl;
    }
    virtual void createdCar(void)
    {
        cout << "BmwCar::createdCar()" << endl;
    }
};


class Factory//车厂
{
public:
    virtual Car* createSpecificCar(void) = 0;
	virtual ~Factory()
	{
		cout << "virtual ~Factory()" << endl;
	}
};

class BenzFactory : public Factory//奔驰车厂
{
public:
    virtual Car* createSpecificCar(void)
    {
        return (new BenzCar());
    }
};

class BmwFactory : public Factory//宝马车厂
{
public:
    virtual Car* createSpecificCar(void)
    {
        return (new BmwCar());
    }
};


int main(int argc, char** argv)
{
    Factory* factoryA = new BenzFactory();
    Car* specificCarA = factoryA->createSpecificCar();
    Factory* factoryB = new BmwFactory();
    Car* specificCarB = factoryB->createSpecificCar();
    
    delete factoryA;
    delete factoryB;
	delete specificCarA;
	delete specificCarB;
    
    return 0;
}
