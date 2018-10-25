#include <iostream> 

#include <algorithm>

#include "ToDoListApp.h"

#include "homework_task.h"

#include  "shopping_task.h"

#include "event_task.h"

#include <fstream>

#include <string>

#include <vector>





//replace all cin = in and cout = out

using std::endl; 

using std::cout; 

using std::cin; 





//enum TaskType { SHOPPING = 'S', EVENT = 'E', HOMEWORK = 'H', GENERIC = 'G' };







void ToDoListApp::run() {



		sortedList<General_Task*, Comparator> taskList; //Initializing link list for incomplete task 

		sortedList<General_Task*, Comparator> complete_task; //Initializing link list for complete task



	//NOTE: we are using out/in streams from the class level, not cin/cout



	//      directly. All your functions should do this.



	out << "Welcome to your To-Do List! You may begin to enter commands.";



	out << endl;



	commandDisplay(); 





	string command;



	do {



		out << "> ";



		getline(in, command);







		//Convert entire command to uppercase for easy compares



		transform(command.begin(), command.end(), command.begin(), ::toupper);







		if (command == "PRINT") {



			executeCommandPrint(taskList);



		} else if (command == "ADD") {



		executeCommandAddTask(taskList);



		} else if (command == "DETAILED") {



		executeCommandPrintDetailed(taskList);



		} else if (command == "COMPLETE") {



		executeCommandCompleteTask(taskList,complete_task);



		} else if (command == "COMPLETED") {



		executeCommandPrintCompleted(complete_task);



		}  else if (command == "REMOVE") {



		executeCommandRemoveTask(taskList);



		} else if (command == "HELP") {



		commandDisplay(); 



		} else if (command == "SAVE") {



		executeCommandSave(taskList);



		} else if (command == "LOAD") {



		executeCommandLoad(taskList);



		} else if (command == "EXIT") {



			out << "Thank you for using To-Do List!\n";



			break;



		} else {



			out << "Unknown Command (" << command << "). Try Again.\n";



		}



		out << "\n";



	} while (true);



}



//Function for Displaying Menu

void ToDoListApp::commandDisplay(){

	out << "Enter -|ADD|- to add a task" << endl; 

	out << "Enter -|REMOVE|- to remove a task" << endl; 

	out << "Enter -|PRINT|- to print a list of task" <<endl; 

	out << "Enter -|DETAILED|- to print list of task with details" << endl; 

	out << "Enter -|COMPLETE|- to make a task complete" << endl; 

	out << "Enter -|COMPLETED|- to display completed task" << endl; 

	out << "Enter -|LOAD|- to load task" << endl;

	out << "Enter -|SAVE|- to save task to folder" << endl;

	out << "Enter -|HELP|- to display options on screen" << endl; 

	out << "Enter -|EXIT|- to exit the program" << endl; 

}







// Functon for converting string into Date object

Date ToDoListApp::convert(string date_){

/*

gets month first by using the '/' as delimiter to obtain the month then 

erase the month from the string in order to extract the rest of the date 

and assign to day, and to year 



*/



	string mth,dy,yr; 

	Date date; 

	string slash; 

	slash = "/";



	mth = date_.substr(0,date_.find(slash));   

 	date_.erase(0,date_.find(slash) + slash.size());

	dy = date_.substr(0, date_.find(slash));

	date_.erase(0, date_.find(slash) + slash.size());

	yr = date_;



	date.month = stoi(mth.c_str()); //Initialize the month for date

	date.day = stoi(dy.c_str());	// Initialize the day for date

	date.year = stoi(yr.c_str()); // Initialize the year for date





	return date;  // returns a date object



}







// Function for adding a task 

