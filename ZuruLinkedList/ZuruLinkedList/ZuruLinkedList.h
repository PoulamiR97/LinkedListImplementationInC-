#include<iostream>
#include "ErrorCodes.h"
#include <string>


#pragma once

// Creating doubly linked list 
template <typename T>
class LinkedList {

private:

	///<summary>
	/// Creating inner class node to have the contents of node element of LinkedList
	/// <param name='data'> data content of the node element.  </param>
	/// <param name='prev'> pointer to previous node element.  </param>
	/// <param name='next'> pointer to next node element.      </param>
	///</summary>

	class Node {
	private:
		T data {};
		Node* prev{ nullptr };
		Node* next{ nullptr };
	public:
		friend class LinkedList;        // so that private members of Node class can be accessed by LinkedList class
		friend class Iterator;          // so that private members of Node class can be accessed by Iterator class
	};

	///<summary>
	/// Creating node elements of LinkedList
	/// <param name='head'> first node of the list  </param>
	/// <param name='tail'> last  node of the list  </param>
	///</summary>

	Node* head;
	Node* tail;

public:

	///<summary>
	/// Implementation of LinkedList methods
	/// <param name='list'> taking specified linkedlist as parameter </param>
	/// <param name='val'> value or the data of the specified node  </param>
	/// <param name='p'> position of the specified node  </param>
	/// <param name='it'> iterator of the specified linkedlist  </param>
	///</summary>
	int NodeCount = 0;           // global variable kept to keep the count of nodes
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
	void Reverse();                                              // API to reverse the whole linkedlist
	void RemoveNodes(int p, int n, Direction);
	int  FindNodePos(const T& val);                              // API to find the return the node position as per the provided node data.
	Node* SearchNode(int p);                                     // API to return the node pointer from a given position 'p' in the Linkedlist
	void displayLinkedList();                                    // API to display the Linkedlist
	void EmptyListException();                                   // API to handle empty list exceptions
	LinkedList<T>& operator+=(LinkedList<T>& list);              // API to append one linkedlist at the end of another linkedlist

	///<summary>
	/// Creating inner class iterator of LinkedList
	/// <param name='node'> node element of  Iterator  class </param>
	///</summary>

	class Iterator
	{
	private:
		Node* node;

	public:
		Iterator();                               // Default constructor of  Iterator  class.
		Iterator(Node* node);                     // Parametrized constructor of  Iterator  class.
		T& operator*() const;                     // Dereferncing operator overload 
		Iterator& operator++ ();                  // Pre increment operator overload method
		void operator++(const int);               // Post increment operator overload method
		Iterator& operator--();                   // Pre decrement operator overload method
		void operator--(const int);               // Post decrement operator overload method
		bool operator!=(Iterator it) const;       // not-equal-to operator overload method
	};

