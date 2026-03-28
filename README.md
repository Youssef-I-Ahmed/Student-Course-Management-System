# Student Course Management System

A console-based C++ application for managing student records and course enrollments.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [How to Compile](#how-to-compile)
- [How to Run](#how-to-run)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Concepts Used](#concepts-used)

---

## Overview

This project is a menu-driven student management system built in C++. It allows users to add, remove, search, and display students, manage course enrollments, and sort students by GPA — all from the command line.

---

## Features

- Add a student with a unique ID, name, and GPA
- Remove a student by ID
- Search for a student by ID
- Display all students
- Enroll a student in a course (no duplicate courses)
- Show all courses a student is enrolled in
- Sort all students by GPA (descending)

---

## Requirements

- A C++ compiler that supports **C++11** or later
  - `g++` (Linux / macOS)
  - `g++` via MinGW or WSL (Windows)
  - MSVC (Visual Studio)

No external libraries or package managers are required.

---

## How to Compile

```bash
g++ -std=c++11 -o student_system App.cpp
```

---

## How to Run

**Linux / macOS:**
```bash
./student_system
```

**Windows:**
```bash
student_system.exe
```

---

## Usage

Once the program starts, you will see the main menu:

```
===== MENU =====
1. Add Student
2. Remove Student
3. Search Student
4. Display All Students
5. Enroll Student in Course
6. Show Student Courses
7. Sort Students by GPA
8. Exit
Enter choice:
```

### Example Session

```
Enter choice: 1
Enter ID: 1001
Enter Name: Ali
Enter GPA: 3.5
Student added successfully.

Enter choice: 5
Enter Student ID: 1001
Enter Course Name: Math
Course added.

Enter choice: 6
Enter Student ID: 1001
- Math

Enter choice: 8
Goodbye!
```

### Input Rules

| Field | Rule |
|-------|------|
| ID | Integer, must be unique |
| Name | Supports full names (spaces allowed) |
| GPA | Decimal between `0.0` and `4.0` |
| Course | Supports full course names (spaces allowed), no duplicates per student |

---

## Project Structure

```
.
├── App.cpp       # Main source file (all code)
├── README.md     # This file
└── Report.docx   # Full project report
```

---

## Concepts Used

| Concept | Where |
|---------|-------|
| OOP – Inheritance | `Student` inherits from `Person` |
| OOP – Encapsulation | Private attributes with public getters |
| OOP – Constructors | Both classes use constructors |
| STL – `vector` | Stores the list of all students |
| STL – `set` | Stores each student's courses (no duplicates) |
| STL – `sort` | Sorts students by GPA using a comparator function |
| Modular Design | Each feature is a separate function |
