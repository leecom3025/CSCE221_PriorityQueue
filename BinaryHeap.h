#include "RuntimeException.h"
#include <iostream>

template<typename ElemType, typename Comp>
class BinaryHeap {
		class EmptyHeap : public RuntimeException {
		   public:
			 EmptyHeap() : RuntimeException("Empty Heap") {}
		   };
	private:
		Comp comp; // Comp is a comparator class
		// and comp(a,b) will compare arguments a and b
		int curSize; //number of elements in heap
		ElemType *array; //(dynamic) heap array
		int length; //the length of the array
		bool orderOK;
		static const int DEF_SIZE = 8;
		
		void getNewArray(int newSize) {
			array = new ElemType[newSize];
			length = newSize;
		}
	
	public: // templated class BinaryHeap (cont)
		BinaryHeap(int size = DEF_SIZE) { //constructor
			curSize = 0;
			orderOK = true;
			getNewArray(size);
			}
		ElemType& findMin() throw(EmptyHeap) {
			if ( isEmpty() ) throw EmptyHeap();
			if (! orderOK) buildHeap();
			return array[0];
		}
		
		bool isEmpty( ) const {  return curSize == 0; }
		
		void buildHeap(){
			for (int i = (curSize-2)/2; i >= 0; i--) walkDown(i);
			orderOK = true;
		}
		
		void checkSize( ) {
			if (curSize == length) {
				ElemType *oldArray = array;
				getNewArray(2*curSize);
				for (int i = 0; i < curSize; i++)
				array[i] = oldArray[i];
				delete [] oldArray;
			}
		}
		
		void decreaseKey(int loc, int k){
			int i =0;
			while(loc != array[i].getLoc()){
				++i; //loc
			}
			
			// cout << "=====Before decrease=====\n"; 
			// print();
	
			// cout << "----------\n" <<"I ::: " << i << endl;
			
			array[i].setKey(array[i].getKey()-1);
			walkUp(i);
			// cout << "----------\n";
			// print();
			
		}
		
		void insert(const ElemType& x){
			checkSize( );
			//walk up (establish heap order now)
			int hole = curSize++;
			for ( ; hole > 0 && comp(array[(hole-1)/2], x) > 0; hole = (hole-1)/2)
				array[hole] = array[(hole-1)/2];
			array[hole] = x;
		}
		
				
		void deleteMin() throw(EmptyHeap){			
			array[0] = array[ --curSize ]; //decrease size
			walkDown(0);
		}
		
		void remove(int loc) throw(EmptyHeap){
			int i =0;
			while(loc != array[i].getLoc()){
				// cout << "I: " << i << endl;
				++i; //loc
			}
			// if(i==0){
				// array[0] = array[curSize--];
				// walkDown(0,0);
			// }else{
			array[i] = array[--curSize];
			walkDown(0,0);
			// }
		}
		
		
		void walkDown(int hole, int rcomp){
			int child;
			// int rcomp = 0;
			ElemType key = array[hole];
			for ( ; 2*hole+1 < curSize; hole = child) {
				++rcomp;
				child = 2*hole+1;
				if (child != curSize-1 && comp(array[child], array[child+1]) > 0){
					++rcomp;
					child++; // right child = 2*hole+2
				}
				if (comp(key, array[child]) > 0) {
					++rcomp;
					array[hole]=array[child];
				}else break;
			}
			array[hole] = key;
			cout << "***Remove Comparison: " << rcomp << endl;
		}
		
		void walkDown(int hole){
			int child;
			ElemType key = array[hole];
			for ( ; 2*hole+1 < curSize; hole = child) {
				child = 2*hole+1;
				if (child != curSize-1 && comp(array[child], array[child+1]) > 0){
					child++; // right child = 2*hole+2
				}
				if (comp(key, array[child]) > 0) {
					array[hole]=array[child];
				}else break;
			}
			array[hole] = key;
		}
		
		
		void walkUp(int hole){
			int decomp = 0;
			int parent, nei;
			ElemType x = array[hole];
			for( ; hole > 0; hole = parent){
				++decomp;
				parent = (hole-1)/2;
				if(++decomp && hole%2 ==0){
					nei = hole-1;
					++decomp;
					if( comp(array[hole],array[nei])<0){
						ElemType temp = array[nei];
						array[nei] = array[hole];
						array[hole] = temp;
					}
				}else if (hole%2 ==1) {
					nei = hole+1;
					if( comp(array[nei], array[hole])<0){
						ElemType temp = array[nei];
						array[nei] = array[hole];
						array[hole] = temp;
					}
				}
				if (++decomp && comp(x, array[parent])<0){
					array[hole] = array[parent];
					
				}else break;
			}
			array[hole] = x;
		
			// for ( ; hole > 0 && ++decomp && comp(array[(hole - 1) / 2], x) > 0; hole = (hole - 1) / 2){
				// cout << "LOL\n";
				// ++decomp;
				// array[hole] = array[(hole-1)/2];
				
			  // }
			 // array[hole] = x;
				cout << "***DecreaseKey Comparison: " << decomp << endl;
		
		}
		
		void print(){
			for(int i =0; i<curSize; i++){
				if(array[i].getKey()==0 && array[i].getLoc()==0){}else
				cout << "E" << i << ": " << array[i].getElem() << " " <<array[i].getKey() << " " <<array[i].getLoc() << endl;
			}
		}
};









