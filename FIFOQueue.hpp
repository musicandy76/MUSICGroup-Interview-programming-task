
#pragma once

#include "FIFOQueue.h"

using namespace std;
// This is a template FIFO Queue class that incoroprates using the STL
// standard queue

template<class t_Job>
bool FIFOQueue<t_Job>::pop(t_Job & tJob)
{
	bool bRet = false;
	unique_lock<mutex> lk(m);

	if (fifoQueue.empty() && !stopCalled)
		waitForData.wait(lk);
	if (!fifoQueue.empty() && !stopCalled)
	{
		tJob = fifoQueue.front();

		fifoQueue.pop();

		bRet = true;
	}

	return bRet;
}

template<class t_Job>
void FIFOQueue<t_Job>::stop()
{
	unique_lock<mutex> lk(m);
	stopCalled = true;
	waitForData.notify_all();
}

template<class t_Job>
void FIFOQueue<t_Job>::reset()
{
	stopCalled = false;

}


template<class t_Job>
bool FIFOQueue<t_Job>::pop_try(t_Job & tJob)
{
	bool bRet = false;
	unique_lock<mutex> lk(m);

	if (!fifoQueue.empty())
	{
		tJob = fifoQueue.front();

		fifoQueue.pop();

		bRet = true;
	}

	return bRet;
}

template <class t_Job>
bool FIFOQueue<t_Job>::push(t_Job const& elem)
{
	bool bRet = true;
	unique_lock<mutex> lk(m);

	try 
	{
		fifoQueue.push(elem);
		waitForData.notify_all();
	}
	catch(const exception&)
	{
		bRet = false;
	}

	return bRet;
}
