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

	Group(const Group&);

	Group& operator = (const Group&);

	void addStudent(Student& _student);

	void expelStudent(int _id);

	void expelStudent(std::string _fio);

	int findStudent(std::string _fio) const;

	int findStudent(int _id) const;

	bool electGroupHead(Student& _student);

	double averageMark() const;

	~Group();
};


#endif // !GROUP
