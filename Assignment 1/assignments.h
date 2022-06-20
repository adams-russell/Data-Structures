#pragma once
#include <list>
#include <iterator>
#include <string>
#include <iostream>

class Assignments {

private:
	//Class variable to obviate redundancy
	int due_date;
	std::string title;


public:
	std::list<Assignments>::iterator lit, lit1;

	//Default constructor
	Assignments() {};

	//Constructor
	Assignments(int dueDate, std::string title) : due_date(dueDate), title(title) {}

	//Getter for assignment title
	std::string getTitle() { return title; }

	//Getter for assignment date
	int getDate() { return due_date; }

	//Add assignment to list
	static void addAssignment(std::list <Assignments>& alist, Assignments& assignment) {
		alist.push_back(assignment);
	}

	//Remove assignment from list
	void removeAssignment(std::list <Assignments>& alist,std::string title) {
		Assignments assignment_copy;
		for (alist.begin(); lit != alist.end(); lit++) {
			assignment_copy = *lit;
			if (assignment_copy.getTitle() == title) {
				lit1 = alist.erase(lit);
				lit = lit1;
			}
		}
	}

	//Print all assignmnets to screen
	void printAssingments(std::list <Assignments>& alist) {
		Assignments assignment_copy;
		for (lit = alist.begin(); lit != alist.end(); lit++) {
			assignment_copy = *lit; //Must create copy Assignments object because class methods do not work on iterators even if references
			std::cout << assignment_copy.getTitle() << std::endl;
		}
	}

	//Return assignment with the earliest due date
	void earliestDue(std::list <Assignments>& alist) {
		Assignments assignment_copy;
		int earliest_date = 1231;
		for (lit = alist.begin(); lit != alist.end(); lit++) {
			assignment_copy = *lit;
			if (assignment_copy.getDate() < earliest_date) {
				earliest_date = assignment_copy.getDate();
			}
		}
		std::cout << "Earlist due assignment: " << earliest_date << std::endl;
	}

};