void ToDoListApp::executeCommandAddTask(sortedList<General_Task*, Comparator> &s_list){

std:: string choice; 

bool check = false; 

Date d; 

	

	//Prompt user 

	out << "What type of task is this [G]: Generic, [E]: Event, [S]: Shopping, [H]: Homework\n";

		getline(cin, choice); 

	

	while(choice != "G" && choice != "g" && choice != "S" && choice != "s" && choice != "E" && choice != "e" && choice != "H" && choice != "h"){ //Checks for valid input 

		out << "Please enter on of the following options." << endl; 

		out << "What type of task is this [G]: Generic, [E]: Event, [S]: Shopping, [H]: Homework\n";

		getline(cin, choice); // Get user input 



	} 



	

	string discription, date;

	int count = 0;  

	out << "When is this task due?" << endl; 

	out << "=> ";

	getline(cin,date); 

	d = convert(date);  //converts users input date into date object



	out << "How would you describe this task" << endl; 

		out << "=> ";

		getline(cin, discription);





	//IF TASK IS GENERIC

	if(choice == "G" || choice == "g"){ 

		General_Task *newtask = new General_Task; // Creates new task poiner of type Generic Task  

		newtask->setDeadline(d); //sets date object for Generic class

		newtask->setDiscription(discription); //sets descripton for Generic class



		s_list.sorted_insert(newtask,Comparator()); //Inserts new task pointer into sorted link list



		out << "Task added successfully" << endl;



	}



	//IF TASK IS SHOPPING

	else if ((choice == "S") || (choice == "s")){ 

		std::string input,item;  

		shopping_task *ptr_shopping = new shopping_task; //Create a new task pointer of type Shopping 



		out << "what items do you need to buy? [Type your items and press ENTER to add another item. Type DONE to complete the list.]" << endl; //prompt user for items

		while((item != "DONE") || (item != "done")){

			out << "=>";

			cin >> item; 



			if(item == "DONE" || item == "done"){

				break; 

			}

			ptr_shopping->push_item(item); //call push function to push user items into vector 

		}

		ptr_shopping->setDeadline(d); // inititialize deadline for shopping task

		ptr_shopping->setDiscription(discription); // inititialize description for shopping task 

		s_list.sorted_insert(ptr_shopping,Comparator()); // inserts shopping pointer into sorted link list 

		out << "Task added successfully" << endl;

	}



	//IF TASK IS SHOPPING

	else if ((choice == "E") || (choice == "e")){



		//Initialize date, and description for event task



		std::string place,time_; 

		event_task *ptr_event = new event_task; 

		ptr_event->setDeadline(d); 

		ptr_event->setDiscription(discription); 



		out << "Where is this event taking place?" << endl; 

			getline(cin,place);

			ptr_event->setDestination(place); //set location for event task

		out << "What time is this event taking place?" << endl; 

			getline(cin,time_); 

			ptr_event->setTime(time_); //Set time for event task 



			s_list.sorted_insert(ptr_event,Comparator()); //insert event task pointer into sorted link list

			out << "Task added successfully" << endl;



	}

	//IF TASK IS HOMEWORK 

	else if(choice == "H" || choice == "h"){

		

		//Initialize date, and description for homework task



		std::string input_h;

		Homework_Task *ptr_homework = new Homework_Task;

		ptr_homework->setDeadline(d); 

		ptr_homework->setDiscription(discription);



		out << "What subject is this homework task for?" << endl; 

			getline(cin,input_h); 

		ptr_homework->setCourse(input_h); //initialize course for homework task 

		s_list.sorted_insert(ptr_homework,Comparator()); //insert homework task into sorted list 

		out << "Task added successfully" << endl;

	}

}





//Funtion to Print 

void ToDoListApp::executeCommandPrint(sortedList<General_Task*, Comparator> s_list){



	if(s_list.empty()){

		cout << "You have no outstanding tasks!" << endl; 

	}

	else{



		int counter = 1; 





		for(int i = s_list.size(); i >= 1; --i){ //prints task from most recent to the latest 	

			cout << endl; 

			General_Task *obj = s_list.get_data(i);

 			cout << counter << ".  ";

			obj->print(); // pointer to access the print function for base class and sub classes 

			++counter; 

	



		}



	}

}



// Function for printing completed task

