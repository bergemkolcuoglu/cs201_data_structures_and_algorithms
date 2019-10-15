#include <iostream>
#include "TestBed.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include <ctime>
#include <algorithm>

using namespace std;

TestBed::TestBed() {
}

TestBed::~TestBed() {
	delete algorithm;
}

void TestBed::setAlgorithm(int type, int k) {
	if (type == 1) {
		algorithm = new AlgorithmSortAll(k) ;
	} else if (type == 2) {
		algorithm = new AlgorithmSortK(k);
	}
}

void TestBed::execute() {
	algorithm->setNumbers();
	int result = 0;
	clock_t start = clock();
	result = algorithm->select();
	clock_t end = clock();
	double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	cout << "Result: " << result << endl;
	cout << "Duration(sec): " << cpu_time << endl;


}
