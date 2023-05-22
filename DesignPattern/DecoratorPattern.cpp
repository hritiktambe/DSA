// Online C++ compiler to run C++ program online

/*
Decorator is a structural pattern that allows adding new behaviors to objects
dynamically by placing them inside special wrapper objects, called decorators.

*/

#include <bits/stdc++.h>
using namespace std;

class BasePizza
{
public:
    virtual int cost() = 0;
};

class VeggieDelight : public BasePizza
{

public:
    int cost()
    {
        return 120;
    }
};

class ToppingDecorator : public BasePizza
{
};

class Mushroom : public ToppingDecorator
{
    BasePizza *bp;

public:
    Mushroom(BasePizza *bp) : bp(bp) {}

    int cost()
    {
        return bp->cost() + 40;
    }
};

int main()
{

    BasePizza *p = new Mushroom(new VeggieDelight());

    cout << p->cost() << endl;
    return 0;
}