// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;


/* 
Here we are initialising dice object afterwards in another function call

 */

class Dice
{
    int count;

public:
    Dice()
    {
    }
    Dice(int count) : count(count) {}

    int getCount()
    {

        return count;
    }
};

class A
{
    Dice d;

public:
    A()
    {
        initialise();
    }

private:
    void initialise()
    {
        d = Dice(1);
    }

public:
    void getDiceCount()
    {
        cout << d.getCount();
    }
};

int main()
{
    A a;

    a.getDiceCount();
}
