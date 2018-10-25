#include <string> 
#include <sstream>
#include <iostream>
#include "task.h"

	
//overloaded equal sign function 
 General_Task& General_Task::operator=(const General_Task& r_object){
	this->discription = r_object.discription; 
	this->deadline = r_object.deadline; 
	return *this; 
}


	

//Work on cpp files for task