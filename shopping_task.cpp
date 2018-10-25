#include <sstream>
#include <string>
#include <iostream>
#include "shopping_task.h"

#pragma once 





shopping_task& shopping_task::operator=(const shopping_task &r_object){ //overloaded function for equal sign  

	this->discription = r_object.discription; 
	this->deadline = r_object.deadline; 
	this->shopping_list = r_object.shopping_list; 

	return *this; 
}