#include <iostream>
#define MAXSIZE 10

using namespace std;

template<class T>

class ArrayStack
{
    private:
        int top;
        T values[MAXSIZE];

    public:
        ArrayStack()
        {
            top = -1;
        }

        void push(T newValue)
        {
            if(top > MAXSIZE)
            {
                cout << "The Stack Is Full!" << endl;
                return;
            }
            values[++top] = newValue;
        }

        bool isEmpty()
        {
            if(top == -1)
            {
                cout << "Stack Is Empty!" << endl;
                return(true);
            }
            else
                return(false);
        }

        void pop()
        {
            if(isEmpty())                                                         /// If Its Not Empty
                return;
            top--;
            cout << "\nOne Element Popped From The Top Of The List\n" << endl;
        }

        T Top() const
        {
            return(values[top]);
        }
        void Display()
        {
            if(!isEmpty())
            {
                cout << "Top Of The Stack" << endl;

                for(int current = top; current > -1; current--)
                {
                    cout << "\t" << values[current] << endl;
                }
                cout << "Bottom Of The Stack\n" << endl;
            }
            else
                cout << "Cannot Display An Empty List!\n" << endl;
        }
};

int main()
{
    ArrayStack<int> stack1;
    int choice = 0;

    while(true)
    {
        system("cls");

        if(!stack1.isEmpty()) /// If Its Not Empty Display
            stack1.Display();

        cout << "\nMenu\n"
             << "1 - Display Top\n"
             << "2 - Push\n"
             << "3 - Pop\n"
             << "4 - Quit\n"
             << "\tEnter Your Choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << stack1.Top() << endl;
                system("pause");
                break;
            case 2:
                cout << "Enter A Value To Push: ";
                cin >> choice;
                stack1.push(choice);
                break;
            case 3:
                stack1.pop();
                system("pause");
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
