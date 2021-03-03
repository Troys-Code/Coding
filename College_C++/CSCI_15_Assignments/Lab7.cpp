#include <stdlib.h>
//#include <conio.h> // used for getch();
#include <time.h> // used for the "seed" number
#include <iomanip> //used for setw() command where setw() moves "x" spaces to the right.
#include <iostream>

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

    virtual float Area() = 0;

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

int main()
{
    char again = 'y';
    int option;
    float base, width, height;

    Shape *Rect = new Rectangle;
    Shape *Tri = new Triangle;
    Shape *Cyl = new Cylinder;
    Shape *Trap = new Trapezoid;
    Shape *Cir = new Circle;

    do
    {
        do
        {
            cout << "\n\tDetermine the Area of the Objects:"
                 << "\n\t1 - Rectangle"
                 << "\n\t2 - Triangle"
                 << "\n\t3 - Cylinder"
                 << "\n\t4 - Trapezoid"
                 << "\n\t5 - Circle"
                 << "\n\t6 - Quit"
                 << "\n\tEnter Option (1-6): ";
            cin >> option;
            system("cls");

        }while(option < 1 || option > 6);

        switch(option)
        {
            case 1:
            {
                cout << "\n\tOption 1 - Rectangle Object"
                     << "\n\n\tEnter Width: ";
                cin >> width;
                cout << "\n\tEnter Height: ";
                cin >> height;
                Rect -> setSome(width, height);

                cout << "\n\tRectangle Object Area Is " << (*Rect).Area();
                break;
            }
            case 2:
            {
                cout << "\n\tOption 2 - Triangle Object"
                     << "\n\n\tEnter Width: ";
                cin >> width;
                cout << "\n\tEnter Base: ";
                cin >> height;
                Tri -> setSome(width, height);
                break;
            }
            case 3:
            {
                cout << "\n\tOption 3 - Cylinder Object"
                     << "\n\n\tEnter Width: ";
                cin >> width;
                cout << "\n\tEnter Height: ";
                cin >> height;
                Cyl -> setSome(width, height);
                cout << "\n\tCylinder Object Area Is " << Cyl -> Area();
                break;
            }
            case 4:
            {
                cout << "\n\tOption 4 - Trapezoid Object"
                     << "\n\n\tEnter Width: ";
                cin >> width;
                cout << "\n\tEnter Height: ";
                cin >> height;
                cout << "\n\tEnter Base: ";
                cin >> base;
                Trap -> setAll(width, height, base);

                cout << "\n\tTrapezoid Object Area Is " << Trap -> Area();
                break;
            }
            case 5:
            {
                cout << "\n\tOption 5 - Circle Object"
                     << "\n\n\tEnter Width: ";
                cin >> width;
                Cir -> setWidth(width);

                cout << "\n\tCircle Object Area Is " << Cir -> Area();
                break;
            }
            case 6:
            {
                cout << "\n\tOption 6:"
                     << "\n\tQuitting...";
                again = 'n';
                break;
            }

        }

        cout << "\n\n\tHit Any Key to Continue...";
        getchar();
        system("cls");

    }while(again == 'y');
}
