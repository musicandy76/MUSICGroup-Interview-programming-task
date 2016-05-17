#pragma once
#include "Job.h"
#include <list>


using namespace std;
class JobProcessor
{
public:
	JobProcessor();
	~JobProcessor();
	void setData(list<Job>   jobsToWrite);
	void execute();
	int jobSize;
private :
	
	
};