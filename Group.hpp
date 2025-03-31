#ifndef GROUP
#define GROUP
#include <string>

class Student;

class Group {
private:
	std::string title;
	Student** students = nullptr;
	int studentsNum = 0;
	int capacity = 0;
	Student* head = nullptr;

public:
	Group(const char* _title);

	Group(const Group&) = delete;

	Group& operator = (const Group&) = delete;

	// FIX ME create move constructor, assignment operator, copy constructor

	void addStudent(Student& _student);

	void expelStudent(int _id);

	void expelStudent(std::string _fio);

	int findStudent(int _id) const;

	int findStudent(std::string _fio) const;

	bool electGroupHead(Student& _student);

	double averageMark() const;

	~Group();
};


#endif // !GROUP
