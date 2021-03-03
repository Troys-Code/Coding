using namespace std;

struct node
{
    node *next = nullptr;
    int value;
    node *previous = nullptr;
};
void Display(node *TEMP, int size)
{
    cout << "\n\tNode # " << size << setw(3) << " Has a value of " << TEMP -> value << setw(3) << " Located at Address " << TEMP << setw (3) << " points to " << TEMP -> next;
}

class LinkedList
{
    private:
    node *FIRST = nullptr;
    node *LAST = nullptr;
    node *TEMP_Previous = nullptr;
    node *TEMP_Next = nullptr;

    node *TEMP = nullptr;
    node *TEMP2 = NULL;
    node *TEMP3 = NULL;

    public:
    void AddToFront(int width)
    {
        TEMP = new node;
        TEMP -> previous = nullptr;
        if(width == 0)
        {
            TEMP -> next = nullptr;
            LAST = TEMP;
        }
        else
        {
            TEMP -> next = FIRST;
            FIRST -> previous = TEMP;
        }
        FIRST = TEMP;

        cout << "\n\t1 - Insert an INTEGER at the BEGINNING of the LIST";
        cout << "\n\n\tEnter a Valid INTEGER: ";
        cin >> TEMP -> value;

        width++;
        Display(FIRST, 1);
    }
    void AddToBack(int width)
    {
        TEMP = new node;
        TEMP -> next = nullptr;
        if(width == 0)
        {
            TEMP -> previous = nullptr;
            FIRST = TEMP;
        }
        else
        {
            TEMP = new node;
            TEMP -> previous = LAST;
            LAST -> next = TEMP;
        }
        LAST = TEMP;
        cout << "\n\t2 - Insert an INTEGER  at the END of the LIST";
        cout << "\n\n\tEnter a Valid INTEGER: ";
        cin >> TEMP -> value;
        width++;
        Display(LAST, width);
    }
    void Remove(int number, int width, bool status)
    {

        cout << "\n\n\tEnter a SPECIFIC INTEGER from the LIST to Remove: ";
        cin >> number;
        TEMP = FIRST;
        for(int n = 1; n <= width; n++)
        {
            int Value = TEMP -> value;
            if(Value == number)
            {
                cout << "\n\tRemoving. . . ";
                Display(TEMP, n);
                //TEMP Previous
                TEMP2 = TEMP -> previous;
                //TEMP Next
                TEMP3 = TEMP -> next;
                TEMP2 -> next = TEMP -> next;
                TEMP3 -> previous = TEMP -> previous;
                width--;
                cout << "\n\n\tPrevious Node";
                if(n == 1)
                {
                    Display(TEMP2, 1);
                }
                else
                {
                    Display(TEMP2, n-1);
                }
                cout << "\n\n\tNext Node";
                Display(TEMP3, n+1);
                status = true;
                break;
            }
        TEMP = TEMP -> next;
        }
        //Outside the for loop
        if(status == false)
        {
            cout << "\n\tUnable to find INTEGER to Remove.";
        }
    }
    void Traverse(int width)
    {
        TEMP = FIRST;
        for(int n = 1; n <= width; n++)
        {
            Display(TEMP,n);
            TEMP = TEMP -> next;
        }
        cout << "\n\tNULL - End of List";
    }
    void Reverse(int width)
    {
        TEMP = LAST;
        for(int n = width; n >= 1; n--)
        {
            Display(TEMP,n);
            TEMP = TEMP -> previous;
        }
        cout << "\n\tNULL - End of List";
    }
    void Find(int number, int width, bool status)
    {
        TEMP = FIRST;
        for(int n = 1; n <= width; n++)
        {
            int Value = TEMP -> value;
            if(Value == number)
            {
                Display(TEMP, n);
                status = true;
                break;
            }
            TEMP = TEMP -> next;
        }
        if(status == false)
        {
            cout << "Unable to find " << number << " in the LIST.";
        }
    }
    void Change_Find(int number, int width, bool status, char again)
    {
        TEMP = FIRST;
        for(int n = 1; n <= width; n++)
        {
            int Value = TEMP -> value;
            if(Value == number)
            {
                Display(TEMP, n);
                cout << "\n\tWould you like to Change the INTEGER? (y or n): ";
                cin >> again;
                again = tolower(again);
                if(again == 'y')
                {
                    cout << "\n\n\tEnter a new INTEGER: ";
                    cin >> number;
                    TEMP -> value = number;

                    Display(TEMP, n);
                    getch();
                }
                again == 'y';
                status = true;
                break;
            }
            TEMP = TEMP -> next;
        }
        if(status == false)
        {
            cout << "Unable to find " << number << " in the LIST.";
        }
    }
    void First_Last(int width)
    {
        Display(FIRST, 1);
        Display(LAST, width);
    }

};
