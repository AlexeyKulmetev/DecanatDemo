#ifndef DEKANAT
#define DEKANAT

#include<algorithm>
#include<iostream>
#include<string>

const int ARRAY_INCREASING = 5;

class Group;

class Student {
private:
	int id = 0;
	std::string fio;
	Group* group = nullptr;	// not a reference to be able to change the group
	int* marks = nullptr;		// perhaps it shuold be int marks[];
	int marksNum = 0;	// number of marks
	int capacity = 0;
public:
	Student() = delete;
	Student(int _id, const char* _fio) : id(_id), fio(_fio) {}

	~Student() {
		delete[] marks;
	}

	void enroll_to_group(Group* _group) {
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

			delete[] marks;
			marks = tmpMarks;
			tmpMarks = nullptr;
		}
		marks[marksNum++] = _mark;
	}
	void printMarks() {
		for (int i = 0; i < marksNum; ++i) {
			std::cout << *(marks + 1) << " ";
		}
	}
};


class Group {
	std::string title;
	Student** students = nullptr;
	int studntNum = 0;
	Student* head = nullptr;

public:
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
