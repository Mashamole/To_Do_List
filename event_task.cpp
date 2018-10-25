#include <sstream>
#include <string>
#include <iostream>
#include "event_task.h"




//implementation for overloading equals operator 
event_task& event_task::operator=(const event_task& r_object){
	
	this->location = r_object.location; 
	this->deadline = r_object.deadline; 
	this->discription = r_object.discription; 
	this->time = r_object.time; 
}


 //function for printing info about task 
 void event_task::print(){
	std::cout << deadline.month << "/" << deadline.day << "/" << deadline.year; 
	std::cout << " - [Event] " << discription; 
}
	
//function for printing detailed information about task
 void event_task::detailed(){
	print(); 
	std::cout <<"\n WHERE: " << location; 
	std::cout << "\n WHEN: " << time;
}
