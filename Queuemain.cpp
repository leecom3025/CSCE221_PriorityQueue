// #include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include "PQVector.h"
using namespace std;

int main() {
	PriorityQueue<string> pq;
	PQVector<string> pqv;
	
		string elem;
	
	int what = 1;
	cout << "1. Priority Queue with Binary Heap\n2. Priority Queue with Vector\nChoic: ";
	cin >> what;
if(what ==1){
	string again, right, left;
	left = 'y'; 	right = 'Y'; 	again = 'Y';
	

	
	elem = "abc"; pq.insertItem(3, elem);
	elem = "2ab"; pq.insertItem(4, elem);
	elem = "bbc"; pq.insertItem(1, elem);
	elem = "cnn"; pq.insertItem(5, elem);
	elem = "ddn"; pq.insertItem(6, elem);
	elem = "eda"; pq.insertItem(7, elem);
	elem = "ggg"; pq.insertItem(9, elem);
	elem = "kkk"; pq.insertItem(10, elem);
	elem = "lll"; pq.insertItem(11, elem);
	elem = "mmm"; pq.insertItem(12, elem);

	// elem = "qqq"; pq.insertItem(16, elem);
	
	cout << "\nAlready inserted heaps\n";
	cout << "===============\n";
	pq.printPQ();
	cout << "===============\n";
	// cout << "---------Before Removing Min\n";
	// cout << "minElement: " << pq.minElement() << endl;
	// cout << "minKey: " << pq.minKey() << endl;
	// cout << "Min element removed." << endl;
	// pq.remove(pq.min());
	// cout << "--------After removing min\n";	
	// cout << "minElement: " << pq.minElement() << endl;
	// cout << "minKey: " << pq.minKey() << endl;	
	
	// pq.decreaseKey(pq.min(),pq.minKey());
	
	// cout << "--------After decreasing loc 3\n";
	// pq.decreaseKey(3,6);

	// cout << "================\n";
	
	// pq.decreaseKey(pq.minKey(), pq.min());

	
	
	while (again.compare(right) == 0 || again.compare(left) == 0)
	{
		char choi;
		cout << "What would you like to do? (Press corresponding number and hit enter)"<<endl;
		cout << "1. Insert items into a priority queue."<<endl;
		cout << "2. Print out priority queue."<<endl;
		cout << "3. Remove an item with a specific location."<<endl;
		cout << "4. Find item with minimum key."<<endl;
		cout << "5. Decrease Key."<<endl;
		cout << "6. Build Priority Queue." << endl;
		cout << "7. Exit."<<endl;
		cout << "Choie: ";
		cin >> choi;
		
		if(choi == '1')
		{
			int key;
			char element[255];
			
			cout << "Key: ";
			cin >> key;
			cout << "Elem: ";
			cin >> element;
			pq.insertItem(key, element);
		}
		else if(choi == '2')
		{
			pq.printPQ();
		}
		else if(choi == '3')
		{
			int loc;
			cout << "Enter Location at which you'd like to remove an item (Enter integer and press enter): ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin >> loc;
			pq.remove(loc);
			cout <<"Current Priority Queue:\n";
			pq.printPQ();
		}
		else if(choi == '4')
		{
			cout << "Minimum Element    : " << pq.minElement() << endl;
			cout << "Minimum Element Key: " << pq.minKey() << "."<<endl;
			
		}
		else if(choi == '5')
		{
			int position,keyy;
			cout << "Enter the Location Index you would like to decrease:";
			cin >> position;
			cout << "Note that the Key will be searched with the location\n";
			pq.decreaseKey(position, 0);
			pq.printPQ();
		}
		else if(choi == '6')
		{
			pq.createPriorityQueue();
			pq.printPQ();
		}
		else if(choi == '7')
		{
			cout <<endl<< "Exit"<<endl;
			break;
		}
		else
			{cout << "INVALID NUMBER" <<endl; break;}
		cout <<endl;
	}
	}else if(what ==2){
		cout << "\nAlready inserted vectors\n";
		cout << "===============\n";
		elem = "abc"; pqv.insertItem(4, elem);
		elem = "2ab"; pqv.insertItem(3, elem);
		elem = "bbc"; pqv.insertItem(7, elem);
		elem = "cnn"; pqv.insertItem(6, elem);
		elem = "ddn"; pqv.insertItem(10, elem);
		elem = "eda"; pqv.insertItem(2, elem);
		elem = "ggg"; pqv.insertItem(1, elem);
		elem = "kkk"; pqv.insertItem(9, elem);
		elem = "lll"; pqv.insertItem(15, elem);
		elem = "mmm"; pqv.insertItem(25, elem);
		elem = "qqq"; pqv.insertItem(16, elem);
		cout << "===============\n";
		// pqv.see();
		// cout << "---------\n";
		// cout << "Minimum element Key: " << pqv.minKey() << endl;
		// pqv.see();
		string va, vr, vl;
		vr = 'y'; vl = 'Y'; va = 'Y';
		while (va.compare(vr) == 0 || va.compare(vl) == 0)
		{
			char choi;
			cout << "What would you like to do? (Press corresponding number and hit enter)"<<endl;
			cout << "1. Insert items into a priority queue."<<endl;
			cout << "2. Print out priority queue."<<endl;
			cout << "3. Remove an item with a specific location."<<endl;
			cout << "4. Find item with minimum key."<<endl;
			cout << "5. Decrease Key."<<endl;
			cout << "6. Exit.";
			cout << "Choice: ";
			cin >> choi;
		
		if(choi == '1')
		{
			int key;
			char element[255];
			
			cout << "Key: ";
			cin >> key;
			cout << "Elem: ";
			cin >> element;
			pqv.insertItem(key, element);
			pqv.build();
		}
		else if(choi == '2')
		{
			pqv.see();
		}
		else if(choi == '3')
		{
			int loc;
			cout << "Enter Location at which you'd like to remove an item (Enter integer and press enter): ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin >> loc;
			cout << "Remove comparison: " << pqv.remove(loc) << endl;
			cout <<"Current Priority Queue:\n";
			pqv.see();
		}
		else if(choi == '4')
		{
			pqv.build();
			cout << "Minimum Element    : " << pqv.minElement() << endl;
			cout << "Minimum Element Key: " << pqv.minKey() <<endl;
			
		}
		else if(choi == '5')
		{
			int position,keyy;
			cout << "Enter the Location Index you would like to decrease:";
			cin >> position;
			cout << "Note that the Key will be searched with the location\n";
			pqv.decreaseKey(position, 0);
			cout << "DecreaseKey Comparison: 0\n";
		}
	
		else if(choi == '6')
		{
			cout <<endl<< "Exit"<<endl;
			break;
		}
		else
			{cout << "INVALID NUMBER" <<endl; break;}
		cout <<endl;
		}
		
		
	}else{ cout << "Wrong Number program terminated";
		exit(0);
	}
	
	return 0;
}
