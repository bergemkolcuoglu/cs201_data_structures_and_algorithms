#include "SelectionAlgorithm.h"

class TestBed
{
public:
	TestBed();
	~TestBed();
	void setAlgorithm(int type, int k);
	void execute();
private:
	SelectionAlgorithm *algorithm;
};


