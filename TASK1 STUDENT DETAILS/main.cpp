#include <iostream>
#include <string>

const int MAX_STUDENTS = 40;

struct Grade {
    int mark;
    char the_grade;
};

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Student {
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grade;
    bool grades_calculated;  // Added flag to ensure grades are not altered
};

char calculateGrade(int mark) {
    return (mark > 69) ? 'A' : (mark > 59) ? 'B' : (mark > 49) ? 'C' : (mark > 39) ? 'D' : 'E';
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;
        std::cout << "Enter registration number, name, age, course code, and course name: ";
        std::cin >> newStudent.reg_number >> newStudent.name >> newStudent.age >> newStudent.course.course_code >> newStudent.course.course_name;
        newStudent.grades_calculated = false;  // Initialize the flag
        students[numStudents++] = newStudent;
    } else {
        std::cout << "Maximum number of students reached!" << std::endl;
    }
}

void editStudentDetails(Student students[], int numStudents) {
    std::string regNumber;
    std::cout << "Enter registration number of the student to edit: ";
    std::cin >> regNumber;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_number == regNumber) {
            std::cout << "Enter new name: ";
            std::cin >> students[i].name;

            std::cout << "Enter new age: ";
            std::cin >> students[i].age;
            return;
        }
    }

    std::cout << "Student not found!" << std::endl;
}

void addMarksAndCalculateGrades(Student students[], int numStudents) {
    std::string regNumber;
    std::cout << "Enter registration number of the student: ";
    std::cin >> regNumber;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_number == regNumber) {
            if (!students[i].grades_calculated) {
                std::cout << "Enter marks: ";
                std::cin >> students[i].grade.mark;

                // Calculate grade based on marks
                students[i].grade.the_grade = calculateGrade(students[i].grade.mark);

                students[i].grades_calculated = true;  // Set the flag to true
                std::cout << "Marks added and grade calculated successfully!" << std::endl;
            } else {
                std::cout << "Grades for this student have already been calculated and cannot be altered." << std::endl;
            }
            return;
        }
    }

    std::cout << "Student not found!" << std::endl;
}

void displayStudentDetails(const Student& student) {
    std::cout << "Registration Number: " << student.reg_number << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Age: " << student.age << std::endl;
    std::cout << "Course Code: " << student.course.course_code << std::endl;
    std::cout << "Course Name: " << student.course.course_name << std::endl;
    if (student.grades_calculated) {
        std::cout << "Mark: " << student.grade.mark << std::endl;
        std::cout << "Grade: " << student.grade.the_grade << std::endl;
    } else {
        std::cout << "Grades not calculated yet." << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void displayAllStudents(const Student students[], int numStudents) {
    if (numStudents > 0) {
        for (int i = 0; i < numStudents; ++i) {
            displayStudentDetails(students[i]);
        }
    } else {
        std::cout << "No students available." << std::endl;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        std::cout << "Menu: 1. Add Student 2. Edit Student Details 3. Add Marks and Calculate Grades 4. Display All Students 5. Exit - Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                editStudentDetails(students, numStudents);
                break;
            case 3:
                addMarksAndCalculateGrades(students, numStudents);
                break;
            case 4:
                displayAllStudents(students, numStudents);
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }

    } while (choice != 5);

    return 0;
}