void ToDoListApp::executeCommandPrintCompleted(sortedList<General_Task*, Comparator> &c_task){

 



	if(c_task.empty()){ 

		cout << "You have no completed tasks!" << endl; 

	}

	else{



		int counter = 1; 

		int i = 1; 

		

		while(i <= c_task.size()){	//tasks will be printed in order of completion 

			cout << endl; 

			General_Task *obj_ = c_task.get_data(i);  //General task pointer is initialized to each task which points to the print function for each task 

 			cout << counter << ")  ";

			obj_->print(); //prints information regarding to each task 

			++counter; 

			++i;  

	



		}



	}

}







//Function for removing task 

void ToDoListApp::executeCommandRemoveTask(sortedList<General_Task*, Comparator> &s_list){



	if(!s_list.empty()){



		int position, count = 1; 





		for(int idx = s_list.size(); idx >= 1; --idx){ //Displays list of task in order for user to choose which one to delete

			cout << endl; 

			General_Task *ptr = s_list.get_data(idx);

			cout << idx << ".  ";

			ptr -> print(); 

		}



	cout << "\nWhich task do you want to remove [ENTER INDEX]\n=>";

		cin >> position;





	while(position < 0 || position > s_list.size()) { // Checks if user inserted a correct position 

			cout << "[Error] - INVALID POSTION" << endl;



			cout << "Which task would you like to remove?" << endl; 

				cin >> position;

 	}

 //		cout << s_list.size() << endl;  

 		s_list.remove(position);  //removes positon from sorted list

 		cout << "Task removed successfully" << endl;  



		}

}









//Function for marking a task as complete 

void ToDoListApp::executeCommandCompleteTask(sortedList<General_Task*, Comparator> &s_list,sortedList<General_Task*, Comparator> &c_task){

 

	if(!s_list.empty()){ //checks if list is empty first 

		int position_; 



		cout << "Which task would you like to complete?" <<endl;

			cin >> position_; 





			while(position_ < 0 || position_ > s_list.size()) { //check if user input is valid 

			cout << "[Error] - INVALID POSTION" << endl;



			cout << "Which task would you like to complete?" << endl; 

				cin >> position_;

 		}



 		c_task.push_back(s_list.get_data(position_)); // obtains users selected position and pushes that task into the complete task list 

 		s_list.remove(position_); //removes postion from incomplete task list 





 		cout << "Your task has been successfully marked as complete" << endl;

	}

	else

		cout << "You have no task to mark as complete" <<endl; 



}









//Function for saving a task

