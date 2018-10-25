#include <string>
#include <sstream>
#include "task.h"

#ifndef HOMEWORK_TASK 
#define HOMEWORK_TASK


class Homework_Task : public General_Task{


protected:
	std::string Course; 

public:


	Homework_Task(){} //Constructor

	//Setter for initializing Course 
	void setCourse(std::string c){
		Course = c; 
	}
	//Getter for getting the Course 
	std::string getHomerwork(){
		return Course; 
	}

	//Function for printing Homework information 
	void print(){
	std::cout << deadline.month << "/" << deadline.day << "/" << deadline.year; 
	std::cout << " - [Homework] " << discription; 
	}


  	//Function for printing detailed information 
 	void detailed(){
	print(); 
	std::cout << "\n SUBJECT: " << Course; 
	}

	 Homework_Task& operator=(const Homework_Task &r_obj); 



	 //Function for outputting to a file 
	std::string file_output(){

	
		std::string m_data = std::to_string(deadline.month);
		std::string d_data = std::to_string(deadline.day);
		std::string y_data = std::to_string(deadline.year);

		return "H|" + m_data + "/" + d_data + "/" + y_data + "|" + discription + "|" + Course; // returns string in Homework format

	}









};

#endif