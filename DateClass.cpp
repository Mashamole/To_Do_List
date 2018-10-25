#pragma once 


#include <iostream>
#include <string>

using namespace std;

struct Date {
		 // private members for assigning a date with a day, month, and a year
		int year;
		int month;
		int day;


			friend std::ostream& operator<<(std::ostream &lhs,  Date &d){ // Defintion for overloading ostream operator 

	  			lhs << d.month << "/" << d.day  << "/" << d.year; 
   				return lhs;
		}

		Date(int m, int d, int y) : year(y), month(m), day(d){} // Date constructor 
		Date(){}
		~Date(){}
		
	 bool operator==(const Date &rhs){ //for checking if date objects are equal to each other  

	 	if(this->year == rhs.year){
	 		if(this->day == rhs.day){
	 			if(this->month == rhs.month){
	 				return true; 
	 			}
	 		}
	 	}

	 	return false; 

	 }
	
	bool operator<(const Date &rhs){ // Definition for overloading less than operator 
	
	if(year < rhs.year){			//compares years to find most recent date
		return true;
	}
	else if(month < rhs.month){
		return true; 
	}
	else if (month == rhs.month && year == rhs.year){
		if(day < rhs.day){
			return true; 
		}	
		else
			return false;
	}
	else 
		return false; 

	}

};




