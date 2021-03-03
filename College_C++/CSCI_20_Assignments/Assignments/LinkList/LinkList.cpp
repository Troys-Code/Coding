#include "LinkList.h"
#include <iostream>
using namespace std;

void testCopyConstructor(LinkList<int> alist) {
	alist.removeLast();
	alist.insertLast(100);
	cout << "alist after changes:\t\t " << alist << endl;
}

int main()
{
	LinkList<int> mylist;
	mylist.insertLast(100);
	mylist.insertLast(200);
	mylist.insertLast(300);
	mylist.insertLast(400);
	mylist.insertAtIndex(500, 4);
	mylist.insertLast(400);

	cout << "MyList\t\t\t\t " << mylist << endl;							//	@@@@@@@@@	Tests	@@@@@@@@@	//

	//LinkList<int> yourlist;													// Blank Default Constructor
	//yourlist = mylist;														// Assignment Opperator
	//LinkList<int> yourlist = mylist;											// Copy Constructor


	/*LinkList<int> yourlist(mylist);

	cout << "\nyourlist before pass by value:\t " << yourlist << endl;

	testCopyConstructor(yourlist);

	cout << "yourlist after pass by value:\t " << yourlist << endl;

	yourlist.clear();
	cout << "yourlist after clear():\t\t " << yourlist << endl;

	yourlist += mylist;
	cout << "yourlist after += mylist:\t " << yourlist << endl;

	yourlist.removeAtIndex(4);
	cout << "yourlist after remove index(4):\t " << yourlist << endl;

	yourlist.removeAtIndex(3);
	cout << "yourlist after remove index(3):\t " << yourlist << endl;

	cout << "yourlist.findItem(200)\t\t { found at index: " << yourlist.findItem(200) << " }" << endl;

	cout << "yourlist.printBackward()\t { ";
	yourlist.printBackwards();
	cout << "}" << endl;
	
	cout << "HELLO" << (mylist + yourlist) << endl;

	LinkList<int> POOP = mylist + yourlist;
	cout << POOP << endl;
	*/
	
	//LinkList<int> emptyList;
	//LinkList<int> newList = (mylist + yourlist);
	//LinkList<int> newList = (emptyList + yourlist);
	//LinkList<int> newList(mylist);
	//newList = (mylist + yourlist);
	//cout << "\nnewList after (mylist+yourlist):\t " << newList << endl;

	/*
	LinkList<int> mylist;
	for (int i = 9; i >= 0; i--) {
		mylist.insertFirst(i);
		cout << mylist << "\t";
		cout << "first: " << mylist.getFirst() << "\t";
		cout << "last: " << mylist.getLast() << endl;
	}
	cout << "size = " << mylist.getSize() << endl;
	while (!(mylist.isEmpty())) {
		cout << "removing " << mylist.getLast() << endl;
		mylist.removeLast();
		cout << "new list is " << mylist << endl;
	}
	for (int i = 0; i < 10; i++)
		mylist.insertLast(i);
	cout << mylist << endl;
	while (!(mylist.isEmpty())) {
		mylist.removeLast();
		cout << mylist << endl;
	}
	LinkList<int> yourlist;
	for (int i = 0; i < 10; i++)
		yourlist.insertFirst(i);
	cout << yourlist << endl;

	while (!(yourlist.isEmpty())) {
		yourlist.removeLast();
		cout << yourlist << endl;
	}
	yourlist.insertLast(5);
	yourlist.insertLast(6);

	cout << "yourlist before pass by value:\t" << yourlist << endl;
	testCopyConstructor(yourlist);
	cout << "yourlist after pass by value:\t" << yourlist << endl;
	*/
	return 0;
}