//goes through list and calls the file output function to output to a file in task specific order

 void ToDoListApp::executeCommandSave(sortedList<General_Task*, Comparator> &s_list){



 	std::string name; 

 	std::ofstream file; 

 	

 	if(s_list.empty()){ //Checks if incomplete task list is empty 

 		cout << "You have no outstanding task!" << endl; 

 	}

 	

 	else{





 		 cout << "Where would you like to save your outstanding task?" << endl; //prompt user for filename  

 		 cout <<"=>";

 		 getline(cin,name); //gets users input 



 		 file.open(name.c_str()); //convert filename to string 



 		 for(int i=1; i<=s_list.size(); ++i){ 

 		 	General_Task *t_object = s_list.get_data(i); //pointer is initialized to position 'i' which contains a task type 

 		 	file << t_object -> file_output();				// allowing access to file output function 

 		 	file << endl; 

 		 }

 		 file.close(); 

 	}



 	 cout << "File saved successfully..." << endl; 



 }



 	//Function for loading task 

	void ToDoListApp::executeCommandLoad(sortedList<General_Task*, Comparator> &s_list){



		std::string filename, line_number, type ,date,discription; 	

		char d_limit = '|'; 

		std::ifstream infile; 

		Date date_; 





		cout << "What file would you like to load outstanding task from? [NOTE] - All data from existing task will be lost." <<endl; // Prompt user to obtain filename 

			cout <<endl; 

			cout << "=>"; 

			getline(cin,filename);



			infile.open(filename.c_str()); 

if(infile){



			s_list.clear_list(); //clear the current list in order to insert tasks from loaded file 

			

			while(!infile.eof()){



				getline(infile,type,d_limit); //gets string characters until the delimiter->'|' is reached (which is the type)



				getline(infile,date,d_limit); // the layout of the file stores the date after the first instance of the delimiter therefore we getline until the delimiter is reached 

				date_ = convert(date);





				if(type == "G"){ // if type is G then it initializes the necessary members 

					getline(infile, discription); 

					General_Task *ptr_G = new General_Task; 

					ptr_G->setDeadline(date_); 

					ptr_G->setDiscription(discription);

					s_list.sorted_insert(ptr_G,Comparator()); 



				}

				else{



					getline(infile, discription,d_limit);  // use getline in order to obtain the description 



					if(type == "S"){ //If type is S then initializes the necessary members including the list of items

						std::vector<std::string> v_list;



						getline(infile,line_number); 

						std::string list; 

						std::string::size_type start = 0; //create starting position for substring manipulation 

						std::string::size_type search = line_number.find_first_of(d_limit); //locates the position of the delimiter 



						 while(search != std::string::npos){ //used to extract the list of items for the shopping list



						 	list = line_number.substr(start,(search - start)); //update string with new string values  

						 	v_list.push_back(list); 

						 	start = search + 1; 

						 	search = line_number.find_first_of(d_limit,start); 

						 }



						 list = line_number.substr(start, (search - start)); // update the string values 

						 v_list.push_back(list);

						 shopping_task *ptr_S = new shopping_task;

						 ptr_S -> setDeadline(date_); // initializes the deadline for shopping task

						 ptr_S -> setDiscription(discription); // initializes the description for shopping task

						 ptr_S -> setList(v_list); // initializes the shopping list for shopping task

						 s_list.sorted_insert(ptr_S,Comparator());  //inserts the shopping task in the sorted list 



					}





				

				/*

				Initializes the values for Event task 

				*/

				if(type == "E"){ 

					std::string loadtime,loadLocation; 

					getline(infile, loadLocation, d_limit);

					getline(cin,loadtime);

					event_task *ptr_E = new event_task; 

					ptr_E -> setDeadline(date_); //initializes the deadline for event task 

					ptr_E -> setDiscription(discription); //initializes the description for event task 

					ptr_E -> setDestination(loadLocation); //initializes the destination for event task 

					ptr_E -> setTime(loadtime);//initializes the time for event task 

					s_list.sorted_insert(ptr_E,Comparator()); // insert new loaded event task into the sorted list 

				}





				/*

				Initializes the values for Homework task 

				*/

				if(type == "H"){



					std::string loadCourse; 

					getline(infile, loadCourse);



					Homework_Task *ptr_H = new Homework_Task; 

					ptr_H->setDeadline(date_); //initializes the deadline for homework task 

					ptr_H -> setDiscription(discription); //initializes the description for homework task 

					ptr_H -> setCourse(loadCourse);  //initializes the Course for homework task 

					s_list.sorted_insert(ptr_H,Comparator());  // insert new loaded homework task into the sorted list 



				}



			} 

		}	 



			infile.close(); 

			cout << "Task loaded successfully!" <<endl;

	}

	else {

		cout << "Task unable to load..." << endl; 

	}





}



//Function for printing the detailed information 

void ToDoListApp::executeCommandPrintDetailed(sortedList<General_Task*, Comparator> &s_list){

if(s_list.empty()){

		cout << "You have no outstanding tasks!" << endl; 

	}

	else{



		int counter = 1; 

		for(int i = s_list.size(); i >= 1; --i){	

			cout << endl; 

			General_Task *obj = s_list.get_data(i); //General task pointer is initialized to each task which points to the detailed function for each task 

 			cout << counter << ".  "; 

			obj->detailed(); //prints detailed information for each task except for the generic task 

			++counter; 

	



		}



	}

}












