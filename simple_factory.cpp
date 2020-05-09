#include <iostream>

using namespace std;

//简单工厂模式

enum CarType{BENZ, BMW};

class Car//车类
{
public:
    virtual void createdCar(void) = 0;
	//必须添加虚析构函数，否则子类不会被析构
	virtual ~Car() 
	{
        cout<<"virtual ~Car()"<<endl;
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


class CarFactory //车厂
{
public:
    Car* createSpecificCar(CarType type)
    {
        switch(type)
        {
        case BENZ://生产奔驰车
            return (new BenzCar());
            break;
        case BMW://生辰宝马车
            return (new BmwCar());
            break;
        default:
            return NULL;
            break;
        }
    }
};

int main(int argc, char** argv)
{
    CarFactory carfac;
    Car* specificCarA = carfac.createSpecificCar(BENZ);
    Car* specificCarB = carfac.createSpecificCar(BMW);

	delete specificCarA;
	delete specificCarB;
    
    return 0;
}
