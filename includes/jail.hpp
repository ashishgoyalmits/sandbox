//--------------------------------------------------------
//   File        : jail.hpp								  
//   Author      : Harshavardhan.k                    
//   Description : Interface For Creating a Process Jail
//--------------------------------------------------------

#ifndef JAIL_H
#define JAIL_H


#include "tracer.hpp"
#include "process.hpp"

class Jail
{
	public:
		
		bool add_tracker(Tracer) = 0;
		bool start_process(Process) = 0;
		bool wait() = 0; 
};

#endif