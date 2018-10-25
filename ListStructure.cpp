
#include <iostream>

#include <vector>

#include <ostream>

#include "DateClass.cpp"

#include "node.h"

#pragma once



/*-----------------------------------------------------------------/

					LINKED LIST CLASS

-----------------------------------------------------------------*/



template<class T>

class LinkedList{

/*
struct Node { // Node for container and pointer

		T container; 
		Node *next = nullptr;

};
*/

private:
	Node<T> *head = new Node<T>; 
	Node<T> *tail = new Node<T>;
	size_t counter=0;
	bool checkPos(int pos){ //Helper function for checking if position is valid 

		if(pos < 0 || pos > counter){

			return false; 

		}

	}



public:

	//Constructor for setting data

	LinkedList() { 

		head->set_next(tail); 
		tail->set_prev(head); 

	}

	//LinkedList() {}	//Default Constructor 

	~LinkedList() { //Destructor

		delete head; 
	}	

	
	Node<T> *get_tail(){
		return tail; 
	}
	//Copy Constructor 

	Linkedlist(const LinkedList &rhs){



		this->head = nullptr; 


		this->counter = rhs.counter; 



		if(rhs.head == nullptr){ //check if passed object is empty 

			this->head = nullptr; 

		}

		else {

			Node<T> *tmp = rhs.head;  //make a temporary head point to passed objects head for iteration  

			Node<T> *Newnode = new Node<T>; //Create new node of new object

			this->head = Newnode; //Make new object's head point to newly created node to insert data from passed object

			Newnode->container = tmp->container; //insert data first to create the first node



			while(tmp->next != nullptr){ //Copy passed objects data to new object's nodes 

				Newnode->next = new Node<T>;

				Newnode = Newnode->next;

				Newnode->container = tmp->container; 


			}

	}



	}

	Node<T> *getHead() const{
			return head;
	}

	//Push Front Function 

	void push_front(const T& data){//this function inserts data into the front of the list



		Node<T> *n = new Node<T>; //creates new node

		n->container = data; 

		n->next = head; //make newly created node 's next point to current head's node

		head = n; //make the current head point to the newly created node

		++counter; //increase size of list



	}

	

	//Push Data Function

	void push_data(const T& data) { //inserts data at the back of the list 

		Node<T> *temp = head;	// create temp ptr equal to head node 

		Node<T> *n_node = new Node<T>; //create new node 

		n_node->container = data; //make new node data equal to passed data 

		if(head == nullptr){ // if head points to null, call pushfront

			push_front(data);

		}

		else{

			while (temp->next != nullptr) { //iterate through nodes until nullptr is reached 

					temp = temp->next; //make temp equal to next

			}

			temp->next = n_node; //make the last node equal to the new node

			n_node->next = nullptr; // make the new node point to next



			

			++counter; //increment size 

		}

	}

	//Pop Front Function 

	bool pop_front(){ //removes the first element from the list 

		Node<T> *tmp = head;  //make new pointer equal to head 

		head = tmp->next;  //make the head point to the next node 

		delete tmp; //delete temporary pointer which points to the old node

		--counter; //decrement size of list

		return true;

	}

	//Pop Data Function 

 	bool pop_data(){ //deletes the last node of the list



 		if(head == nullptr){ //check if head is empty

 			return false; 

 		}

 		if(counter == 1){ //if size is one, call push front to remove the first/last node 

 			pop_front(); 

 			return true; 

 		}

		//using two pointer approach to keep list linked together after deletion 

 		Node<T> *ptr = head;

 		Node<T> *ptr2; 

 		while(ptr->next != nullptr){//iterates through list until ptr is on the last node and ptr2 is on the second last node

 			ptr2 = ptr; 

 			ptr = ptr -> next;

 		}

 		delete ptr;

 		ptr2 -> next = nullptr; 

 		--counter;  //decrement size

 		return true; 

 	}



	//Retrieve Function 

	 T retrieve(int pos) const {// This function returns the data at a position specified by the user 



		Node<T> *tmp = head; 



		for(int i=1; i<pos; ++i){ //iterate through Nodes until pointer points to the postion

			tmp = tmp->next; 

		}

 		return tmp->container; //return data at positon

	}



 	//Size Function

	int size() {

		return counter; 

	}

	//Top Function 

	T top(){ //used to display the data at the top of the list

		

		return head->container; 

	}

	void incrementSize(){
		++counter; 
	}

	//Empty Function 

	bool empty(){ //Checks if list is empty 

		if(this->size() == 0){

			return true; 

		}

		else 

			return false; 

	}

	//Insert at Position function	

	bool insertPos( T& data, int pos){ //inserts data at postion specified by the user 

		/*Create new Node with passed data*/	

		Node<T> *tmp = head; 

		Node<T> *newNode = new Node<T>; 

		newNode-> container = data; 

		newNode->next = nullptr; 



		if(pos > counter || pos < 1){ //check if position is valid 

			std::cerr << "INVALID POSITION"; 

			return false;

		}

		if(pos == 1){ // if position is the first, call push front 

			push_front(data);

			return true; 

		}

		if(counter == pos){ //if pos is the last position, call push front

			push_data(data);

			return true;  

		}



		else{

			for(int i=0; i< pos-2; ++i){ //iterate through list until 2 positions before actual postion

				tmp = tmp -> next; 

			}

			newNode-> next = tmp ->next; //make new node's next equal to temp's next to keep list structure

			tmp -> next = newNode; //make temp's next equal to new node  

			++counter; //increment size 

			return true; 

		}



	}





	//Contains Function 

	bool contains(const T& data){ //checks if data is within the list

		Node<T> *tmp = head;



		while(tmp != nullptr){

			if(tmp->container == data){

				return true; 

			} 

			tmp = tmp->next;



		}

		return false; 



	}

	

	//Remove Function

	bool remove_data(const T& data){

		Node<T> *tmp = head; 

		Node<T> *trash; //create trash pointer for deletion 



		if(head->container == data){ //check if head is pointing to the data 

			trash = head; 

			head = head->next; 

			delete trash; 

			--counter; 

		}

		//iterate through each node and check if data is equal to the data we want to delete

		while(tmp->next != nullptr){ 

			if(tmp->container == data){

				trash = tmp;

				tmp = trash->next;

				trash->next = tmp;  

				delete trash;

				return true; 

				--counter; 

			}

			tmp = tmp->next;



		}

	}

	//Remove by Position Function 

	bool remove_position(int pos){ 

	



		if(head == nullptr){ //checks if head is pointing to nothing 

			return false; 

		}

		if(pos > counter || pos < 1){ //Validates postion 

			return false; 



		}

		if(pos == 1){ // Call pop front if position is the first position 

			pop_front();

			return true; 

		}

		if(counter == pos){ //Call pop front, if position is the last in the list

			pop_data();

			return true; 

		}

		else{

			//Iterate until position is the next node in order to keep list structure, and then delete node 

			Node<T> *tmp = head; 

			for(int i = 1; i < pos-1; ++i){ 

				tmp = tmp->next; 

			}

			

			Node<T> *trash; 

			trash = tmp->next; 

			tmp->next = trash->next; 



			delete trash;

			--counter;  

			return true; 





		}

		return false; 

	}



	//Clear List Function 

	bool clear(){

		

		while(!(empty())){//While list is not empty, call pop front 

			pop_front();

		}



		return true; 

}



};