#include <sys/ptrace.h>

//tracee and tracer
/* 

#--------$Requirements$----------#

1) Process Input and Execution - Easy

A--> Input From command line -> sandbox process_name commandline_params
B--> check for atleast process_name 
C--> check if file exists in the current dir if not tell the user
D--> create a isolated container 
E--> start the process tracking
F--> start the process


2) Isolation From Remaining Systems - Hard
3) Process Tracking To Find Whether it is harmful or not - Medium

#----------$ Architecture $------------------#

Treminal ---->  |------------| ---creates --->	|---------| ----puts into ---> 	|--------| --- Tracks using ---> 	|---------|
				|  Reader    |      			| Process |						| jail   |							| Tracker |
			    |------------|      			|---------|						|--------|							|---------|


#---------$ High Level Design $------------------#

Reader
&Interface Reader (view)      --> *Implementation Terminal Reader -> Reads a Process name and cmds with a space from terminal and returns the process object
															   -> @Error :Displays Error Mesages if Process not found in given dir or process name not given
&Interface Process (model)    --> *Implementation ClientProcess   -> stores process name and command line options of the process 
&Interface Jail  (controller) --> *Implementation ContainerJail   -> takes the process object , creates the isolated execution environment and executes the process.  
												               -> takes tracker object if enabled tracks the behaviour of process
												               -> sends the data to Process Reviewer to analyze and find any behaviour according to rules
												               -> @Error : Resources may not be available we have to handle it 
&Interface Reviewer (view)    --> *Implementation ProcessReviewer -> recieves the methods executed by the process along with runtime stats 
																  -> logs and prints if required
																  -> @Error   : recieve errors or log file open errors may occur 
&Interface Tracker (controller) --> *Implementation ProcessTracker -> puts a ptrace on the process
																   -> @Error : to be investigated  
*/								




class Reader; //1.A, 1.B, 1.C
class Process; //1.F,3
class Jail; // 1.D, 2
class Tracker; //1.E, 3

int main()
{
	Reader Input;
	Process proc;
	Tracker trac;
    Jail jail;

	proc = Input.get_Process();
	jail = Jail::get_jail();
	jail.add_tracker(trac);
	jail.start_process(proc); 
    jail.wait();

	return 0;
}