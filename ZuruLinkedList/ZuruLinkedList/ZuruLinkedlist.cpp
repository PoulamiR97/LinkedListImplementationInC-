//#include<iostream>
//#include<stdexcept>
//#include <string>
//#include <chrono>
////#include<time.h>
//#include "ZuruLinkedList.h"
//#include "ErrorCodes.h"
//
//using namespace std;
//using namespace std::chrono;
//
//int main() {
//
//	try {
//
//        // ***** Testcase of ZuruLinkedList *****
//
//		LinkedList<string> UserList1;
//		UserList1.AddTail("Olivia");
//		UserList1.AddHead("Sophia");
//		UserList1.AddTail("Amelia");
//		UserList1.AddHead("Evelyn");
//		UserList1.AddTail("Harper ");
//		UserList1.AddHead("Camila");
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying primary Userlist1 of type string" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList1.displayLinkedList();
//		cout << "No of nodes in the Userlist1: " << UserList1.Length() << endl;
//		cout << endl;
//
//
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Removing head and tail on UserList1" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Value of removed head: " << UserList1.RemoveHead() << endl;
//		cout << "Value of removed tail: " << UserList1.RemoveTail() << endl;
//		cout << endl;
//
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist1 after adding node" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList1.Add("Aubrey", 1);
//		UserList1.displayLinkedList();
//		cout << endl;
//
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist1 after removing node" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Removed node: " << UserList1.Remove(0) << endl;               
//		UserList1.displayLinkedList();
//		cout << endl;
//
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist1 after all operations" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList1.displayLinkedList() ;
//		cout << "No of nodes in the List: " << UserList1.Length() << endl;
//		cout << endl << endl << endl;
//
//
//		
//
//		LinkedList<string> UserList2;
//		UserList2.AddTail("Aa");
//		UserList2.AddHead("Bb");
//		UserList2.AddTail("Cc");
//		UserList2.AddHead("Dd");
//		UserList2.AddTail("Ee");
//		UserList2.AddHead("Ff");
//		UserList2.AddHead("Gg");
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying primary Userlist2 of type string " << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList2.displayLinkedList();
//		cout << endl<< endl;
//
//
//
//
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Illustrating copy constructor" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		LinkedList<string> UserList3(UserList1);
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist3 copying from UserList1" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList3.displayLinkedList();
//
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Illustrating copy assignment operator" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList3 = UserList2;
//		cout << "-------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist3 again after assigning UserList2" << endl;
//		cout << "-------------------------------------------------------------" << endl;
//		UserList3.displayLinkedList();
//		cout << endl << endl;
//
//
//
//
//
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Illustrating move constructor" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		LinkedList<string> UserList4{move( UserList2) };
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist4 moving from UserList2" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		UserList4.displayLinkedList();
//
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Illustrating move assignment operator" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		UserList2 = move(UserList4);
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Displaying Userlist2 again after moving and assigning from UserList4" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		UserList2.displayLinkedList();
//		cout << endl << endl;
//
//
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Displaying after appending UserList1 with UserList2" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		UserList1 += UserList2;
//		UserList1.displayLinkedList();
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Destroying UserList2 after appending" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		UserList2.Destroy();
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Getting value UserList1 at position 8 : ";
//		cout << UserList1.Get(8) << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << endl << endl;
//
//
//
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Displaying UserList1 using Iterator" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//
//		LinkedList<string>::Iterator it = UserList1.begin();
//		for (; it != UserList1.end(); ++it) {
//			cout <<"|"<< *it << "|";
//		}
//		cout << endl;
//		cout << endl << endl;
//
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Displaying next 3rd node from beginning using next() method " << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		it = UserList1.begin();
//		LinkedList<string>::Iterator it2 = UserList1.next(it, 3);
//		cout << *it2;
//		cout << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Again back to first node  from 3rd node using prev() method" << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		LinkedList<string>::Iterator it3 = UserList1.prev(it2, 3);
//		cout << *it3;
//		cout << endl<< endl;
//
//
//		cout << "--------------------------------------------------------------------" << endl;
//		cout << "Displaying UserList1 using range based for " << endl;
//		cout << "--------------------------------------------------------------------" << endl;
//		for (auto x : UserList1) {
//			cout <<"|" << x << "|";
//		}
//		cout << endl << endl<< endl;
//
//
//
//		LinkedList<int> UserList5;
//
//		auto start_time = high_resolution_clock::now();
//
//		for (int i = 0; i < 2000000; ++i) {
//			UserList5.AddHead(i);
//		}
//		cout << "No of nodes in the List: " << UserList5.Length() << endl;
//			
//		cout << "Removed node: " << UserList5.Remove(1000000) << endl;
//		cout << "No of nodes in the List: " << UserList5.Length() << endl;
//			
//		UserList5.Destroy();
//		cout << "No of nodes in the List: " << UserList5.Length() << endl;
//
//		auto stop_time = high_resolution_clock::now();
//		auto duration_time = duration_cast<milliseconds>(stop_time - start_time);
//		cout << "\nTime taken by function : " << duration_time.count() << " milliseconds" << endl;
//		
//	}
//
//	catch (string& ex) {
//		cout << ex << endl;
//	}
//
//	catch (...) {
//		cout << "Error" << endl;
//	}
//
//	return 0;
//}