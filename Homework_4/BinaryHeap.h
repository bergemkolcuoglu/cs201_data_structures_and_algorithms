#ifndef __BINARYHEAP__
#define __BINARYHEAP__

class BinaryHeap {

public:
	BinaryHeap(int); 
	~BinaryHeap();
	void insert(int);
	void deleteMin();
	int getMin();

private:
	int *heap;
	int size;
	int capacity;
	void percolateDown(int);
	void swap(int, int);
	void percolateUp(int);
};

#endif