	Iterator begin() const;                       // to set the Iterator to point at head node of Linkedlist
	Iterator end() const;                         // to set the Iterator to point just after the end node of Linkedlist 
	Iterator next(Iterator it, int p);            // to set the iterator at the position mentioned next of the current position
	Iterator prev(Iterator it, int p);            // to set the iterator at the position mentioned previous of the current position
	~LinkedList();                                // destructor of  LinkedList  class
};


	///<summary>
	///  Iterator()  is the default constructor of  Iterator  class.
	///</summary>
    template <typename T>
	LinkedList<T>::Iterator::Iterator() {
		node = nullptr;
	};

	///<summary>
	///  Iterator(Node* node)  parametrized constructor of  Iterator  class.
	///</summary>
	template <typename T>
	LinkedList<T>::Iterator::Iterator(Node* node) {
		this->node = node;

	};
	

	///<summary>
	///  operator*()  dereferncing operator overload method  Iterator  class.
	///</summary>
	template <typename T>
	T& LinkedList<T>::Iterator::operator*() const {
		return node->data;
	}


	///<summary>
	///  operator++()  pre increment operator overload method  Iterator  class.
	///</summary>
	template <typename T>
	typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++ () {

		node = node->next;
		return *this;
	};


	///<summary>
	///  operator++(...)  post increment operator overload method  Iterator  class.
	///</summary>
	template <typename T>
	void LinkedList<T>::Iterator::operator++(const int) {

		++* this;
	};

	///<summary>
	///  operator--()  pre decrement operator overload method  Iterator  class.
	///</summary>
	template <typename T>
	typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--() {

		node = node->prev;
		return *this;
	};

	///<summary>
	///  operator--(...)  post decrement operator overload method  Iterator  class.
	///</summary>
	template <typename T>
	void LinkedList<T>::Iterator::operator--(const int) {

		--* this;
	};

	///<summary>
	///  operator!=(...) const  not equal to operator overload method Iterator class.
	///</summary>
	template <typename T>
	bool LinkedList<T>::Iterator::operator!=(Iterator it) const {

		if (this->node != it.node)
			return true;
		else
			return false;
	};

	///<summary>
	///  LinkedList()  is the default constructor of  LinkedList  class.
	///</summary>
	template <typename T>
	LinkedList<T>::LinkedList() {
		{
			head = nullptr;
			tail = nullptr;
		}
	};

	///<summary>
	///  LinkedList(...)  copy constructor  LinkedList  class.
	///</summary>
	template <typename T>
	LinkedList<T>::LinkedList(const LinkedList<T>& list) {
		
		cout << "Copy constructor is called" << endl;

		// To check if the list that needs to be copied is empty! (if empty! make the present list empty and return)
		if (list.head == nullptr || list.tail == nullptr) {
			this->head = nullptr;
			this->tail = nullptr;
			return;
		}
		/* setting this->head = list.head and creating a loop will only make the this->head pointer
		  to point towards the list.head pointer location and thus, do a shallow copy */

		else
		{
		// Deep copying of resources
			Node* currentNode = list.head;  // pointer to traverse through &list 
			while (currentNode != nullptr) {
				LinkedList<T>::AddTail(currentNode->data);
				currentNode = currentNode->next;
			}
		}
	};

	///<summary>
	///  LinkedList<T>& operator=(const LinkedList<T>& list)  copy assignment operator  LinkedList  class.
	///</summary>
	template <typename T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) {

		cout << "Copy assignment operator is called" << endl;

		if (this != &list) {
			// Free the existing resource.
			this->LinkedList<T>::Destroy(); 

			if (list.head == nullptr || list.tail == nullptr) {
				this->head = nullptr;
				this->tail = nullptr;
			}
			else {
				Node* currentNode = list.head;  // pointer to traverse through &list 
				while (currentNode != nullptr) {
					LinkedList<T>::AddTail(currentNode->data);
					currentNode = currentNode->next;
				}
			}
		}
		return *this;
	};

	///<summary>
	///  LinkedList(LinkedList<T>&& list)  move constructor  LinkedList  class.
	///</summary>
	template <typename T>
	LinkedList<T>::LinkedList(LinkedList<T>&& list) noexcept {

		cout << "Move constructor is called" << endl;
		// Move the temporary resources to existing resources
			head = list.head;
			tail = list.tail;
			this->NodeCount = list.NodeCount;

		// Release the temporary resources 
		list.head = nullptr;
		list.tail = nullptr;
		list.NodeCount = 0;
	};

	///<summary>
	///  LinkedList<T>& operator=(LinkedList<T>&& list)  move assignment operator  LinkedList  class.
	///</summary>
	template <typename T>
	LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& list) noexcept {
		
		cout << "Move assignment operator is called" << endl;

		if (this != &list) {
			// Free the existing resource.
			delete head;
			delete tail;

			// Copy of the temporary resources
			head = list.head;
			tail = list.tail;
			this->NodeCount = list.NodeCount;

			// Release the temporary resources 
			list.head = nullptr;
			list.tail = nullptr;
			list.NodeCount = 0;
		}
		return *this;
	};

	///<summary>
	///  AddHead(...)  API to add node to head of the linked list and return it's position
	///</summary>
	template <typename T>
	int LinkedList<T>::AddHead(const T& val) {
		Node* newNodeAtHead = new Node; //allocate memory for new node at head
		newNodeAtHead->data = val;      //assign data to new node
		newNodeAtHead->prev = nullptr;  //Set prev of new node to nullptr
		newNodeAtHead->next = nullptr;  //Set next of new node to nullptr

		/* if part is for when the linkedlist contains one node only
		   + for displaying LinkedList to set first node to head and last node to tail*/

		if (head == nullptr) {
			head = newNodeAtHead;
			tail = newNodeAtHead;
		}
		else {
			newNodeAtHead->next = head;
			head->prev = newNodeAtHead;
			head = newNodeAtHead;
		}

		NodeCount = NodeCount++;
		//return head;
		return LinkedList<T>::FindNodePos(val);
	};

	///<summary>
	///  AddTail(...)  API to add node to tail of the linked list and return it's position
	///</summary>
	template <typename T>
	int LinkedList<T>::AddTail(const T& val) {
		Node* newNodeAtTail = new Node; //allocate memory for new node at tail
		newNodeAtTail->data = val;      //assign data to new node
		newNodeAtTail->prev = nullptr;  //Set prev of new node to nullptr
		newNodeAtTail->next = nullptr;  //Set next of new node to nullptr

		/* if part is for when the linkedlist contains one node only
		   + for displaying LinkedList to set first node to head and last node to tail*/

		if (tail == nullptr) {
			tail = newNodeAtTail;
			head = newNodeAtTail;
		}
		else {
			newNodeAtTail->prev = tail;
			tail->next = newNodeAtTail;
			tail = newNodeAtTail;
		}

		NodeCount = NodeCount++;
		//return tail;
		return LinkedList<T>::FindNodePos(val);
	};

	///<summary>
	///  RemoveHead()  API to remove and return head node data of the Linkedlist
	///</summary>
	template <typename T>
	T LinkedList<T>::RemoveHead() {
		Node* currentNode = head;
		LinkedList<T>::EmptyListException();   // to handle empty list input exception                      
		T currentNodeData = head->data; //storing the data as needed to return the value after deletion of head

		//check to see if only one node is present in LinkedList and deleting that node
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			currentNode = head->next;
			currentNode->prev = nullptr;
			head->next = nullptr; //head->prev is already nullptr as it is head of LinkedList
			delete head;
			head = currentNode;
		}

		NodeCount = NodeCount--;
		return currentNodeData;
	};

	///<summary>
	///  RemoveTail()  API to remove and return tail node of the Linkedlist
	///</summary>
	template <typename T>
	T LinkedList<T>::RemoveTail() {
		Node* currentNode = tail;
		LinkedList<T>::EmptyListException();  // to handle empty list input exception
		T currentNodeData = tail->data; //storing the data as needed to retuen the value after deletion of tail

		//check to see if only one node is present in LinkedList and deleting that node
		if (tail->prev == nullptr) {
			delete tail;
			tail = nullptr;
			head = nullptr;
		}
		else {
			currentNode = tail->prev;
			currentNode->next = nullptr;
			tail->prev = nullptr; //tail->next is already nullptr as it is tail of LinkedList
			delete tail;
			tail = currentNode;
		}

		NodeCount = NodeCount--;
		return currentNodeData;
	};

	///<summary>
	///  Add(...)  API to add node to a specific position of the Linkedlist and return operation status
	///</summary>
	template <typename T>
	string LinkedList<T>::Add(const T& val, int p) {
		Node* newNode = new Node; //allocate memory for new node at head
		newNode->data = val;      //assign data to new node
		newNode->prev = nullptr;  //Set prev of new node to nullptr
		newNode->next = nullptr;  //Set next of new node to nullptr

		/* Find node position */
		Node* currentNode = LinkedList<T>::SearchNode(p);
		Node* prevNode = currentNode->prev;

		/* If node position found is at first then AddHead */
		if (currentNode->prev == nullptr)
			LinkedList<T>::AddHead(val);       // also the logic can be used that if (p==0)


		/* If node position found is at last then AddTail
		else if (currentNode->next == nullptr)
		LinkedList::AddTail(val);   // also the logic can be used that if (p== Length-1), after Length implementation */


		/* If node position found is after any specific node */
		else
		{
			newNode->prev = prevNode;
			newNode->next = currentNode;
			prevNode->next = newNode;
			currentNode->prev = newNode;
			NodeCount = NodeCount++;
		}

		int NewNodePos = LinkedList<T>::FindNodePos(val);
		if (NewNodePos == p) {
			cout << val << " succesfully added to specific location: " << p << endl;
			return operation_status(E_SUCCESS);
		}
		else {
			//throw (string)"Exception caught: Failed to add node.";
			return operation_status(E_FAILURE);
		}
	};

	///<summary>
	///  Remove(...)  API to remove node from a specific position of the Linkedlist and return the node data
	///</summary>
	template <typename T>
	T LinkedList<T>::Remove(int p) {

		/* Find node position */
		Node* currentNode = LinkedList<T>::SearchNode(p);
		T RemovedNodeData = currentNode->data;
		Node* prevNode = currentNode->prev;
		Node* nextNode = currentNode->next;
		int flag = E_FAILURE;

		/* If node position found is at first then RemoveHead */
		if (currentNode->prev == nullptr) {
			LinkedList<T>::RemoveHead();       // also the logic can be used that if (p==0)
			if (nextNode->prev == nullptr) flag = E_SUCCESS;
		}

		/* If node position found is at last then RemoveTail */
		else if (currentNode->next == nullptr) {
			LinkedList<T>::RemoveTail();   // also the logic can be used that if (p== Length-1), after Length implementation
			if (prevNode->next == nullptr) flag = E_SUCCESS;
		}

		/* If node position found is after any specific node */
		else {
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			currentNode->prev = nullptr;
			currentNode->next = nullptr;
			delete currentNode;
			currentNode = nullptr;
			if (LinkedList<T>::FindNodePos(nextNode->data) == p) { 
				flag = E_SUCCESS; 
				NodeCount = NodeCount--;
			}
		}

		if (flag == E_SUCCESS) {
			cout << RemovedNodeData <<" succesfully removed from specific location : " << p << endl; 
			return RemovedNodeData;
		}
		else
			throw (string)"Exception caught: Failed to remove node.";
	};

	///<summary>
	///  Length()  API to return the no of nodes present in the Linkedlist
	///</summary>
	template <typename T>
	int  LinkedList<T>::Length() {
		//Node* currentNode = head;  // Exception: head is containing some garbage value
		//int NodeCount = 0;

		///* To count from head to tail set current node at head
		//   and iterate till it reaches tail->next i.e.nullpointer */
		//while (currentNode != nullptr) {
		//	currentNode = currentNode->next;
		//	NodeCount++;
		//}
		//return NodeCount;
		return NodeCount;
		cout << endl;
	};

	///<summary>
	///  Destroy()  API to destroy the entire Linkedlist
	///</summary>
	template <typename T>
	void LinkedList<T>::Destroy() {
		Node* currentNode = head;

		/* To count from head to tail set current node at head
		   and iterate till it reaches tail->next i.e.nullpointer */
		while (currentNode != nullptr) {
			//Node* prevNode = currentNode;
			currentNode = currentNode->next;
			delete head;
			head = nullptr;
			NodeCount = NodeCount--;
			head = currentNode;
		}
		tail = nullptr;

		/*if (LinkedList<T>::Length() == 0)*/
		if (NodeCount == 0) {
			cout << "\n Entire Linked List is successfully destroyed" << endl;
		}
	};

	///<summary>
	///  FindNodePos(...)  API to find the return the node position as per the provided node data.
	///</summary>
	template <typename T>
	int  LinkedList<T>::FindNodePos(const T& val) {
		Node* currentNode = head;
		T currentNodeData = currentNode->data;
		int index = 0;
		while (currentNode != nullptr) {
			if (currentNodeData == val) { return index; }
			currentNode = currentNode->next;
			currentNodeData = currentNode->data;
			index++;
		}
		if (currentNode == nullptr) {
			throw (string)"Exception caught: Invalid data input.";
			//return E_INVALID_DATA_INPUT;
		}
		return 0;
	};

	///<summary>
	///  Get(...)  API to return the node data from a given position 'p' but shall not remove the node from the Linkedlist
	///</summary>
	template <typename T>
	T LinkedList<T>::Get(int p) {
		Node* currentNode = head;
		int index = 0;
		if (currentNode == nullptr) 
			throw (string)"Exception caught: Invalid position input";

		while (index != p) {
			currentNode = currentNode->next;
			index++;
		}
		return currentNode->data ;
	}

	template<typename T>
	typename void LinkedList<T>::Reverse()
	{
		Node* currentNode = head;
		Node* prevNode = nullptr;
		Node* nextNode = nullptr;

		//while (currentNode != nullptr) {
		//	nextNode = (currentNode != tail) ? currentNode->next : nullptr;
		//	prevNode = (currentNode != head) ? currentNode->prev : nullptr;

		//	// reversing the next and prev pointers of the currentNode
		//	currentNode->next = prevNode;
		//	currentNode->prev = nextNode;

		//	// changing the currentNode
		//	currentNode = nextNode;
		//}

		while (currentNode != nullptr) {
			nextNode = currentNode->next; // Assigns nextNode to the current node’s next node
			currentNode->next = prevNode; // Assigns current node to the previous node’s next node

			prevNode = currentNode;       // Increments previous node to current node
			currentNode = nextNode;       // Increments current node to temp node
		}
		tail = this->head;
		this->head = prevNode;
	}

	template<typename T>
	typename void LinkedList<T>::RemoveNodes(int p, int n, Direction)
	{
		Direction dir{};
		int pos = p+n;
		if(dir == Succeeding){
			while (p < pos)
			{
				Remove(p);
				p++;
			}
	}
		if(dir == Preceeding)
			while (p > pos)
			{
				Remove(p);
				p--;
			}
	}

	///<summary>
	///  SearchNode(...)  API to return the node pointer from a given position 'p' in the Linkedlist
	///</summary>
	template<typename T>
	typename LinkedList<T>::Node* LinkedList<T>::SearchNode(int p)
	{
		Node* currentNode = head;
		int index = 0;
		while (currentNode != nullptr) {
			if (index == p) return currentNode;
			currentNode = currentNode->next;
			if (currentNode == nullptr) {
				throw (string)"Exception caught: Invalid position input";
			}
			index++;
		}
		return currentNode;
	};

	///<summary>
	///  displayLinkedList()  API to display the Linkedlist 
	///</summary>
	template <typename T>
	void LinkedList<T>::displayLinkedList() {
		Node* currentNode = head;
		int index = 0;

		/* To display LinkedList from head to tail set current node at head
		   and iterate till it reaches tail->next i.e.nullpointer          */
		   //cout << "[NULL]" << " <=> ";
		while (currentNode != nullptr) {
			//cout << "Node Data: " << currentNode->data << ", " << "Node position: " << index << " ; " <<endl;
			cout << currentNode->data << "[" << index << "] <=> ";
			currentNode = currentNode->next;
			index++;
		}
		cout << "[NULL]";
		cout << endl;
	};

	///<summary>
	///  EmptyListException()  API to handle empty list exceptions
	///</summary>
	template <typename T>
	void LinkedList<T>::EmptyListException()            
	{
		if (head == nullptr || tail == nullptr)
			throw (string)"Exception caught: List is empty.";
	};

	///<summary>
	/// <code>operator+=(...)</code> API to append one linkedlist at the end of another linkedlist
	///</summary>
	template <typename T>
	LinkedList<T>& LinkedList<T>::operator+=(LinkedList<T>& list) {

		//if both present list and given list are empty
		if ((head == nullptr || tail == nullptr) && (list.head == nullptr || list.tail == nullptr)) {
			throw (string)"Exception caught : Both lists are empty.";
		}

		//if given list is empty return present list
		else if (list.head == nullptr || list.tail == nullptr) {
			return *this;
		}

		//if both lists are present or present list is empty
		else {
			Node* currentNode = list.head;
			while (currentNode != nullptr) {
				this->AddTail(currentNode->data);
				currentNode = currentNode->next;
			}
			return *this;
		}
	};

	///<summary>
	///  begin() const  to set the Iterator of Linkedlist to point at head node.
	///</summary>
	template <typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
		
		if (head == nullptr) {
			throw (string)"Empty List to iterate!";
		}
		Iterator it(head);
		return it;
	};

	///<summary>
	///  end() const  to set the Iterator to point just after the end node of Linkedlist.
	///</summary>
	template <typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::end() const {

		if (tail == nullptr) {
			throw (string)"Empty List to iterate!";
		}
		Iterator it(tail->next);
		return it;
	};

	///<summary>
	///  next(...)  to set the iterator at the position mentioned next of the current position.
	///</summary>
	template <typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::next(Iterator it, int p) {

		for (auto i = 0; i < p; i++) {
			++it;
		}
		return it;
	};

	///<summary>
	///  prev(...)  to set the iterator at the position mentioned previous of the current position.
	///</summary>
	template <typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::prev(Iterator it, int p) {

		for (auto i = 0; i < p; i++) {
			--it;
		}
		return it;
	};

	///<summary>
	///  ~LinkedList()  destructor of  LinkedList  class.
	///</summary>
	template <typename T>
	LinkedList<T>::~LinkedList() {

		LinkedList<T>::Destroy();

		if (head != nullptr || tail != nullptr) {
			delete head;
			head = nullptr;
			delete tail;
			tail = nullptr;
		}
	};