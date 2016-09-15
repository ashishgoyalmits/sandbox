//--------------------------------------------------------
//   File        : process.hpp								  
//   Author      : Harshavardhan.k                    
//   Description : Interface For Process Object
//--------------------------------------------------------
#include <string>

class process 
{
	public:
		string get_name() = 0;
        bool put_name(string) = 0;

};