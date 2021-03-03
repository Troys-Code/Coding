#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include "ListNode.h"
#include <exception>
using namespace std;

template <typename T>

class LinkList
{
    template <typename U>

    friend ostream & operator<< (ostream & out, const LinkList<U> & list)
    {
        ListNode<U> * p = list.headPointer;
        out << "{ ";
        while (p != nullptr)
        {
            out << p->data << " ";
            p = p->next;
        }
        out << "}";
        return out;
    }

private:
    ListNode<T> *headPointer = nullptr, *tailPointer = nullptr;
    int size;

public:
    LinkList() {
        headPointer = tailPointer = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void insertFirst(const T & data) {
        if (isEmpty())
            headPointer = tailPointer = new ListNode<T>(data);
        else
            headPointer = new ListNode<T>(data, nullptr, headPointer);
        size++;
    }

    void insertLast(const T & data) {
        if (isEmpty())
            headPointer = tailPointer = new ListNode<T>(data);
        else
            tailPointer = new ListNode<T>(data, tailPointer);
        size++;
    }

    int getSize() const {
        return size;
    }

    T& getFirst() {
        if (isEmpty())
            throw logic_error("Can't get first value in an empty list");
        return headPointer->data;
    }

    T& getLast() {
        if (isEmpty())
            throw logic_error("Can't get last value in an empty list");
        return tailPointer->data;
    }

    void removeFirst() {
        if (!isEmpty()) {
            ListNode<T> * tempPtr = headPointer;
            headPointer = headPointer->next;
            delete tempPtr;
            if (headPointer != nullptr)
                headPointer->previous = nullptr;
            else
                tailPointer = nullptr;
            size--;
        }
    }

    void removeLast() {
        if (!isEmpty()) {
            ListNode<T> * tempPtr = tailPointer;
            tailPointer = tailPointer->previous;
            delete tempPtr;
            if (tailPointer != nullptr)
                tailPointer->next = nullptr;
            else
                headPointer = nullptr;
            size--;
        }
    }

	/// clear the list
    void clear()
    {
        while(size != 0)                                                    // While We Still Have Elements In The List /= 0
            removeLast();                                                   // Delete Last Element In The List
    }

	/// just call clear()
    ~LinkList()
    {
       clear();
    }

	/// a deep copy is needed here
    LinkList(const LinkList &other) // Copy Constructor
	{
		headPointer = tailPointer = nullptr;	// Because Copy Constructor calls = operator we must reassign head and tail because it clears
		size = 0;
		*this = other;
    }

	/// again, a deep copy is neaded
    LinkList& operator=(const LinkList & other)
	{
		clear();	// Delete *This Whole List Before Copying Over 'Others' Object Values
		for (ListNode<T>* traverse = other.headPointer; traverse != nullptr; traverse = traverse->next)  // Iterates Through The List
			this->insertLast(traverse->data);
		return(*this);
    }

	/// append the items in other to the end of this list
	/// return *this
    LinkList& operator+=(const LinkList & other)
	 {
		for (ListNode<T>* tempPtr = other.headPointer; tempPtr != nullptr; tempPtr = tempPtr->next)  // Iterates Through The List
			this->insertLast(tempPtr->data);														 // Append The Data Into The List and updates size accordingly
		return(*this);																				 // Return The Modified List
	}

	/// create a temporary list equal to this list
	/// call += on the temporary list and other
	/// return the temporary list
    LinkList& operator+(const LinkList & other) const
	{
		LinkList<T>* tempPtr = new LinkList;			/// HAD TO USE 'new' b/c It Needs To Be Allocated On The Heap Because It Was Falling Out Of Scope
		*tempPtr = *this;
		*tempPtr += other;
		return(*tempPtr);
    }

	/// return value at the given index
	/// index may range from 0 to size-1, inclusive
	/// throw an exception if index is out of bounds
    T& operator[] (int index)
	{
		if (index >= 0 && index <= (size - 1))								    // If index is within acceptable range
		{
			ListNode<T>* tempPtr = headPointer;					                // Start at The beggining of the list
			for (int i = 0; i < index; i++)						                // Loop: Break Out When We Land on the Desired Index
				tempPtr = tempPtr->next;						                // Iterate the last and breaks out on the element desired
			return(tempPtr->data);								                // Return that Elements Data
		}
		else
			throw logic_error("Index is out of bounds");
    }

	///   insert the item at the given index
	///   index may range from 0 to size, inclusive
	///   if index is out of bounds then do nothing
    void insertAtIndex(const T& item, int index)
	{
		if (index >= 0 && index <= size)											// If index is within acceptable range
		{
			if (index == 0)															// If index to insert is the first element
				insertFirst(item);													// Call Insert first element function
			else if (index == size)													// Else If index to insert is the last element
				insertLast(item);													// Call Insert Last Element
			else
			{																		// OtherWise Its Not First, and Not Last It Has To Be In The Middle
				ListNode<T>* tempPtr = headPointer;									// Start at The beggining of '*this list' the object I am to  insert at
				for (int i = 0; i < index; i++)										// Loop: Break Out When We Land on the Desired Index
					tempPtr = tempPtr->next;										// Iterate the list and breaks out on the element desired
				tempPtr = new ListNode<T>(item, tempPtr->previous, tempPtr->next);	// Creates A New Node with (data, links_to_prev, links_to_next)
			}
		}
    }

	/// remove the item at the given index
	/// index may range from 0 to size-1, inclusive
	/// if index is out of bounds then do nothing
    void removeAtIndex(int index)
	{
		if (index >= 0 && index <= (size - 1))										// If index is within bounds
		{
			if (index == 0)															// If index to remove is the first element
				removeFirst();														// Then remove first element
			else if (index == (size - 1))											// If index to remove is the last element
				removeLast();														// Then remove last element
			else
			{
				ListNode<T>* tempPtr = headPointer;
				for (int i = 0; i < index; i++)
					tempPtr = tempPtr->next;										// incremementing the loop iterates through the list till we reach Index to remove
				tempPtr->previous->next = tempPtr->next;							// [tempPtr->prev->next = tempPtr->Next]-[tempPtr]-[] Essentially skips the middle element
				tempPtr->next->previous = tempPtr->previous;						// []-[tempPtr]-[tempPtr->next->prev = tempPtr->prev]
				size--;																// Dont forget to reduce the size of the list when we remove an element
			}																		// No Delete is neccessary, we have delete in the destructor/clear function
		}
    }

    /// return index of the first occurence of item
	/// or return -1 if not found
    int findItem(const T& item)
    {
        int indexLocation = 0;

        for (ListNode<T>* tempPtr = headPointer; tempPtr != nullptr; tempPtr = tempPtr->next)	// Iterate From Beggining Of '*this' list to the End
        {
            if (tempPtr->data == item)															// If the data at the current node == thie item we are searching for
                return(indexLocation);															// Return the index location
            indexLocation++;																	// Otherwise increase index and restart loop test if statement again
        }
        return(-1);																			// Was not found in the list return -1 for index (meaning error)
    }

	/// output the items in reverse order to the console (cout)
	/// e.g. if the list contains values 6 and 3 in that order
	/// then your output would be { 3 6 } followed be endl.
     void printBackwards() const
     {
		 for(ListNode<T>* tempPtr = tailPointer; tempPtr != nullptr; tempPtr = tempPtr->previous)
			 cout << tempPtr->data << " ";
     }
};

#endif
