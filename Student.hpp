#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <string>
#include <stdexcept>

class Group;

class Student {
private:
	int id = 0;
	std::string fio;
	Group* group = nullptr;
	int* marks = nullptr;
	int marksNum = 0;
	int capacity = 0;

	friend class Group;

public:
	Student() = delete;

	Student(const int _id, const char* _fio);

	Student(const int _id, const std::string _fio);

	Student(const Student& other);

	Student& operator = (const Student& other);

	~Student();

	void print() const;

	void enrollToGroup(Group* _group);

	Group* getGroup() const;

	void addMark(int _mark);

	double averageMark() const;

	void printMarks() const;
};

#endif // !STUDENT
