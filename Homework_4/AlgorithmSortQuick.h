#include "SelectionAlgorithm.h"

class AlgorithmSortQuick : public SelectionAlgorithm
{
public:
	AlgorithmSortQuick(int k);
	~AlgorithmSortQuick();
	void setNumbers();
	int select();
private:
	void insertionSort(int numbers[]);
	int partition(int numbers[], int left, int right);
	int quickSelect(int numbers[], int first, int last, int k);
};

