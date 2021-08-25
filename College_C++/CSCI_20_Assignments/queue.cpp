#include "linklist.cpp"

using namespace std;

int main()
{
	linklist<string> queue;
	bool run = true;
	char option;
	string value;

	while(run)
	{
		system("clear");
		queue.display_queue();
		
		cout << "\n1: enque" << endl;
		cout << "2: deque" << endl;
		cout << "Enter An Option: ";

		cin >> option;
		switch(option)
		{
			case '1': 
				cout << "Enter A Value: ";
				cin >> value;
				queue.push_back(value);
				break;
			case '2':
				queue.pop_front();
				break;
			default:
				exit(0);
		}
		
	}
	return(0);

}
