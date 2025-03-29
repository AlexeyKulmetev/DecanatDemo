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
	Group* group = nullptr;
	int* marks = nullptr;
	int marksNum = 0;
	int capacity = 0;

	friend class Group;

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

	void enroll_to_group(Group* _group) {
		if (group == _group) {
			return; // is already enrolled
		}
		group->addStudent(*this);
	}

	Group* getGroup() const {
		return group;
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

	void addStudent(Student& _student) {
		// resize students array logic
		if (students == nullptr) {
			capacity = ARRAY_INCREASING;
			students = new Student * [capacity];
		}
		if (studentsNum >= capacity) {
			capacity += ARRAY_INCREASING;
			Student** tmpStudents = new Student*[capacity];
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
	// delete student from array
	void expelStudent(int _id) {
		int studentInd = findStudent(_id);
		if (studentInd >= 0) {
			for (int i = studentInd; i < studentsNum - 1; ++i) {
				students[i] = students[i + 1];
			}
			--studentsNum;
		}
	}
	// delete student from array
	void expelStudent(std::string _fio) {
		int studentInd = findStudent(_fio);
		if (studentInd >= 0) {
			for (int i = studentInd; i < studentsNum - 1; ++i) {
				students[i] = students[i + 1];
			}
			--studentsNum;
		}
	}
	// return index of student if found and -1 if not
	int findStudent(std::string _fio) const {
		for (int i = 0; i < studentsNum; ++i) {
			if (students[i]->fio == _fio) {
				return i;
			}
		}
		return -1;
	}
	// return index of student if found and -1 if not
	int findStudent(int _id) const {
		for (int i = 0; i < studentsNum; ++i) {
			if (students[i]->id == _id) {
				return i;
			}
		}
		return -1;
	}

	bool electGroupHead(Student& _student) {
		// FIX ME find this student in array and if contains add
		if (findStudent(_student.id) >= 0) {
			head = &_student;
			return true;
		}
		return false;
	}
	// calculate average mark of all students in group
	double averageMark() const {
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
