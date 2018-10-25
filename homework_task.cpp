#include <sstream>
#include <string>
#include <iostream>
#include "homework_task.h"

#pragma once 


//function for overloading the equals operator 
Homework_Task& Homework_Task::operator=(const Homework_Task& r_object){
	this->discription = r_object.discription; 
	this->deadline = r_object.deadline; 
	this->Course = r_object.Course; 

	return *this; 
}



