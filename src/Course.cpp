// Course.cpp

/**
 * Author(s): Jhonatan Parada & Tazim Ahmed & Justin Rodriguez
 * Date: Oct 17, 2026
 * Group: 7
 */

#include "Course.h"
#include <string>

using namespace std; 

// ---------- Constructors ----------
// Default constructor
Course::Course() {
    courseName = "";
    creditHours = 0;
    letterGrade = "F";
}
 
// Parameterized constructor
Course::Course(const string& courseName, int creditHours, const string& letterGrade) {
    this->courseName = courseName;
    this->creditHours = creditHours;
    this->letterGrade = letterGrade;
}

// ---------- Getters ----------
string Course::getCourseName() const { return courseName; }
int Course::getCreditHours() const { return creditHours; }
string Course::getLetterGrade() const { return letterGrade; }
 
double Course::getGradePoints() const {
    return gradeToPoints(letterGrade);
}
 
double Course::getTotalPoints() const {
    return creditHours * getGradePoints();
}

// Returns true only for the 12 allowed letter grades
bool Course::isValidGrade(const string& letterGrade) {
    return letterGrade == "A"  || letterGrade == "A-" ||
           letterGrade == "B+" || letterGrade == "B"  || letterGrade == "B-" ||
           letterGrade == "C+" || letterGrade == "C"  || letterGrade == "C-" ||
           letterGrade == "D+" || letterGrade == "D"  || letterGrade == "D-" ||
           letterGrade == "F";
}
 
// Find the grade points for a letter grade per credit
double Course::gradeToPoints(const string& letterGrade) {
    if (letterGrade == "A")  return 4.0;
    if (letterGrade == "A-") return 3.7;
    if (letterGrade == "B+") return 3.3;
    if (letterGrade == "B")  return 3.0;
    if (letterGrade == "B-") return 2.7;
    if (letterGrade == "C+") return 2.3;
    if (letterGrade == "C")  return 2.0;
    if (letterGrade == "C-") return 1.7;
    if (letterGrade == "D+")  return 1.3;
    if (letterGrade == "D")  return 1.0;
    if (letterGrade == "D-") return 0.7;
    return 0.0;        // F (or anything unexpected)
}

/**
 * Jhonatan's Reflection: While coding this particular file I learned that you
 * cannot call a non-const function inside a const function. I spent 2 hours
 * trying to debug an error regarding the gradeToPoints function, but it wasn't
 * const. So I went to the Course.h file and made const.
 *
 * Tazim's Reflection: While working on this file, it was pretty easy as 
 * professor gave us most of the variables ideas like courseName, creditHours
 * and letterGrade. I learned that the Course class should have methods
 * as wellto get the value for course name, credit hours, letter grade, 
 * grade points and total points. and also methods to check if the grade
 * is valid and to convert the grade to points as the letterGrade is in 
 * string format.
 *
 *Justins Reflection:
 * while working on this file, i learned more about how classes and functions work together c++. 
 * I also learned how to use methos to get values like course names, credit hours,
 * and grades. This helped me better understand how to organize code and 
 * and make sure everything works correctly. 
 */
