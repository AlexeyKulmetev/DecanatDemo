#ifndef DEKANAT
#define DEKANAT

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include "Group.hpp"
#include "Student.hpp"

class Student;
class Group;

//class Student {
//private:
//	int id = 0;
//	std::string fio;
//	Group* group = nullptr;
//	int* marks = nullptr;
//	int marksNum = 0;
//	int capacity = 0;
//
//	friend class Group;
//
//public:
//	Student() = delete;

	//Student(const int _id, const char* _fio){
	//	if (_id < 0) throw std::invalid_argument("ID must be non-negative");
	//	if (!_fio || !*_fio) throw std::invalid_argument("FIO cannot be empty");
	//	id = _id;
	//	fio = _fio;
	//}

	//Student(const Student& other) : id(other.id), fio(other.fio), group(other.group),
	//	marksNum(other.marksNum), capacity(other.capacity) {
	//	marks = new int[capacity];
	//	std::copy(other.marks, other.marks + other.marksNum, marks);
	//}

	// FIX ME create move constructor

	//Student& operator = (const Student& other) {
	//	if (this == &other) {
	//		return *this;
	//	}
	//	int* tmpMarks = new int[other.capacity];
	//	std::copy(other.marks, other.marks + other.marksNum, tmpMarks);
	//	// delete old array marks
	//	delete[] marks;

	//	// assign values
	//	id = other.id;
	//	fio = other.fio;
	//	group = other.group;
	//	marks = tmpMarks;
	//	marksNum = other.marksNum;
	//	capacity = other.capacity;
	//	return *this;
	//}

	//~Student() {
	//	delete[] marks;
	//}

	//void enroll_to_group(Group* _group) {
	//	if (group == _group) {
	//		return; // is already enrolled
	//	}
	//	group->addStudent(*this);
	//}

	//Group* getGroup() const {
	//	return group;
	//}

	//void addMark(int _mark) {
	//	if (marks == nullptr) {
	//		capacity = ARRAY_INCREASING;
	//		marks = new int[capacity];
	//	}

	//	if (marksNum >= capacity) {
	//		capacity += ARRAY_INCREASING;
	//		int* tmpMarks = new int[capacity];
	//		if (tmpMarks == nullptr) {
	//			throw::std::bad_alloc();
	//		}
	//		std::copy(marks, marks + marksNum, tmpMarks);
	//		// clean old array
	//		delete[] marks;
	//		marks = tmpMarks;
	//	}
	//	marks[marksNum++] = _mark;
	//}
	
	//double averageMark() const {
	//	if (marksNum == 0) {
	//		std::cout << "Student has no marks yet";
	//		return 0.0;
	//	}
	//	double sum = 0;
	//	for (int i = 0; i < marksNum; ++i) {
	//		sum += marks[i];
	//	}
	//	return sum / marksNum;
	//}

//	void printMarks() const {
//		if (marksNum == 0) {
//			std::cout << "Student has no marks yet";
//			return;
//		}
//		for (int i = 0; i < marksNum; ++i) {
//			std::cout << marks[i];
//			if (i < marksNum - 1) std::cout << ", ";
//		}
//	}
//};


//class Group {
//	std::string title;
//	Student** students = nullptr;
//	int studentsNum = 0;
//	int capacity = 0;
//	Student* head = nullptr;

