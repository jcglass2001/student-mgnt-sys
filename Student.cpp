#include "Student.h"

Student::Student(std::string name_param, int age_param, int id_param, int grade_param) :
    name(name_param), age(age_param), id(id_param), grade(grade_param) {};

std::string Student::getName() const {
    return name;
}
int Student::getAge() const {
    return age;
}
int Student::getId() const {
    return id;
}
int Student::getGrade() const {
    return grade;
}
void Student::setName(const std::string& name_param) {
    name = name_param;
}
void Student::setAge(int age_param) {
    age = age_param;
}
void Student::setId(int id_param) {
    id = id_param;
}
void Student::setGrade(int grade_param) {
    grade = grade_param;
} 
void Student::display() const {
    std::cout << std::setw(10) << "ID:" << std::setw(10) << id 
              << std::setw(10) << "Name:" << std::setw(20) << name 
              << std::setw(10) << "Age:" << std::setw(5) << age 
              << std::setw(10) << "Grade:" << grade << std::endl;
}

StudentManager::StudentManager() {};

void StudentManager::addStudent(const Student& student_param) {
    students.push_back(student_param);
}
bool StudentManager::removeStudent(const Student& student_param) {
    for(size_t i; i < students.size(); ++i) {
        if(students.at(i).getId() == student_param.getId()){
            students.erase(students.begin() + i);
            return true;
        }
    }
    return false;
}
void StudentManager::display() const {
    for(const auto& student: students) student.display();
}