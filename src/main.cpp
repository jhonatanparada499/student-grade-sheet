// Author: Tazim Ahmed
// Date: October 12, 2026
// Course: CSCI 272 - Object Oriented Programming
// Group Project: Student Grade Sheet 

#include <iostream>
#include <string>
#include <cctype>
#include "Course.h"
#include "Student.h"

using namespace std;

// Asks for a whole number between min and max.

 int getNumber(string str, int min, int max) {
    int number;
    while (true) {
        cout << str;
        cin >> number;

        if (cin.fail()) {
            // user typed letters instead of a number
            cin.clear(); // reset cin
            cin.ignore(1000, '\n'); // throw away bad input
            cout << "  Invalid input. Please enter a number." << endl;
        } else if (number < min || number > max) {
            cin.ignore(1000, '\n');
            cout << "  Please enter a number from " << min << " to " << max << "." << endl;
        } else {
            // remove the leftover Enter key so getline works next time
            cin.ignore(1000, '\n');
            return number;
        }
    }
}

// Asks for a line of text (can have spaces). Keeps asking if it is empty.
string getText(string str) {
    string text;
    while (true) {
        cout << str;
        getline(cin, text);
        if (text != "") {
            return text;
        }
        cout << "Input cannot be empty. Please try again." << endl;
    }
}

// Asks for a letter grade. Keeps asking until it is valid.
string getGrade(string str) {
    while (true) {
        string grade = getText(str);

        // change lowercase letters to uppercase (a- becomes A-)
        int length = grade.length();
        for (int i = 0; i < length; i++) {
            grade[i] = toupper(grade[i]);
        }

        if (Course::isValidGrade(grade)) {
            return grade;
        }
        cout << "  Invalid grade. Allowed: A, A-, B+, B, B-, C+, C, C-, D, F\n";
    }
}

int main() {
    cout << "=== Student Grade Sheet ===\n";

    // 1. Get the student's name and create the Student object
    string name = getText("Enter student's full name: ");
    Student student(name);

    // 2. Get the number of courses
    int numCourses = getNumber("Enter number of courses (1-10): ", 1, 10);

    // 3. Get the information for each course
    for (int i = 1; i <= numCourses; i++) {
        cout << "\nCourse " << i << ":" << endl;
        string courseName = getText("\tCourse name: ");
        int credits = getNumber("\tCredit hours: ", 0, 30);
        string grade = getGrade("\tLetter grade: ");

        Course course(courseName, credits, grade);
        student.addCourse(course);
    }

    // 4. Print the transcript
    student.printTranscript(0);

    // 5. Extra credit
    cout << "\nSort the transcript?\n";
    cout << "  0 = No" << endl;
    cout << "  1 = By credits (highest first)" << endl;
    cout << "  2 = By course name (A-Z)" << endl;
    int choice = getNumber("Your choice: ", 0, 2);

    if (choice != 0) {
        student.printTranscript(choice);
    }

    return 0;
}
