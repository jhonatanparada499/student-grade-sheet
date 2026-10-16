# Student Grade Sheet
A student transcript manager.

## Requirements
- cmake
- C/C++ compiler such as g++

## Quick Start
```
$ cmake -B build # Run only once
$ cmake --build build
$ ./build/student-grade-sheet
```

Checkout the dashboard quickly using a sample file:  
```
$ ./build/student-grade-sheet < test-input.txt
```

## Progress
Student.h: Done  
Course.h: Done  
Student.cpp: Need reflections  
Course.cpp: Needs Tazim's reflections  
main.cpp: Needs reflections   

## Tasks
- fix parameter in cin.ignore to reflect class slides.
- How to pass input streams from files to the code
- add func to uppercase course names
- Fix format for Total Credits entry
- Fix this ENG 201                    3      3.35     10.05 (it should say 3.30 for letter C+)
- Maybe remove the sort prompt since it is not specified in the instructions?

