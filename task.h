
#include "ListStructure.cpp"
#include <string> 
#include <sstream>

#ifndef	GENERAL_TASK
#define GENERAL_TASK



class General_Task{


protected:
	Date deadline; 
	std::string discription; 
	std::string T_type; 

public:

	General_Task(Date d, std::string discription_arg, std::string type_ = "G") : deadline(d), discription(discription_arg), T_type(type_){}
	General_Task(){}
	 ~General_Task(){}
	

	void setDeadline(int year,int month, int day){

		deadline.year = year;
		deadline.month = month; 
		deadline.day = day; 

	}


	//  setter for initializing deadline
	void setDeadline(Date d){
		deadline = d; 
	}
	//setter for initializing Type 
	void setType(std::string type){
		T_type = type;
	}
	// setter for initialzing description 
	void setDiscription(std::string script){
		discription = script; 
	}	
	// getter for getting the date 
	Date getDate(){
		return deadline; 
	}
	
	//getter for getting the type
	std::string getType(){
		return T_type; 
	}
	//getter for desciption 
	std::string getDiscription(){
		return discription; 
	}


	//overloaded operator = to assign a task object to another task object
	General_Task& operator=(const General_Task &rhs);



	 // print function to print the date and description of the task 
	virtual void print(){
	std::cout << deadline.month << "/" << deadline.day << "/" << deadline.year; 
	std::cout << " - " << discription; 

	}

	//print function for detailed output 
	virtual void detailed(){
		print(); //just print because general task do not have detailed information
	} 

	//function for outputting to a file 
	virtual std::string file_output(){ 


		std::string m_data = std::to_string(deadline.month);
		std::string d_data = std::to_string(deadline.day);
		std::string y_data = std::to_string(deadline.year);


		return "G|" + m_data + "/" + d_data + "/" + y_data + "|" + discription; //outputs to a specified file in this format.

	}
};




#endif














































