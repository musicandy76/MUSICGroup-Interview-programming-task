#pragma once

#include <queue>


#include <mutex>

#include <condition_variable>

using namespace std;

template <class t_Job>
class FIFOQueue 
{

private:
	queue<t_Job> fifoQueue;

	mutex g_lock;
	mutex m;	
	condition_variable waitForData;
	bool stopCalled = false;


public:

	bool pop(t_Job & tJob);
	bool pop_try(t_Job  & tJob);
	bool push(t_Job const& elem);
	void stop();
	void reset();
};
