#include <iostream>
#include "Student.h"

void addStudentInput(StudentManager &manager);
void removeStudentInput(StudentManager &manager);
void showMenu();

int main()
{
    StudentManager manager;
    int input;

    std::cout << "======= Student Management System =======" << "\n";
    do
    {
        showMenu();

        std::cin >> input;
        switch (input)
        {
        case 1:
            addStudentInput(manager);
            break;
        case 2:
            removeStudentInput(manager);
            break;
        case 3:
            manager.display();
            break;
        case 4:
            std::cout << "Exiting program..." << std::endl;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        std::cout << std::endl;
    } while (input != 4);

    return 0;
}
void addStudentInput(StudentManager &manager)
{
    int age, grade, id;
    std::string name;

    std::cout << "Enter student information: " << std::endl;
    std::cout << "Student ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Grade: ";
    std::cin >> grade;

    manager.addStudent(Student(name, age, id, grade));
}
void removeStudentInput(StudentManager &manager)
{
    int id;
    std::cout << "Enter student ID: ";
    std::cin >> id;

    if (manager.removeStudent(Student("", 0, id, 0)))
    {
        std::cout << "Student removed successfully..." << std::endl;
    }
    else
    {
        std::cout << "Student not found..." << std::endl;
    }
}
void showMenu()
{
    std::cout << "Please choose an option: " << "\n";
    std::cout << "1. Add Student " << "\n";
    std::cout << "2. Remove Student " << "\n";
    std::cout << "3. List All Students " << "\n";
    std::cout << "4. Exit" << std::endl;
}