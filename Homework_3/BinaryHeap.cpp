#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
	this->capacity = capacity;
	heap = new int[capacity + 1];
	size = 0;
}

BinaryHeap::~BinaryHeap() {
	delete[] heap;
}

void BinaryHeap::insert(int element) {
	if (size == capacity)
		return;
	else {
		size++;
		heap[size - 1] = element;
		percolateUp(size - 1);
	}
}

void BinaryHeap::deleteMin() {
	if (size <= 1)
		return;
	heap[0] = heap[size - 1];
	size--;
	if (size > 0) {
		percolateDown(0);
	}
}

int BinaryHeap::getMin() {
	if (size == 0) {
		return -1;
	}		
	else {
		return heap[0];
	}	
}

void BinaryHeap::percolateDown(int hole) {
	int min;
	int leftChild = 2 * hole + 1;
	int rightChild = 2 * hole + 2;

	if (leftChild >= size && rightChild >= size) {
		return;
	}
	if ((rightChild >= size && leftChild < size) || (rightChild < size && heap[leftChild] <= heap[rightChild])) {
		min = leftChild;
	}
	if (rightChild < size && heap[leftChild] > heap[rightChild]) {
		min = rightChild;
	}
	if (heap[min] < heap[hole]) {
		swap(min, hole);
		percolateDown(min);
	}
}

void BinaryHeap::swap(int i, int j) {
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
}

void BinaryHeap::percolateUp(int hole) {
	if (hole == 0)
		return;
	int parent = (hole - 1) / 2;
	if (heap[parent] > heap[hole]) {
		swap(parent, hole);
		percolateUp(parent);
	}
}

