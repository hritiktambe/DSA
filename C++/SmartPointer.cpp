#include <iostream>
using namespace std;

/*
https://www.geeksforgeeks.org/smart-pointers-cpp/
*/

class Smartpointer
{

    private:
    int* ptr;

    public:
    explicit SmartPointer(int* ptr=NULL)
    {
        this->ptr = ptr;
    }

    ~SmartPointer()
    {
        delete ptr;
    }

    int& operator*()
    {
        return *ptr;
    }

    int* operator->() { return ptr; }
};