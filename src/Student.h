// Student.h

/**
 * Author(s): Jhonatan Parada & Tazim Ahmed
 * Date: Oct 17, 2026
 * Group: 7
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

using namespace std;

class Student {
private:
  string name;
  vector<Course> courses;

public:
    // Constructors
    Student();
    Student(const string& name);

    // Add a course to the list
    void addCourse(const Course& course);

    // Getters
    string getStudentName() const;
    int getCourseCount() const;
    int getTotalCredits() const;
    double getTotalPoints() const;
    double getGPA() const;
    string getStanding() const;

    // sortMode: 0 = order entered, 1 = by credits, 2 = by name
    void printTranscript(int sortMode = 0) const;
};


#endif

/**
 * Jhonatan's Reflection: It was tricky to design the Student class due to the
 * lack of detail in the instructios. But, since it is mentioned that Student
 * should have Courses, I defined a vector with Course types. And I realized
 * that it makes sense.
 *
 * Tazim's Reflection: It was tricky to design the Student class because I
 *  had to think about what attributes and methods a Student class should have.
 *  I learned that a Student class should have a name and a list of courses,
 *  and that it should have methods to add courses, get the total credits and
 *  points, calculate the GPA, and print the transcript.
 */
