#include <string>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <cstring>
class Student
{
    private:
        int age;
        int id;
        int grade;
        std::string name;
    public:
        Student();
        Student(const std::string& name_param, int age_param, int id_param, int grade_param);
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
        std::unordered_map<int, Student> students;
    public:
        StudentManager();
        bool addStudent(const Student& student_param);
        bool removeStudentById(int id_param);
        void display() const;
        bool save(const std::string& filename);
        bool load(const std::string& file_path);
};