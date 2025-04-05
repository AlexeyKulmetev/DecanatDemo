#include "Group.hpp"
#include "shared_constants.hpp"
#include "Student.hpp"

Group::Group(const char* _title) : title(_title) {}

Group::Group(std::string& _title) : title(_title) {}

void Group::print() const {
	std::cout << "group: " << title;
}

const std::string& Group::getTitle() const {
	return title;
}

void Group::addStudent(Student& _student) {
	if (!this) {
		return;
	}
	if (findStudent(_student.id) >= 0) {
		return; // already added
	}
	if (_student.group) {
		_student.group->expelStudent(_student.id);
	}
	// resize students array logic
	if (students == nullptr) {
		capacity = Constants::ARRAY_INCREASING;
		students = new Student * [capacity];
	}
	if (studentsNum >= capacity) {
		capacity += Constants::ARRAY_INCREASING;
		Student** tmpStudents = new Student * [capacity];
		if (tmpStudents == nullptr) {
			throw std::bad_alloc();
		}
		std::copy(students, students + studentsNum, tmpStudents);
		// clean old array
		delete[] students;
		students = tmpStudents;
	}
	students[studentsNum++] = &_student;
	_student.group = this;
}

void Group::expelStudent(int _id) {
	int studentInd = findStudent(_id);
	if (studentInd >= 0) {
		students[studentInd]->group = nullptr;
		for (int i = studentInd; i < studentsNum - 1; ++i) {
			students[i] = students[i + 1];
		}
		--studentsNum;
	}
}

void Group::expelStudent(std::string _fio) {
	int studentInd = findStudent(_fio);
	if (studentInd >= 0) {
		for (int i = studentInd; i < studentsNum - 1; ++i) {
			students[i] = students[i + 1];
		}
		--studentsNum;
	}
}

int Group::findStudent(int _id) const {
	for (int i = 0; i < studentsNum; ++i) {
		if (students[i]->id == _id) {
			return i;
		}
	}
	return -1;
}

int Group::findStudent(std::string _fio) const {
	for (int i = 0; i < studentsNum; ++i) {
		if (students[i]->fio == _fio) {
			return i;
		}
	}
	return -1;
}

bool Group::electGroupHead(Student& _student) {
	// FIX ME find this student in array and if contains add
	if (findStudent(_student.id) >= 0) {
		head = &_student;
		return true;
	}
	return false;
}

double Group::averageMark() const {
	double sum = 0.0;
	int num = 0;
	for (int i = 0; i < studentsNum; ++i) {
		for (int j = 0; j < students[i]->marksNum; ++j) {
			sum += students[i]->marks[j];
			++num;
		}
	}
	return (num > 0) ? (sum / num) : 0.0;
}

Group::~Group() {
	delete[] students;
}