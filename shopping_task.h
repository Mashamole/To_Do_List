#include <string>
#include <sstream>
#include "task.h"
#include <vector>


#ifndef SHOPPING_TASK
#define SHOPPING_TASK


class shopping_task : public General_Task{

private: 
	std::vector<std::string> shopping_list;


public: 

	shopping_task(){} // Constructor 
	~shopping_task(){} // Destructor 


	//function for initializing vector 
	void setList(std::vector<std::string> v){
		shopping_list = v; 
	}

	//getter for getting vector 
	std::vector<std::string> getList(){
		return shopping_list; 
	}

	//function for pushing into the vector 
	void push_item(std::string &item){
		shopping_list.push_back(item); 
	} 

 //function for printing date, type, and description
 void print(){
	std::cout << deadline.month << "/" << deadline.day<< "/" << deadline.year; 
	std::cout << " - [Shopping] " << discription; 
}


 //function prints regular date and description along with detailed information regarding to shopping list 
 void detailed(){
	print(); 
	std::cout << "\n ITEMS:";
	for(int i=0; i<shopping_list.size(); ++i){
		std::cout << endl << " "  << shopping_list[i];

	}
}

	 //function for overloading equal operator 
	 shopping_task& operator=(const shopping_task &r_object); 


	 //function for outputting to file used for SAVING A TASK 
 	std::string file_output(){
		
		
		
		std::string m_data = std::to_string(deadline.month);
		std::string d_data = std::to_string(deadline.day);
		std::string y_data = std::to_string(deadline.year);

		std::string l_items = "";

		for(size_t i = 0; i < shopping_list.size(); ++i){
			l_items += "|" + shopping_list[i];
		}

		return "S|" + m_data + "/" + d_data + "/" + y_data + "|" + discription  + l_items; 

	}
};

#endif 


