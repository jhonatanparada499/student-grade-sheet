// Author: Tazim Ahmed
// Date: October 12, 2026
// File: Student.cpp - defines the Student class member functions

#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ---------- Constructors ----------

// Default constructor
Student::Student() {
    this->name = "";
}

// Parameterized constructor
Student::Student(const string& name) {
    this->name = name;
}

// ---------- Add a course ----------

void Student::addCourse(const Course& course) {
    courses.push_back(course);
}

// ---------- Getters ----------

string Student::getStudentName() const {
    return name;
}

int Student::getCourseCount() const {
    return courses.size();
}

// Adds up the credits of every course
int Student::getTotalCredits() const {
    int total = 0;
    for (int i = 0; i < getCourseCount(); i++) {
        total = total + courses[i].getCreditHours();
    }
    return total;
}

// Adds up the total points of every course
double Student::getTotalPoints() const {
    double total = 0.0;
    for (int i = 0; i < getCourseCount(); i++) {
        total = total + courses[i].getTotalPoints();
    }
    return total;
}

// GPA = total points / total credits
double Student::getGPA() const {
    if (getTotalCredits() == 0) {
        return 0.0; // cannot divide by zero, so return 0.0 if no credits
    }
    return getTotalPoints() / getTotalCredits();
}

string Student::getStanding() const {
    double gpa = getGPA();
    if (gpa >= 3.70) {
        return "Dean's List";
    } else if (gpa >= 2.00) {
        return "Good Standing";
    } else {
        return "Probation";
    }
}

// ---------- Sorting (extra credit) ----------

// true if course a should come before course b (credits high to low)
bool compareByCredits(const Course& a, const Course& b) {
    return a.getCreditHours() > b.getCreditHours();
}

// true if course a should come before course b (name A-Z)
bool compareByName(const Course& a, const Course& b) {
    return a.getCourseName() < b.getCourseName();
}

// ---------- Print the transcript ----------
void Student::printTranscript(int sortMode) const {
    // make a copy so the original order is not changed
    vector<Course> list = courses;

    if (sortMode == 1) {
        sort(list.begin(), list.end(), compareByCredits);
    } else if (sortMode == 2) {
        sort(list.begin(), list.end(), compareByName);
    }

    // Title
    cout << endl << endl << setfill('=') << setw(13) << "" << " Student Grade Report " << setw(13) << "" << setfill(' ') << endl;
    cout << "Student: " << name << endl;
    if (sortMode == 1) cout << "(sorted by credits)" << endl;
    if (sortMode == 2) cout << "(sorted by course name)" << endl;
    cout << endl;

    // Table header
    cout << left << setw(20) << "Course"
         << right << setw(8) << "Credits"
         << setw(10) << "GradePts"
         << setw(10) << "TotalPts" << endl;
    cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

    // One row for each course
    cout << fixed << setprecision(2);
    int count = list.size();
    for (int i = 0; i < count; i++) {
        cout << left << setw(20) << list[i].getCourseName()
             << right << setw(8) << list[i].getCreditHours()
             << setw(10) << list[i].getGradePoints()
             << setw(10) << list[i].getTotalPoints() << endl;
    }
    cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

    // Summary
    cout << "Total Credits: " << setw(13) << getTotalCredits() << endl;
    cout << "Total Points:  " << setw(15) << getTotalPoints() << endl;
    cout << "Semester GPA:  " << setw(15) << getGPA() << endl;
    cout << "Standing:      " << setw(20) << getStanding() << endl;
    cout << setfill('=') << setw(48) << "" << setfill(' ') << endl;
}