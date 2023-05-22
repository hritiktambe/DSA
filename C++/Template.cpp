/*
    eg
    template<class Ttype> returnType funcName()
    {

    }

    Points to Remember

    C++ supports a powerful feature known as a template to implement the concept of generic programming.
    
    A template allows us to create a family of classes or family of functions to handle different data types.
    
    Template classes and functions eliminate the code duplication of different data types and thus makes the development easier and faster.
    
    Multiple parameters can be used in both class and function template.
    
    Template functions can also be overloaded.
    
    We can also use nontype arguments such as built-in or derived data types as template arguments.



*/

#include <iostream>
using namespace std;

template<class T>T add(T t1, T t2)
{
    T result = t1+t2;

    return result;
}

template<class X,class Y> void fun(X x, Y y)
{

    cout<<"value of x"<<x<<endl;
    cout << "value of y" << y << endl;
}

template <class T>
class A
{

    T t;

public:
    A(T t) : t(t) {}

    void show()
    {
        cout << t << endl;
    }
};

int main()
{
    int a=1,b=2;
    float f = 1.23;
    cout<<add(a,b);
    fun(a,b);

    A<int> tmp(a);

    tmp.show();
}