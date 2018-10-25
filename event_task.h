#include <string>
#include <sstream>
#include "task.h"


#ifndef EVENT_TASK
#define EVENT_TASK

class event_task : public General_Task{

private:
	std::string location; 
	std::string time; 



public: 
	
	event_task(){} //Constructor 

	//Setter for initializing location
	void setDestination(std::string destination){
		location = destination; 
	}
	
	//Setter for initializing the time 
	void setTime(std::string t){
		time = t; 
	}
	
	//Getter for returning the location
	std::string getDestination(){
		return location; 
	} 

	//Getter for returning the location
	std::string getTime(){
		return time; 
	}


	void detailed(); //detailed function for printing detailed information 
	void print(); //print function 

	event_task& operator=(const event_task& r_object); //Declaration for overloading equal operator


	//Function for outputting to a file 
	std::string file_output(){

		std::stringstream s_day,s_month,s_year;  

		std::string m_data = std::to_string(deadline.month);
		std::string d_data = std::to_string(deadline.day);
		std::string y_data = std::to_string(deadline.year);


		return "E|" + m_data + "/" + d_data + "/" + y_data + "|" + discription + "|" + location + "|" + time; //output data in shopping format

	}




};

#endif