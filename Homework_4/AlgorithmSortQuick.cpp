#include "AlgorithmSortQuick.h"
#include <iostream>

using namespace std;

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k){
	this->k = k;
}

AlgorithmSortQuick::~AlgorithmSortQuick(){
	delete[] pNums;
	pNums = 0;
}

void AlgorithmSortQuick::setNumbers(){
	cin >> n;
	pNums = new int[n];
	for (int i = 0; i < n; i++){
		cin >> pNums[i];
	}
}

int AlgorithmSortQuick::select(){
	if (n <= 10){
		insertionSort(pNums);
		return pNums[k - 1];
	} else{
		return quickSelect(pNums, 0, n - 1, k + 1);
	}
}

void AlgorithmSortQuick::insertionSort(int numbers[]){
	int i;
	for (int p = 1; p < n; p++) {
		int tmp = numbers[p];
		for (i = p; i > 0 && tmp < numbers[i - 1]; i--) {
			numbers[i] = numbers[i - 1];
		}
		numbers[i] = tmp;
	}
}

int AlgorithmSortQuick::partition(int numbers[], int left, int right){
	int pivot = numbers[right];    
	int i = (left - 1); 
	for (int j = left; j <= right - 1; j++){		 
		if (numbers[j] <= pivot){
			i++;
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}
	}
	int temp2 = numbers[i + 1];
	numbers[i + 1] = numbers[right];
	numbers[right] = temp2;
	return (i + 1);		
}


int AlgorithmSortQuick::quickSelect(int numbers[], int left, int right, int k){
	if (left == right){
		return numbers[left];
	}

	int number = partition(numbers, left, right);
	int line = number - left + 1;
	
	if (line == k){
		return numbers[number];
	}
	if (k < line){
		return quickSelect(numbers, left, number - 1, k);
	}
	if (k > line){
		return quickSelect(numbers, number + 1, right, k - line);
	}
}
