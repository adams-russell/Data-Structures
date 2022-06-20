#include "assignments.h"

std::list <Assignments> assignments;

int main() {
	Assignments a1(620,"Drawing"), a2(621, "Writing");
	Assignments::addAssignment(assignments,a1);
	Assignments::addAssignment(assignments,a2);
	a2.printAssingments(assignments);
	a2.removeAssignment(assignments,a2.getTitle());
	a2.earliestDue(assignments);

	return 0;
}
