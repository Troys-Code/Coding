#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode
{
public:
    T data;
    ListNode *next, *previous;
    ListNode(const T &data = T(),ListNode *previous = nullptr, ListNode *next = nullptr) /// DEPENDING ON WHAT ARGUEMENTS YOU PASS IN CHANGES HOW THE FUNCTION REACTS
    {
        if (next != nullptr)                                                    /// IF THE *NEXT PASSED IN IS NOT NULLPTR
            next->previous = this;                                              // make the next node point to this one

        if (previous != nullptr)                                                /// IF THE *PREVIOUS PASSED IN IS NOT NULLPTR
            previous->next = this;                                              // make the previous node point to this

        this->previous = previous;  /// PASS NOTHING,PREVIOUS IS STILL NULLPTR, PASS IN A PREVIOUS THAN 'THIS' LISTNODES PREVIOUS IS ASSIGNED
        this->next = next; /// PASS NOTHING, NEXT IS STILL ASSIGNED NULLPTR, PASS IN A NEXT THAN 'THIS' LIST NODES NEXT IS ASSIGED

        this->data = data;                                                      /// SET THE DATA MEMBER
    }
};
#endif
