#include "Student.hpp"
#include "Group.hpp"

// FIX ME perhaps make it static fild is the best way?
const int ARRAY_INCREASING = 5;

Student::Student(const int _id, const char* _fio) {
	if (_id < 0) throw std::invalid_argument("ID must be non-negative");
	if (!_fio || !*_fio) throw std::invalid_argument("FIO cannot be empty");
	id = _id;
	fio = _fio;
}

Student::Student(const Student& other) : id(other.id), fio(other.fio), group(other.group),
marksNum(other.marksNum), capacity(other.capacity) {
	marks = new int[capacity];
	std::copy(other.marks, other.marks + other.marksNum, marks);
}

Student& Student::operator = (const Student& other) {
	if (this == &other) {
		return *this;
	}
	int* tmpMarks = new int[other.capacity];
	std::copy(other.marks, other.marks + other.marksNum, tmpMarks);
	// delete old array marks
	delete[] marks;
	// assign values
	id = other.id;
	fio = other.fio;
	group = other.group;
	marks = tmpMarks;
	marksNum = other.marksNum;
	capacity = other.capacity;
	return *this;
}

Student::~Student() {
	delete[] marks;
}

void Student::enroll_to_group(Group* _group) {
	if (group == _group) {
		return; // is already enrolled
	}
	group->addStudent(*this);
}

Group* Student::getGroup() const {
	return group;
}

void Student::addMark(int _mark) {
	if (marks == nullptr) {
		capacity = ARRAY_INCREASING;
		marks = new int[capacity];
	}

	if (marksNum >= capacity) {
		capacity += ARRAY_INCREASING;
		int* tmpMarks = new int[capacity];
		if (tmpMarks == nullptr) {
			throw::std::bad_alloc();
		}
		std::copy(marks, marks + marksNum, tmpMarks);
		// clean old array
		delete[] marks;
		marks = tmpMarks;
	}
	marks[marksNum++] = _mark;
}

double Student::averageMark() const {
	if (marksNum == 0) {
		std::cout << "Student has no marks yet";
		return 0.0;
	}
	double sum = 0;
	for (int i = 0; i < marksNum; ++i) {
		sum += marks[i];
	}
	return sum / marksNum;
}

void Student::printMarks() const {
	if (marksNum == 0) {
		std::cout << "Student has no marks yet";
		return;
	}
	for (int i = 0; i < marksNum; ++i) {
		std::cout << marks[i];
		if (i < marksNum - 1) std::cout << ", ";
	}
}