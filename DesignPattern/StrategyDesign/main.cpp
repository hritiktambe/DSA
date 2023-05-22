#include <bits/stdc++.h>

using namespace std;

class DriveStrategy
{
public:
    virtual void drive() = 0;
};

class SportsDrive : public DriveStrategy
{
public:
    void drive()
    {
        cout << "special drive" << endl;
    }
};

class Vehicle
{

public:
    DriveStrategy *ds; //has a relation

    Vehicle(DriveStrategy *obj) : ds(obj) {}

    void drive()
    {
        ds->drive();
    }
};

class SportsVehicle : public Vehicle
{

public:
    SportsVehicle() : Vehicle(new SportsDrive) {}
};

main()
{
    Vehicle *vehicle = new SportsVehicle();

    vehicle->drive();
}