#include "Dekanat.hpp"


int main() {
	Student s1(1, "Leha Kulmetev");
	s1.addMark(4);
	s1.addMark(4);
	s1.addMark(4);
	s1.addMark(1);
	s1.printMarks();
	Group g1("IRTK");
	g1.addStudent(s1);
	std::cout << std::endl << s1.averageMark();
	return 0;
}