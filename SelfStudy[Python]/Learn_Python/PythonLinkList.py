# A single node of a singly linked list
class Node:
  # constructor
  def __init__(self, data = None, next = None): 
    self.data = data
    self.next = next

# A Linked List class with a single head node
class LinkedList:
  def __init__(self):  
    self.head = None
  
  # insertion method for the linked list
  def insert(self, data):
    newNode = Node(data)		# CREATES A NODE WITH PASSED IN DATA FIELD
    
    if(self.head):				# If Head is not Null
      current = self.head		# Set current equal to head
      while(current.next):		# While current->next is not Null
        current = current.next 	# Traverse to current->next
      current.next = newNode	# Here current->next is Null, here we place new node
    else:
      self.head = newNode		# Otherwise Set head equal to the new node created above
  
  # print method for the linked list
  def printLL(self):
    current = self.head
    while(current):
      print(current.data)
      current = current.next

# Singly Linked List with insertion and print methods
LL = LinkedList()
LL.insert("Apple")
LL.insert("Peach")
LL.insert("Pear")
LL.printLL()
