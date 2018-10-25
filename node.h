#ifndef NODE_
#define NODE_



template<class T>
struct Node { // Node for container and pointer




	Node<T> *head = nullptr; 
	Node<T> *prev = nullptr; 
	Node<T> *next = nullptr;
	Node<T> *tail = nullptr; 
	T container; 


		Node(T data): head(nullptr),container(data) {}
		Node(){}
		~Node(){}

		bool setData(T data){ 
			container = data;
		}
		bool set_next(Node *next_){
			next = next_;
		}
		bool set_prev(Node *previ_){
			prev = previ_; 
		}

		Node *getNext() const{
			return next; 
		}
		T getData()const {
			return container; 
		}

		Node *getTail()const {
			return tail; 
		}
		Node *getHead()const {
				return head;
		}
		
		Node *getPrevious(){
			return prev; 
		}
		T getHeadData(){
			return head->data; 
		}



	};


#include "node.cpp"
#endif 