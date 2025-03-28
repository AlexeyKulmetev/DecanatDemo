#ifndef DEKANAT
#define DEKANAT

#include<algorithm>
#include<iostream>
#include<string>

const int ARRAY_INCREASING = 5;

class Student;
class Group;
class Dekanat;

class Student {
private:
	int id = 0;
	std::string fio;
	// perhaps need to declare Group class as a friend to give him access to field group
	// or make it protected preferably
	Group* group = nullptr;	// not a reference to be able to change the group 
	int* marks = nullptr;		// perhaps it shuold be int marks[];
	int marksNum = 0;	// number of marks
	int capacity = 0;

protected:


public:
	Student() = delete;

	Student(int _id, const char* _fio) : id(_id), fio(_fio) {}

	Student(const Student& other) : id(other.id), fio(other.fio), group(other.group),
		marksNum(other.marksNum), capacity(other.capacity) {
		marks = new int[capacity];
		std::copy(other.marks, other.marks + other.marksNum, marks);
	}

	Student& operator = (const Student& other) {
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

	~Student() {
		delete[] marks;
	}
	// FIX ME perhaps should add this object to students array in Group class
	void enroll_to_group(Group* _group) {
		if (group == _group) {
			return; // is already enrolled
		}
		group->addStudent(*this);
	}

	// FIX ME is it neccesary?
	Group* getGroup() const {
		return group;
	}

	void setGroup(Group* _group) {
		group = _group;
	}

	void addMark(int _mark) {
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
	
	double averageMark() {
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

	void printMarks() const {
		if (marksNum == 0) {
			std::cout << "Student has no marks yet";
			return;
		}
		for (int i = 0; i < marksNum; ++i) {
			std::cout << *(marks + i);
			if (i < marksNum - 1) std::cout << ", ";
		}
	}
};


class Group {
	std::string title;
	Student** students = nullptr;
	int studentsNum = 0;
	int capacity = 0;
	Student* head = nullptr;

public:
	Group(const char* _title) : title(_title) {}

	void addStudent (Student& _student) {
		// resize students array logic


		students[studentsNum++] = &_student;
		_student.setGroup(this);
	}

	~Group() {
		delete[] students;
	}
};

class Dekanat {
	Student* students = nullptr;
	Group* groups = nullptr;

	~Dekanat() {
		delete[] students;
		delete[] groups; // FIX ME why this field is unavailable
	}
};

#endif // !DEKANAT
