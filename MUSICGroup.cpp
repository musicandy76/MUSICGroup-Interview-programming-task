// MUSIC Group.cpp : Defines the entry point for the console application.
//

#include "JobProcessor.h"

#include <thread>

#include <iostream>
#include <list>

list<Job>  jobsToWrite;


int main()
{
	// Test harness for the template class utlising a JobProcessor helper class to start the 
	// reader and writer threads. 
	//  This job queue is using as an exmaple mixig desk event names with an appropriate
	//  MIDI value as an exmaple. 
	Job job1;
	job1.mixingDeskEventName = "Pan Channel 1";
	job1.midiValue = 127;

	Job job2;
	job2.mixingDeskEventName = "Volume Channel 1";

	job2.midiValue = 64;

	Job job3;
	job3.mixingDeskEventName = "Pan Channel 2";
	job3.midiValue = 127;

	Job job4;
	job4.mixingDeskEventName = "Volume Channel 2";

	job4.midiValue = 64;

	Job job5;
	job5.mixingDeskEventName = "Pan Channel 3";
	job5.midiValue = 127;

	Job job6;
	job6.mixingDeskEventName = "Volume Channel 3";

	job6.midiValue = 64;

	jobsToWrite.push_back(job1);
	jobsToWrite.push_back(job2);
	jobsToWrite.push_back(job3);
	jobsToWrite.push_back(job4);

	jobsToWrite.push_back(job5);
	jobsToWrite.push_back(job6);

	//  Using the job processor to queue up and execute two jobs. 
	JobProcessor* processor1 = new JobProcessor();
	processor1->setData(jobsToWrite);
	processor1->execute();

	processor1->setData(jobsToWrite);
	processor1->execute();


	delete processor1;
	

	return 0;

}


