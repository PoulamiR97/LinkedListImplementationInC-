    -------------------
	ZuruLinkedList
	-------------------
	This is a doubly linked list library developed in C++. It is a generic one, means it is capable of handling any type of data (e.g. int, float, char, any user defined data type etc.)
	It contains an iterator using which one can traverse through the list.
	Testcases to test all the properties of this linked list have been enclosed.
	
	-------------------------------
	How to install
	-------------------------------
    Unzip the ZuruLinkedList.zip folder. To run the code open  the solution "ZuruLinkedList.sln". 
	If files are not added you may add the header and source files from "ZuruLinkedList" folder.
	-------------------------------
	Properties of  ZuruLinkedList
	-------------------------------

    LinkedList();                                                // Default constructor of  LinkedList  class
	LinkedList(const LinkedList<T>& list);                       // Copy constructor  LinkedList  class
	LinkedList<T>& operator=(const LinkedList<T>& list);         // Copy assignment operator  LinkedList  class
	LinkedList(LinkedList<T>&& list) noexcept;                   // Move constructor  LinkedList  class
	LinkedList<T>& operator=(LinkedList<T>&& list) noexcept;     // Move assignment operator  LinkedList  class
	int AddHead(const T& val);                                   // API to add node to head of the linked list and return it's position
	int AddTail(const T& val);                                   // API to add node to tail of the linked list and return it's position
	T RemoveHead();                                              // API to remove and return head node data of the Linkedlist
	T RemoveTail();                                              // API to remove and return tail node of the Linkedlist
	string Add(const T& val, int p);                             // API to add node to a specific position of the Linkedlist and return operation status
	T Remove(int p);                                             // API to remove node from a specific position of the Linkedlist and return the node data
	int  Length();                                               // API to return the no of nodes present in the entire LinkedList
	void Destroy();                                              // API to destroy the entire Linkedlist
	T Get(int p);                                                // API to return the node data from a given position 'p' but shall not remove the node from the Linkedlist
	int  FindNodePos(const T& val);                              // API to find the return the node position as per the provided node data.
	Node* SearchNode(int p);                                     // API to return the node pointer from a given position 'p' in the Linkedlist
	void displayLinkedList();                                    // API to display the Linkedlist
	void EmptyListException();                                   // API to handle empty list exceptions
	LinkedList<T>& operator+=(LinkedList<T>& list);              // API to append one linkedlist at the end of another linkedlis
    Iterator();                                                  // Default constructor of  Iterator  class.
	Iterator(Node* node);                                        // Parametrized constructor of  Iterator  class.
	T& operator*() const;                                        // Dereferncing operator overload 
	Iterator& operator++ ();                                     // Pre increment operator overload method
	void operator++(const int);                                  // Post increment operator overload method
	Iterator& operator--();                                      // Pre decrement operator overload method
	void operator--(const int);                                  // Post decrement operator overload method
	bool operator!=(Iterator it) const;                          // not-equal-to operator overload method
	Iterator begin() const;                                      // to set the Iterator to point at head node of Linkedlist
	Iterator end() const;                                        // to set the Iterator to point just after the end node of Linkedlist 
	Iterator next(Iterator it, int p);                           // to set the iterator at the position mentioned next of the current position
	Iterator prev(Iterator it, int p);                           // to set the iterator at the position mentioned previous of the current position
	~LinkedList();                                               // destructor of  LinkedList  class