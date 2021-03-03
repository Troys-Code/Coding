
//#include <stdlib.h>
//#include <time.h>
//#include <iostream>
//#include <math.h>
//#include <iomanip>
//#include <fstream>
//#include <sstream>
//#include <conio.h>

using namespace std;

class Shape
{
    protected:
    float Width;
    float Base;
    float Height;

    public:
    float getBase()
    {
        return Base;
    }

    float getHeight()
    {
        return Height;
    }

    float getWidth()
    {
        return Width;
    }

    void setBase(float base)
    {
        Base = base;
    }

    void setHeight(float height)
    {
        Height = height;
    }

    void setWidth(float width)
    {
        Width = width;
    }

    void setAll(float width, float base, float height)
    {
        Width = width;
        Base = base;
        Height = height;
    }

    void setSome(float width, float height)
    {
        Width = width;
        Height = height;
    }

    virtual float Area(void) = 0;

};

class Rectangle : public Shape
{
public:
    float Area()
    {
        return Width * Height;
    }
};

class Triangle : public Shape
{
public:
    float Area()
    {
        return 1/2 * Width * Height;
    }
};

class Cylinder : public Shape
{
public:
    float Area()
    {
        return (2 * 3.14159 * Width * Height) + (2 * 3.14159 * Width * Width);
    }
};

class Trapezoid : public Shape
{
public:
    float Area()
    {
        return (Width + Base)/2 * Height;
    }
};

class Circle : public Shape
{
public:
    float Area()
    {
        return (3.14159 * Width * Width);
    }
};
