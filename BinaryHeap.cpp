#include "BinaryHeap.h"
// #include <map>

// template<typename ElemType, typename Comp>
// void BinaryHeap<ElemType, Comp>::insert(const ElemType& x) {
	// checkSize( );
	//walk up (establish heap order now)
	// int hole = curSize++;
	// for ( ; hole > 0 && comp(array[(hole-1)/2], x) > 0;
	// hole = (hole-1)/2)
	// array[hole] = array[(hole-1)/2];
	// array[hole] = x;
// }

// template<typename ElemType, typename Comp>
// void BinaryHeap<ElemType, Comp>::deleteMin() throw(EmptyHeap) {
	// array[0] = array[ --curSize ]; //decrease size
	// walkDown(0);
// }

// template<typename ElemType, typename Comp>
// void BinaryHeap<ElemType, Comp>::walkDown(int hole) {
	// int child; ElemType key = array[hole];
	// for ( ; 2*hole+1 < curSize; hole = child) {
		// child = 2*hole+1;
		// if (child != curSize-1 &&
		// comp(array[child], array[child+1]) > 0)
		// child++; // right child = 2*hole+2
		// if (comp(key, array[child]) > 0) array[hole]=array[child];
		// else break;
	// }
	// array[hole] = key;
// }


