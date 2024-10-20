#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
class Student
{
    private:
        int age;
        int id;
        int grade;
        std::string name;
    public:
        Student(std::string name_param, int age_param, int id_param, int grade_param);
        std::string getName() const;
        int getAge() const;
        int getId() const;
        int getGrade() const;
        void setName(const std::string& name_param);
        void setAge(int age_param);
        void setId(int id_param);
        void setGrade(int grade_param);
        void display() const;
};

class StudentManager
{
    private:
        std::vector<Student> students;
    public:
        StudentManager();
        void addStudent(const Student& student);
        bool removeStudent(const Student& student);
        void display() const;
        void save();
        void load();
};