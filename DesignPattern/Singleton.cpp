
#include <bits/stdc++.h>

using namespace std;

class Singleton
{
    int data;
    static Singleton *instance;

    Singleton()
    {
        data = 0;
    }

public:
    Singleton *getInstance()
    {
        if (!instance)
            instance = new Singleton();

        return instance;
    }
};

Singleton *Singleton::instance = 0;

int main()
{

    Singleton *obj = obj->getInstance();

    cout << obj << endl;

    Singleton *b = b->getInstance();

    cout << b << endl;

    return 0;
}
