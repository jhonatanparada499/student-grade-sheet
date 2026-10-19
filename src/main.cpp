// main.cpp

/**
 * Author(s): Tazim Ahmed & Jhonatan Parada
 * Date: October 17, 2026
 * Group: 7
 *
 * Git Repo:
 * github.com/jhonatanparada499/student-grade-sheet
 */

#include <iostream>
#include <string>
// Required for numeric_limits in cin.ignore
#include <limits>

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
            cin.clear(); // reset cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // throw away bad input
            cout << "  Invalid input. Please enter a number." << endl;
        } else if (number < min || number > max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a number from " << min << " to " << max << "." << endl;
        } else {
            // remove the leftover Enter key so getline works next time
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    student.printTranscript(2); // Sort asc by course name

    return 0;
}


/**
 * Jhonatan's Reflection: I was reviewing Tazim's code and noticed that
 * cin.ignore was being given a paramter of 1000(meaning the first 1000
 * characters until it hits \n) But then I remember the class slides. Something
 * called numberic_limits was being used instead. So I suggested the changes to
 * Tazim. cin.ignore is pretty much used when a program uses the shift operator
 * (<<) and the getline function. If it only used <<, it wouldn't be necessary.
 *
 * Tazim's Reflection: Working on this file became easier after we had 
 * the Student and Course classes. I learned that the main function 
 * should handle user input and output, while the Student and Course classes 
 * should handle the data and calculations like backend logic. I also 
 * learned that it is important to validate user input to prevent errors.
 * Like created unlimited loops for getGrade, getText and getNumber to get 
 * the user to enter the correct input. I also learned that the main 
 * function should be kept simple and not contain too much logic, 
 * and that it should delegate tasks to the appropriate classes and methods.
 */
