#ifndef DEKANAT
#define DEKANAT

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include "Group.hpp"
#include "shared_constants.hpp"
#include "Student.hpp"

class Student;
class Group;

class Dekanat {
	Student** students = nullptr;
	int studentsNum = 0;
	int studentCapacity = 0;

	Group** groups = nullptr;
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
				groupCapacity += Constants::ARRAY_INCREASING;
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
				studentCapacity += Constants::ARRAY_INCREASING;
				Student** tmpStudents = new Student * [studentCapacity];
				if (tmpStudents == nullptr) {
					throw std::bad_alloc();
				}
				std::copy(students, students + studentsNum, tmpStudents);
				delete[] students;
				students = tmpStudents;
			}
			Group* group = findGroup(tmpGroupName);
			if (!group) {
				std::cerr << "Warning: group " << tmpGroupName
					<< " not found for student " << tmpId << std::endl;
				continue;
			}
			// add new student
			students[studentsNum] = new Student(tmpId, tmpFio);
			students[studentsNum]->enrollToGroup(findGroup(tmpGroupName));
			++studentsNum;
		}
	}

	void printGroups() const {
		for (int i = 0; i < groupsNum; ++i) {
			groups[i]->print();
			std::cout << std::endl;
		}
	}

	void printStudents() const {
		for (int i = 0; i < studentsNum; ++i) {
			students[i]->print();
			std::cout << std::endl;
		}
	}
};

#endif // !DEKANAT
