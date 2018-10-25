#ifndef TODOLISTAPP_H
#define TODOLISTAPP_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "DateClass.cpp"
#include "ListStructure.cpp"
#include "sorted_list.cpp" 




	class Comparator{ // Comparator class for comparing to task dates 
	public:
			
		bool operator()(General_Task* first_task, General_Task* second_task) const {

			if(first_task->getDate() < second_task->getDate()){
				return true; 

			}
				return false; 


		}


		
	};


// ToDoList Application Class - This class will handle the commands entered from the

// user. It is initialized with an input/output stream, which is by default cout/cin. 

// Any functions implemented should make use of out/in instead of cout/cin directly.

class ToDoListApp {

public:

	void run(); //Declaration for run function which starts the program
	
	void commandDisplay();  //Declaration for displaying menu  

	Date convert(std::string date_); // Declaration for converting a string into a date object
	

	ToDoListApp(std::istream& in = std::cin, std::ostream& out = std::cout) : in(in), out(out) {}


//	enum TaskType { SHOPPING = 'S', EVENT = 'E', HOMEWORK = 'H', GENERIC = 'G' };



	// You will implement all of the following functions


	//Command for print 
	void executeCommandPrint(sortedList<General_Task*, Comparator > s_list); 

	//Command for adding a task 
	void executeCommandAddTask(sortedList<General_Task*, Comparator> &s_list);

	//command for removing task 
	void executeCommandRemoveTask(sortedList<General_Task*, Comparator> &s_list);

	//Command for marking a task complete
	void executeCommandCompleteTask(sortedList<General_Task*, Comparator> &s_list, sortedList<General_Task*, Comparator> &c_task);

	//Command for printing completed task 
	void executeCommandPrintCompleted(sortedList<General_Task*, Comparator> &c_task);

	//Command for saving task 
	void executeCommandSave(sortedList<General_Task*,Comparator> &s_list);

	//Command for loading task 
	void executeCommandLoad(sortedList<General_Task*, Comparator> &s_list);

	//Command for printing detailed information 
	void executeCommandPrintDetailed(sortedList<General_Task*, Comparator> &s_list); 


private:

	// Remember: you may add additional member variables
	
	std::istream& in = std::cin;

	std::ostream& out = std::cout;


};



#endif



