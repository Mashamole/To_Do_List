	/*-----------------------------------------------------------------/

				SORTED LINKED LIST CLASS

	-----------------------------------------------------------------*/

	#include "ListStructure.cpp"

	#include "task.h"
	#include "node.h"



	#pragma once





	template <class type, typename Comparator>

	class sortedList{



	private:

		LinkedList<type> sort_; 




	public:



		sortedList(){}

		~sortedList(){}



		LinkedList<type> getSortedList(){ //function for returning a list 

			return sort_; 

		}

		void remove(int pos){  //removes positon from list

			sort_.remove_position(pos); 

		}



		bool empty(){ //checks if list is empty

			return sort_.empty(); 

		} 



		int size(){ //returns the size of the list 

			return sort_.size(); 

		}

		

		type get_data(int pos){ // gets data at specified postion 



			return sort_.retrieve(pos);

		}



		type first_task(){ // returns the data at the top of the list 

			return sort_.top();

		}

		void insertFirst(const type& data){
			sort_.push_data(); 
		}


		void clear_list(){ //clears list 

			sort_.clear(); 

		}
	
		void *get_head(){
			sort_.getHead(); 
		}

		void push_back(type data ){ //pushes data into list when list is empty.[Note]-> Only used when list is empty at first

			sort_.push_data(data);

		} 

		// function for sorting the list 
		bool sorted_insert(const type& data,Comparator comparator) {

			Node<type> *t_head = sort_.getHead()->getNext(); 

			while(t_head != sort_.get_tail()->getNext() && comparator(t_head->getData(),data)){ //iterates while comparing the dates that are being passed to sort  
					t_head = t_head->getNext(); 
			}

			Node<type> *newNode = new Node<type>; //creates new node for comparison of previos node
			newNode ->setData(data);  //sets the data for newly created node 
			newNode->set_prev(t_head->getPrevious());  //chain the previous node and next node of the newly created node 
			t_head->getPrevious()->set_next(newNode); 
			t_head->set_prev(newNode);  // make the previous node point to new node 
			sort_.incrementSize(); // call increment function to increment size of linked list 

			return true; 


		}

			
};		

////////////////// WITHOUT COMPARATOR IMPLEMENTATION ///////////////////////////
/*




-----------------------------------------------------------------/

			SORTED LINKED LIST CLASS

-----------------------------------------------------------------



#include "ListStructure.cpp"

#include "task.h"
#include "node.h"



#pragma once



class Comparator{
public:
		
	bool operator()(General_Task* first_task, General_Task* second_task) const {

		if(first_task->getDate() < second_task->getDate()){
			return true; 

		}
			return false; 


	}


	
};



template <class type, typename Comparator>

class sortedList{



private:

	LinkedList<type> sort_; 




public:



	sortedList(){}

	~sortedList(){}



	LinkedList<type> getSortedList(){ //function for returning a list 

		return sort_; 

	}





	void remove(int pos){  //removes positon from list

		sort_.remove_position(pos); 

	}



	bool empty(){ //checks if list is empty

		return sort_.empty(); 

	} 



	int size(){ //returns the size of the list 

		return sort_.size(); 

	}

	

	type get_data(int pos){ // gets data at specified postion 



		return sort_.retrieve(pos);

	}



	type first_task(){ // returns the data at the top of the list 

		return sort_.top();

	}



	void clear_list(){ //clears list 

		sort_.clear(); 

	}
/*
	void sizeIncrement(){
		sort_.incrementSize(); 
	}

	void *get_head(){
		sort_.getHead(); 
	}

	void push_back(type data ){ //pushes data into list when list is empty.[Note]-> Only used when list is empty at first

		sort_.push_data(data);

	} 

	// function for sorting the list 
	bool sorted_insert(const type& data/*const &type, Comparator lessThan) {
		Comparator comparator;
		Node1<General_Task*> *newNode = new Node1<General_Task*>;
		newNode->setData(data);
		Node1<General_Task*> *t_head = sort_.getHead(); // NEED TO FIX THIS LINE INVALID CONVERSION

		

		if(sort_.size() == 0 ){   // checks if list is empty in order to insert push the first item into the list  

			sort_.push_data(newNode);
			operation = true; 

		}

		if(t_head == nullptr){
			t_head = newNode; 
			sort_.incrementSize();
			return true; 
		}

		if(comparator(data,t_head->getData())){
			newNode->set_next(t_head);
			t_head->set_next(newNode);
			sort_.push_data(newNode);
			return true; 
		}

		Node1<General_Task*> *tmp = t_head->getNext(); 
		Node1<General_Task*> *trail_ptr = t_head; 

		while(tmp->getNext() != nullptr){
			if(comparator(data, tmp->getData())){
				trail_ptr -> set_next(newNode); 
				sort_.incrementSize(); 
				return true; 
			}

			trail_ptr = tmp; 
			tmp = tmp->getNext(); 
		}

		tmp->set_next(newNode); 

		//Node1<General_Task> *ptr; 

//		General_Task* object; 
//		bool operation = false; 








/*

	void sorted_insert(General_Task* task, ) {
		Comparator c_tor; 
		Node1<General_Task> *ptr; 

		General_Task* object; 
		bool operation = false; 





		if(sort_.size() == 0 ){   // checks if list is empty in order to insert push the first item into the list  

			sort_.push_data(data);

			operation = true; 

		}

	

		// Enters else if list is not empty 

		else{





			for(int i=1; i< sort_.size()+1;++i){



				object = sort_.retrieve(i);  //retrives data for date comparisons





					if(object->get_year() < task->get_year()){ //checks diffrence between years which



							sort_.insertPos(task,i); //inserts the task with the most recent date 

							operation = true; 

							break;

					}

					else if(object->get_year() == task->get_year()){ //if years are equal then check the months 

						if(object->get_month() < task->get_month()){

							

							sort_.insertPos(task,i);  //inserts the task with the most recent date 

							operation = true; 

							break; 

						}

					

					else if(object->get_month() == task->get_month()){ // if months are equal then

						if(object->get_day() < task->get_day()){       //then compare the days 



							sort_.insertPos(task, i);  //inserts the task with the most recent date 

							operation = true; 

							break;

						}

					}

				}

			}



			} 

			if (operation == false){

				sort_.push_data(task); 

			}

		

}



};



*/


