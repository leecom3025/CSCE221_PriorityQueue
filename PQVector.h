#include <vector>
#include <iostream>
#include "RuntimeException.h"
#include "PriorityQueue.h"
using namespace std;

// template<typename ElemType>
// class Item {
	// private:
		// int key;
		// ElemType elem;
		// int index;
	// public:
		// Item(const int k=0, const ElemType& e=ElemType(), const int i=0)
		// : key(k), elem(e), index(i)  {}
		// const int getKey() const { return key; }
		// const int getLoc() const { return index; }
		// const ElemType& getElem() const { return elem; }
		// void setLoc(const int i) { index = i;} 
		// void setKey(const int k) { key = k; }
		// void setElem(const ElemType& e) { elem = e; }
// };

template<typename ElemType>
class PQVector {
	class EmptyPriorityQueue : public RuntimeException {
	   public:
		 EmptyPriorityQueue() : RuntimeException("Empty PriorityQueue") {}
	  };
	protected: 
		typedef Item<ElemType> Item;
	private:
	
		vector<Item> v;                     //unsorted array 
		static const int DEF_SIZE = 8;
	public: // class PriorityQueue cont.
		PQVector(int size = DEF_SIZE){}
		int size(){return v.size();}
		bool isEmpty() const{ if(v.size()==0){ return true;}}
				
		void insertItem(const int k, const ElemType& e){
			int i =v.size();
			v.push_back(Item(k,e,i));
			cout << "V" << i <<": "<<v[i].getElem() << " " 
			<< v[i].getKey() << " " 
			<< v[i].getLoc() << endl;

		}
		
		void build() throw(EmptyPriorityQueue) {
			// if (isEmpty()) throw EmptyPriorityQueue();
			for(int i =0; i<v.size(); i++){
				for(int j=0; j<v.size(); j++){
					if(v[i].getKey() < v[j].getKey()){
						int temp = v[i].getKey();
						v[i].setKey(v[j].getKey());
						v[j].setKey(temp);
					}
				}
			}	
		}
		
		const int minKey() throw(EmptyPriorityQueue) {
			// if (isEmpty()) throw EmptyPriorityQueue();
			for(int i =0; i<v.size(); i++){
				for(int j=0; j<v.size(); j++){
					if(v[i].getKey() < v[j].getKey()){
						int temp = v[i].getKey();
						v[i].setKey(v[j].getKey());
						v[j].setKey(temp);
					}
				}
			}
			return v[0].getKey();		
		}
		const int remove(int loc) throw(EmptyPriorityQueue){
			int rcmp =0;
			for(int i =0; i<v.size(); i++){
				if(v[i].getLoc() == loc){
					for(int j=loc+1; j<v.size(); j++){
						++rcmp;
						v[i] = v[j];
						++i;
					}
				}
			}
			v.pop_back();
			return rcmp;
		}
		
		const ElemType& minElement() throw(EmptyPriorityQueue) {
			// if (T.isEmpty()) throw EmptyPriorityQueue();
			return v[0].getElem();
		}
		
		void decreaseKey(int loc, int k) throw(EmptyPriorityQueue){
			// if(T.isEmpty()) throw EmptyPriorityQueue();
			for(int i =0; i<v.size(); i++){
				if(v[i].getLoc() == loc){
					v[i].setKey(v[i].getKey()-1);
				}
			}
		}
		
		void see () {
			for(int i =0; i<v.size(); i++){
				cout << "V" << i <<": "<<v[i].getElem() << " " 
				<< v[i].getKey() << " " 
				<< v[i].getLoc() << endl;
			}
		}
		//---------------------------------

		
		// void remove(int loc) throw(EmptyPriorityQueue){  //walkdown 
			// if(T.isEmpty()) throw EmptyPriorityQueue();
			// T.remove(loc);
		// }
		


		
// decreaseKey(loc, k) updates a minimum priority queue after the key k with locator loc was decreased
// createPriorityQueue() builds a minimum priority queue


};
