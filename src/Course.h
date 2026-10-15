// Course.h

/**
 * Author(s): Jhonatan Parada & Tazim Ahmed & Justin Rodriguez
 * Date: Oct 17, 2026
 * Group: 7
 */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

using namespace std;

class Course {
private:
    string courseName;
    int creditHours;
    string letterGrade;

public:
    // Constructors
    Course();
    Course(const string& courseName, int creditHours, const string& letterGrade);

    // Const getters (they do not change the object)
    string getCourseName() const;
    int getCreditHours() const;
    string getLetterGrade() const;
    double getGradePoints() const;
    double getTotalPoints() const;

    // Helpers that belong to the class but don't need an object
    static bool isValidGrade(const string& letterGrade);
    static double gradeToPoints(const string& letterGrade);
};

#endif
