#include <iostream>
#include <cstdlib>

template <class T>
struct node 
{
	T data;
	node<T> *next = NULL;
	node<T> *previous = NULL;
};

template <class T>
class linklist
{
	private:
		node<T> *head;
		node<T> *tail;
	public:
		linklist()
		{
			head = NULL;
			tail = NULL;
		}

		void display_all()				// Display List Values
		{
			for( node<T> *current = head; current != NULL; current = current->next )
				std::cout << current->data << std::endl;
		}
		
		void display_queue()                              // Display List Values
                {	std::cout << "Front Of Queue" << std::endl;
                        for( node<T> *current = head; current != NULL; current = current->next )
                                std::cout << "|" << current->data << "| ";
                }

		void display_stack()
		{	
			std::cout << "Top Of Stack" << std::endl;
			for( node<T> *current = head; current != NULL; current = current->next )
			{
				std::cout << "\t\t|\t" << current->data << "\t|\t" << std::endl;
				std::cout << "\t\t|_______________|\t\t"<< std::endl;
			}
		}

		void push_front(T value)			// Add to begin of list (push front)
		{
			node<T> *current = new node<T>; 	// Create new node
			current->data = value;			// Set new nodes data member to value

			if( head == NULL )			// If list is empty
				head = tail = current;		// head and tail point to the current new node
			else					// Else the list is not empty we do the linking
			{
				head->previous = current;
				current->next = head;
				head = current;
					
			}
		}

		void pop_front()				// Delete from begin of list (pop)
		{
			node<T> *current = head;
			if ( head == NULL )			// Empty List
				std::cout << "Cannot Pop Empty List" << std::endl;
			else if( head->next != NULL )		// More than one element list
			{
				head = head->next;
				head->previous = NULL;
				delete current;
			}
			else					// Only one element list
			{
				delete current;
				head = tail = NULL;
			}
		}
				
		void push_back(T value)				// Add to the end of the list (Push)
		{
			node<T> *current = new node<T>;
			current->data = value;

			if( head == NULL)				// Empty List
				head = tail = current;
			else						// Add to end of list and link
			{
				tail->next = current;
				current->previous = tail;
				tail = current;
			}
		}
					
		void pop_back()					// Remove last item of the list (pop back)
		{
			node<T> *current = tail;
			if( head == tail && current == NULL )	// If empty list
				std::cout << "Cannot Pop An Empty List" << std::endl;
			else if( tail->previous != NULL )	// More than one item in the list
			{
				tail = tail->previous;
				tail->next = NULL;
				delete current;
			}
			else					// Only one item in the list
			{
				delete current;
				head = tail = NULL;
			}
		}

};

/*

void display_menu()
{
	cout << "\nPlease Enter An Option or enter 0 to exit" << endl;
	cout << "1: Push Front" << endl;
	cout << "2: Pop Front" << endl;
	cout << "3: Push Back" << endl;
	cout << "4: Pop Back" << endl; 
}

int main()
{
	// linklist<int> list;
	linklist<string> list;
	char option;
	int index;
	// int value;
	string value;
	bool run = true;

	do 
	{
		list.display_all();	// Display Current List
		display_menu();
		cin >> option;

		system("clear");

		switch( option ) 
		{
			case '0':
				run = false;
				break;
			case '1':
				cout << "1: Push Front" << endl;
				cout << "Enter A Value: ";
				cin >> value;
				list.push_front(value); 
				break;
			case '2':
				cout << "2: Pop Front" << endl;
				list.pop_front();
                                break;
			case '3':
				cout << "3: Push Back" << endl;
				cout << "Enter A Value: ";
                                cin >> value;
				list.push_back(value);
                                break;
			case '4':
				cout << "4: Pop Back" << endl;
				list.pop_back();
                                break;
		}
		cout << "\nHit Enter To Continue: ";
		cin.ignore();
		cin.get();
		system("clear");
	} while( run );	
		
} 

*/