//public:
	//Group(const char* _title) : title(_title) {}

	//Group(const Group&) = delete;

	//Group& operator = (const Group&) = delete;

	//void addStudent(Student& _student) {
	//	if (findStudent(_student.id)) {
	//		return; // already added
	//	}
	//	if (_student.group) {
	//		_student.group->expelStudent(_student.id);
	//	}
	//	// resize students array logic
	//	if (students == nullptr) {
	//		capacity = ARRAY_INCREASING;
	//		students = new Student * [capacity];
	//	}
	//	if (studentsNum >= capacity) {
	//		capacity += ARRAY_INCREASING;
	//		Student** tmpStudents = new Student*[capacity];
	//		if (tmpStudents == nullptr) {
	//			throw std::bad_alloc();
	//		}
	//		std::copy(students, students + studentsNum, tmpStudents);
	//		// clean old array
	//		delete[] students;
	//		students = tmpStudents;
	//	}
	//	students[studentsNum++] = &_student;
	//	_student.group = this;
	//}
	
	// delete student from array
	//void expelStudent(int _id) {
	//	int studentInd = findStudent(_id);
	//	if (studentInd >= 0) {
	//		students[studentInd]->group = nullptr; 
	//		for (int i = studentInd; i < studentsNum - 1; ++i) {
	//			students[i] = students[i + 1];
	//		}
	//		--studentsNum;
	//	}
	//}
	
	// delete student from array
	//void expelStudent(std::string _fio) {
	//	int studentInd = findStudent(_fio);
	//	if (studentInd >= 0) {
	//		for (int i = studentInd; i < studentsNum - 1; ++i) {
	//			students[i] = students[i + 1];
	//		}
	//		--studentsNum;
	//	}
	//}
	
	// return index of student if found and -1 if not
	//int findStudent(std::string _fio) const {
	//	for (int i = 0; i < studentsNum; ++i) {
	//		if (students[i]->fio == _fio) {
	//			return i;
	//		}
	//	}
	//	return -1;
	//}

	// return index of student if found and -1 if not
	//int findStudent(int _id) const {
	//	for (int i = 0; i < studentsNum; ++i) {
	//		if (students[i]->id == _id) {
	//			return i;
	//		}
	//	}
	//	return -1;
	//}

	//bool electGroupHead(Student& _student) {
	//	// FIX ME find this student in array and if contains add
	//	if (findStudent(_student.id) >= 0) {
	//		head = &_student;
	//		return true;
	//	}
	//	return false;
	//}
	
	// calculate average mark of all students in group
	//double averageMark() const {
	//	double sum = 0.0;
	//	int num = 0;
	//	for (int i = 0; i < studentsNum; ++i) {
	//		for (int j = 0; j < students[i]->marksNum; ++j) {
	//			sum += students[i]->marks[j];
	//			++num;
	//		}
	//	}
	//	return (num > 0) ? (sum / num) : 0.0;
	//}

	//~Group() {
	//	delete[] students;
	//}
//};

class Dekanat {
	Student** students = nullptr;
	Group** groups = nullptr;
	int studentsNum = 0;
	int studentCapacity = 0;
	int groupsNum = 0;
	int groupCapacity = 0;

	Group* findGroup(std::string _groupName) const {
		for (int i = 0; i < groupsNum; ++i) {
			if (groups[i]->getTitle() == _groupName) {
				return groups[i];
			}
		}
		return nullptr;
	}

public:
	Dekanat() = default;

	Dekanat(const Dekanat&) = delete;

	~Dekanat() {
		delete[] students;
		delete[] groups;
	}

	// load groups from file method
	bool loadGroupsFromFile(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filename);
		}
		std::string groupName;
		while (file >> groupName) { // suitable for spaces/newlines separation
			// check empty lines
			if (groupName.empty()) continue;
			// resizing array if it neccessary
			if (groupsNum >= groupCapacity) {
				groupCapacity += ARRAY_INCREASING;
				Group** tmpGroups = new Group * [groupCapacity];
				if (tmpGroups == nullptr) {
					throw std::bad_alloc();
				}
				// copy existing array
				std::copy(groups, groups + groupsNum, tmpGroups);
				delete[] groups;
				groups = tmpGroups;
			}
			// add new group
			groups[groupsNum++] = new Group(groupName);
		}
		return true;
	}

	// load students from file method
	bool loadStudentsFromFiles(const std::string filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filename);
		}
		int tmpId;
		std::string tmpFio, tmpGroupName;
		while (file >> tmpId >> std::ws && std::getline(file, tmpFio, ' ')
			&& std::getline(file, tmpGroupName)) {
			// resizing array if it neccessary
			if (studentsNum >= studentCapacity) {
				studentCapacity += ARRAY_INCREASING;
				Student** tmpStudents = new Student * [studentCapacity];
				if (tmpStudents == nullptr) {
					throw std::bad_alloc();
				}
				std::copy(students, students + studentsNum, tmpStudents);
				delete[] students;
				students = tmpStudents;
			}
			// add new student
			students[studentsNum] = new Student(tmpId, tmpFio);
			students[studentsNum]->enrollToGroup(findGroup(tmpGroupName));
			++studentsNum;
		}
	}
};

#endif // !DEKANAT
