#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex g_mutex;
std::once_flag g_flag; //这个是系统定义的标记

//单例模式模板类
template<class T>
class SingleTon {
private:
	//只被调用1次
	static void createInstance() {
		//std::chrono::milliseconds dura(2000);
		//std::this_thread::sleep_for(dura);
		cout << "create instance!" << endl;
		m_instance = new T;
		static Recover recover;
	}
public:
	static T* getInstance() {
		/*
		if(m_instance == nullptr) {
			//懒汉模式 线程安全加锁
			std::unique_lock<std::mutex> lock(g_mutex);
			if(m_instance == nullptr) {
				m_instance = new T;
				static Recover recover;
			}
		}
		*/
		//两个线程同时执行到这里，其中一个线程要等另外一个线程执行完毕
		std::call_once(g_flag, createInstance);
		return m_instance;
	}
	//类中套类，用于释放对象
	class Recover {
	public:
		~Recover() {
			if(SingleTon<T>::m_instance != nullptr) {
				cout << "delete m_instance!" << endl;
				delete SingleTon<T>::m_instance;
				SingleTon<T>::m_instance = nullptr;
			}
		}
	};
private:
	SingleTon();
	~SingleTon();
	static T* m_instance;
};

template<class T>
T* SingleTon<T>::m_instance = nullptr;

class Log
{
private:
	Log(){}							//私有化构造函数，使本类不能再外部生成对象
	Log(const Log& );				//私有化拷贝构造函数，使本类不能为其它本类对象初始化
	Log& operator= (const Log& );	//私有化赋值操作符，使本类不能为其它本类对象赋值

	friend class SingleTon<Log>;	//Singleton模板类为本类的友元类，它才能new对象

public:
	void print_this() {
		cout << "this: " << this << endl;
	}
};

void createThread() {
	Log* log = SingleTon<Log>::getInstance();
	log->print_this();
}

int main(void) {
	std::thread ta(createThread);
	std::thread tb(createThread);
	ta.join();
	tb.join();

	return 0;
}
