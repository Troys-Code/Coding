#include "linklist.cpp"

using namespace std;

void menu()
{
	cout << "\n1: Push" << endl;
	cout << "2: Pop" << endl;
	cout << "\nq: Quit Program" << endl;
	cout << "\nEnter An Option" << endl;
}

int main()
{
	bool	run = true;
	string	value = "";
	char	option = 0;
	linklist<string> stack;
	
	while(run)
	{	
		stack.display_stack();
		menu();
		cin >> option;
		system("clear");
		
		switch(option)
		{
			case 'q':
				exit(0);
			case '1': 
				cout << "Enter A Value: ";
				cin >> value;
				stack.push_front(value);
				break;
			case '2':
				stack.pop_front();
				break;
		}
		system("clear");
	}
}
