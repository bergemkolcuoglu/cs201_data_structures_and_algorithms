#include <iostream>
#include <string>
#include <fstream>
#include "TestBed.h"

using namespace std;

int main(int argc, char *argv[]) {

	string testfile;

	if (argc < 2) {
		cout << "Enter a test file name:" << endl;
		cin >> testfile;
	}

	else {
		testfile = argv[1];
	}

	ifstream file(testfile.c_str());
	if (file.is_open()) {

		cin.rdbuf(file.rdbuf());
	}

	else {
		cout << "Error: cannot read the test file!" << endl;
		return -1;
	}

	int type = 0;
	cin >> type;
	
	int n = 0;
	cin >> n;
	
	TestBed *testbed = new TestBed();

	testbed->setAlgorithm(type, n);
	testbed->execute();
	
	delete testbed;
		
	return 0;
}
