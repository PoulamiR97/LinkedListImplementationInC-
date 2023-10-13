#include<iostream>
#include<stdexcept>
#include <string>
#include <chrono>
#include<time.h>
#include "ZuruLinkedList.h"
#include "ErrorCodes.h"
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {

	try {

		 //***** Testcase of ZuruLinkedList *****

		//
		//LinkedList<int> UserList1;

		// Start measuring time
		//time_t begin, end;
		//time(&begin);
		//auto start = high_resolution_clock::now();

		//for (int i = 0; i < 2000000; ++i) {
		//	UserList1.AddHead(i);
		//}
		//cout << "No of nodes in the List: " << UserList1.Length() << endl;

		//cout << "Removed node: " << UserList1.Remove(1000000) << endl;
		//cout << "No of nodes in the List: " << UserList1.Length() << endl;

		//UserList1.Destroy();
		//cout << "No of nodes in the List: " << UserList1.Length() << endl;

		//auto stop = high_resolution_clock::now();
		//auto duration = duration_cast<seconds>(stop - start);
		//cout << "\nTime taken by function : " << duration.count() << " milliseconds" << endl;

		// Stop measuring time and calculate the elapsed time
		//time(&end);
		//time_t elapsed = end - begin;

		//
		//cout << "Time measured: " << elapsed << " seconds." << endl;
		//
		//UserList1.AddTail("Olivia");
		//UserList1.AddHead("Sophia");
		//UserList1.AddTail("Amelia");
		//UserList1.AddHead("Evelyn");
		//UserList1.AddTail("Harper ");
		//UserList1.AddHead("Camila");

		//cout << "Value of removed head: " << UserList1.RemoveHead() << endl;
		//cout << "Value of removed tail: " << UserList1.RemoveTail() << endl;

		//UserList1.Add("Aubrey", 1);
		//cout << "Removed node: " << UserList1.Remove(0) << endl;

		//LinkedList<string> UserList2;
		//		/*UserList2.AddTail("Aa");
		//		UserList2.AddHead("Bb");
		//		UserList2.AddTail("Cc");
		//		UserList2.AddHead("Dd");
		//		UserList2.AddTail("Ee");
		//		UserList2.AddHead("Ff");
		//		UserList2.AddHead("Gg");*/

		//UserList1 += UserList2;
		//UserList2.Destroy();
		//UserList1.displayLinkedList();
		//cout << "No of nodes in the List: " << UserList2.Length() << endl;
	 //   cout << endl << endl << endl;


		/*vector<string> v1{ "Diana","Ba", "Bc", "Cab" , "Bulti"};
		vector<int> v2{ 1, 5, 8, 12, 9 };

		sort(v1.begin(), v1.end());
		for (auto& x : v1) { cout<< x << endl; }


		sort(v2.begin(), v2.end());
		for (auto& y : v2) { cout << y << endl; }*/

		LinkedList<string> UserList2;
		UserList2.AddTail("Aa");
		UserList2.AddHead("Bb");
		UserList2.AddTail("Cc");
		UserList2.AddHead("Dd");
		UserList2.AddTail("Ee");
		UserList2.AddHead("Ff");
		UserList2.AddHead("Gg");
		UserList2.AddHead("Hh");
		UserList2.AddHead("Ii");
		UserList2.AddHead("Jj");
		UserList2.displayLinkedList();

		/*UserList2.Reverse();
		UserList2.displayLinkedList();*/

		UserList2.RemoveNodes(6, 3, Preceeding);
		UserList2.displayLinkedList();


	}

	catch (string& ex) {
		cout << ex << endl;
	}

	catch (...) {
		cout << "Error" << endl;
	}

	return 0;
}