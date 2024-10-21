#include <iostream>
#include <filesystem>
#include <vector>
#include "Student.h"

void addStudentInput(StudentManager &manager);
void removeStudentInput(StudentManager &manager);
void saveAndExitInput(StudentManager &manager);
void loadCsvInput();
void showMenu();
std::vector<std::string> searchFilesInCurrentDirectoryByExtension();

int main()
{
    StudentManager manager;
    int input;

    std::cout << "======= Student Management System =======" << "\n";
    loadCsvInput();
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
            saveAndExitInput(manager);
            break;
        case 5:
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
    int id_input;
    std::cout << "Enter student ID: ";
    std::cin >> id_input;

    if (manager.removeStudentById(id_input)) 
        std::cout << "Student removed successfully..." << std::endl;
    else
        std::cout << "Student not found..." << std::endl;
}

void saveAndExitInput(StudentManager &manager)
{
    std::string filename;
    std::cout << "Enter filename to save (or type 'cancel' to abort): ";
    std::cin >> filename;

    if (filename == "cancel") {
        std::cout << "Save canceled." << std::endl;
        return;
    }
    manager.save(filename);
    std::cout << "Data saved. Exiting..." << std::endl;
}
void loadCsvInput(StudentManager &manager)
{
    std::cout << "Loading saved files...\n";
    auto saved_files = searchFilesInCurrentDirectoryByExtension();

    if (saved_files.empty()) { 
        std::cout << "No saves found..." << std::endl;
        return;
    }

    std::cout << "Found files: \n";
    for(size_t i = 0; i < saved_files.size(); ++i) {
        std::cout << "[" << i << "] " << saved_files.at(i) << "\n";
    }

    int input;
    std::cout << "Select save: ";
    
    while(!(std::cin >> input) || input < 0 || input >= saved_files.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid selection. Try again: ";
    }

    manager.load(saved_files[input]);

}
void showMenu()
{
    std::cout << "Please choose an option: " << "\n";
    std::cout << "1. Add Student " << "\n";
    std::cout << "2. Remove Student " << "\n";
    std::cout << "3. List All Students " << "\n";
    std::cout << "4. Save & Exit" << "\n";
    std::cout << "5. Exit" << std::endl;
}

const std::string CSV_EXTENSION = ".csv";
std::vector<std::string> searchFilesInCurrentDirectoryByExtension()
{
    std::vector<std::string> saves;
    std::string current_path = std::filesystem::current_path().string();

    for(const auto& entry : std::filesystem::directory_iterator(current_path)){
        if(entry.is_regular_file() && entry.path().extension() == CSV_EXTENSION) {
            saves.push_back(entry.path().filename().string());
        }
    }
    return saves;
}