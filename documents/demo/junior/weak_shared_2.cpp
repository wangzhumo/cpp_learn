#include <iostream>
#include <memory>

using namespace std;
struct B;

struct A{
    shared_ptr<B> pb;
    ~A(){
        cout << "~A 析构函数" << endl;
    }
};

struct B{
    shared_ptr<A> pa;
    ~B(){
        cout << "~B 析构函数" << endl;
    }
};


// pa 和 pb 存在着循环引用，根据 shared_ptr 引用计数的原理，pa 和 pb 都无法被正常的释放。
// weak_ptr 是为了解决 shared_ptr 双向引用的问题。
struct WB;

struct WA{
    weak_ptr<WB> pb;
    ~WA(){
        cout << "~WA 析构函数" << endl;
    }
};

struct WB{
    shared_ptr<WA> pa;
    ~WB(){
        cout << "~WB 析构函数" << endl;
    }
};



void Test()
{
	cout << "Test shared_ptr and shared_ptr:  " << endl;
	shared_ptr<A> tA(new A());                                               // 1
	shared_ptr<B> tB(new B());                                               // 1
	cout << tA.use_count() << endl;
	cout << tB.use_count() << endl;
	tA->pb = tB;    //循环引用,引用计数 + 1
	tB->pa = tA;
	cout << tA.use_count() << endl;                                        // 2
	cout << tB.use_count() << endl;                                        // 2
}
void Test2()
{
	cout << "Test weak_ptr and shared_ptr:  " << endl;
	shared_ptr<WA> tA(new WA());
	shared_ptr<WB> tB(new WB());
	cout << tA.use_count() << endl;                                        // 1
	cout << tB.use_count() << endl;                                        // 1
	tA->pb = tB;    //tA中的 pb作为一个weak_ptr不会对tB的引用计数造成影响
	tB->pa = tA;    //tB中 shared_ptr就会改变引用计数
	cout << tA.use_count() << endl;                                        // 2
	cout << tB.use_count() << endl;                                        // 1
}

int main()
{
	Test();
    //ta / tb 已经出了作用域
    //但是 ~A -B  没有执行析构函数,因为引用计数还不为0


	Test2();

    //~WB 析构函数
    //~WA 析构函数
    return 0;
}