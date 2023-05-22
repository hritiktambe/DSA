// Online C++ compiler to run C++ program online


//Factory pattern is a creational design pattern used to create object based on a condition 

#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{

public:
    void draw()
    {
        cout << "Draw circle" << endl;
    }
};

class Rect : public Shape
{

public:
    void draw()
    {
        cout << "Draw rect" << endl;
    }
};

class ShapeFactory
{

public:
    Shape *getShape(string type)
    {

        if (type == "Circle")
        {
            return new Circle();
        }

        if (type == "Rect")
        {
            return new Rect();
        }
    }
};

int main()
{

    ShapeFactory *sf = new ShapeFactory();

    Shape *s = sf->getShape("Circle");

    s->draw();

    return 0;
}