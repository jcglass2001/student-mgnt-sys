#include "Student.h"

Student::Student() : name(""), age(0), id(0), grade(0) {};
Student::Student(const std::string& name_param, int age_param, int id_param, int grade_param) :
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

bool StudentManager::addStudent(const Student& student_param) {
    if (students.find(student_param.getId()) != students.end()) {
        std::cout << "Error: Student with input ID already exists..." << std::endl;
        return false;
    }
    students[student_param.getId()] = student_param;
    return true;
}
bool StudentManager::removeStudentById(int id_param) {
    auto it = students.find(id_param);
    if(it != students.end()) {
        students.erase(it);
        return true;
    }
    return false;
}
void StudentManager::display() const {
    std::cout << "==================== Student List =====================";
    for(const auto& entry: students) entry.second.display();
    std::cout << "=======================================================" << std::endl;
}

bool StudentManager::save(const std::string& filename) {
    std::ofstream file(filename);
    
    if(!file.is_open()) {
        std::cerr << "Error: Could not open file. \n";
        return false;
    }

    file << "ID,Name,Age,Grade\n";

    for(const auto& entry: students) { 
        file << entry.second.getId() << "," << entry.second.getName() 
             << "," << entry.second.getAge() << "," << entry.second.getGrade() << "\n";
    }

    file.close();

    std::cout << "Data successfully written to file: " + filename << std::endl;
    return true;
}

Student parseLineToStudent(std::string line) {
    std::stringstream ss(line);
    std::string name, age_str, grade_str, id_str;

    getline(ss, id_str, ',');
    getline(ss, name, ',');
    getline(ss, age_str, ',');
    getline(ss, grade_str, ',');

    int age = std::stoi(age_str);
    int id = std::stoi(id_str);
    int grade = std::stoi(grade_str);

    return Student(name, age, id, grade);
}

bool StudentManager::load(const std::string& file_path) {
    std::ifstream file(file_path);

    if(!file.is_open()) {
        std::cout << "Error: Unable to open file at path: " << file_path << std::endl;
        return false;
    }
    
    std::string line;
    bool first_line = true;
    while(getline(file,line)) {
        if(first_line){
            first_line = false;
            continue;
        }
        if(!line.empty()) {
            try {
                auto parsed_student = parseLineToStudent(line);
                students[parsed_student.getId()] = parsed_student;
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << e.what() << std::endl;
            }
        }
    }

    file.close();
    return true;
}

