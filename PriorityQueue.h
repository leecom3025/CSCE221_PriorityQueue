#include "BinaryHeap.h"
#include "RuntimeException.h"
#include <vector>

template<typename ElemType>
class Item {
	private:
		int key;
		ElemType elem;
		int index;
		// Locator* loc;
	public:
		 // friend class PQVector;
		Item(const int k=0, const ElemType& e=ElemType(), const int i=0)
		: key(k), elem(e), index(i)  {}
		// {loc = new Locator(this); } //constructor
		const int getKey() const { return key; }
		const int getLoc() const { return index; }
		const ElemType& getElem() const { return elem; }
		// Locator* getLoc(){ return loc;} // not using pointer locator this time.
		void setLoc(const int i) { index = i;} 
		void setKey(const int k) { key = k; }
		void setElem(const ElemType& e) { elem = e; }
};

template<typename ElemType>
class PQComp {
public:
	int operator()(const Item<ElemType>& e1,const Item<ElemType>& e2) {
		return e1.getKey() - e2.getKey();
	}
};

template<typename ElemType>
class PriorityQueue {
	class EmptyPriorityQueue : public RuntimeException {
	   public:
		 EmptyPriorityQueue() : RuntimeException("Empty PriorityQueue") {}
	  };
	protected: 
		typedef Item<ElemType> Item;
		typedef PQComp<ElemType> PQComp;
		
	private:
		vector<Item> v;                     //unsorted array 
		BinaryHeap<Item, PQComp> T;
		static const int DEF_SIZE = 8;
	public: // class PriorityQueue cont.
		PriorityQueue(int size = DEF_SIZE) : T(size) { }
		int size(){return T.curSize;}
		
		bool isEmpty() const { return T.isEmpty(); }
		
		void insertItem(const int k, const ElemType& e){
			int i =v.size();
			v.push_back(Item(k,e,i));
			T.insert(Item(k,e,i));
		}
		
		const ElemType& minElement() throw(EmptyPriorityQueue) {
			if (T.isEmpty()) throw EmptyPriorityQueue();
			return T.findMin().getElem();
		}
		
		const int minKey() throw(EmptyPriorityQueue) {
			if (T.isEmpty()) throw EmptyPriorityQueue();
			return T.findMin().getKey();
		}
		
		void removeMin() throw(EmptyPriorityQueue) {
			if (T.isEmpty()) throw EmptyPriorityQueue();
			T.deleteMin();
		}
		
		//---------------------------------
		const int min() throw(EmptyPriorityQueue){
			if(T.isEmpty()) throw EmptyPriorityQueue();	
			return T.findMin().getLoc();
		}
		
		void remove(int loc) throw(EmptyPriorityQueue){  //walkdown 
			if(T.isEmpty()) throw EmptyPriorityQueue();
			T.remove(loc);
		}
		
		void decreaseKey(int loc, int k) throw(EmptyPriorityQueue){
			if(T.isEmpty()) throw EmptyPriorityQueue();
			
			T.decreaseKey(loc,k);
        }
		
		void createPriorityQueue(){
			 T.buildHeap();
		}	
		
		void printPQ(){
			cout << "==Item==K==L===\n";
			T.print();
		}
		
// decreaseKey(loc, k) updates a minimum priority queue after the key k with locator loc was decreased
// createPriorityQueue() builds a minimum priority queue


};
