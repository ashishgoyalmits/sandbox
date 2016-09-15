
#include "../includes/jail.hpp"
#include "../includes/internal/containerJail.hpp"
#include "../include/internal/terminalReader.hpp"

int main()
{
	//create the jail
    std::unique_ptr<Jail> process_jail = new containerJail();
	
	//add tracker
	process_jail.add_tracker(Tracker());
	
	//start process
	process_jail.start_process(terminalReader().get_Process()); 
    
    //wait until execution completes
    process_jail.wait();

	return 0;
}
