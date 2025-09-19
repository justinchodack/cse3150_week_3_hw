
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes

void addStudent(char* name, double gp, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double gpa, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);


// TODO: implement addStudent

void addStudent(char* name, double gp, char* names[], double gpas[], int& size, int capacity){
    if(size == capacity)
        throw "List full";
    names[size] = name;
    gpas[size] = gp;
    size++;
}

// TODO: implement updateGPA

void updateGPA(double* gpPtr, double newGpa){
    *gpPtr = newGpa;
}

// TODO: implement printStudent

void printStudent(const char* name, const double& gpa){
    std::cout << "Name, GPA: " << name << ", " << gpa  << std::endl;
}

// TODO: implement averageGPA

double averageGPA(const double gpas[], int size){
    if(size == 0)
        throw "No students";

    double total = 0.0;
    for(int i = 0; i < size; i++){
        total += gpas[i];
    }

    return total / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic

                std::cout << "Enter name: " << std::endl;
                std::string temp;
                std::cin >> temp;

                int len = temp.length();
                char* name = new char[len + 1];
                std::strcpy(name, temp.c_str()); //Check this line over

                std::cout << "Enter GPA: " << std::endl;
                double gpa = 0.0;
                std::cin >> gpa;

                try{
                    addStudent(name, gpa, names, gpas, size, capacity);
                } catch (const char* msg){
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic

                std::cout << "Enter student number" << std::endl;
                int student;
                std::cin >> student;

                std::cout << "Enter new GPA: " << std::endl;
                double newGpa = 0.0;
                std::cin >> newGpa;

                updateGPA(&gpas[student], newGpa);
                break;
            }
            case 3: {
                // TODO: implement menu logic

                for(int i = 0; i < size; i++){
                    printStudent(names[i], gpas[i]);
                }

                break;
            }
            case 4: {
                // TODO: implement menu logic

                double avg = 0.0;
                try{
                    avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << static_cast<int>(averageGPA(gpas, size)) << std::endl;
                } catch (const char* msg){
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory

    for(int i = 0; i < size; i++){
        delete[] names[i];
    }

    return 0;
}
