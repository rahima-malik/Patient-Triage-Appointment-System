# Patient Triage & Appointment Management System

## Project Overview

The **Patient Triage & Appointment Management System** is a console-based application developed in C++ to manage patient registration and waiting queues based on medical priority levels.

The system follows an automated priority-based approach to ensure that patients with more critical medical conditions are attended to before those with lower priority. It also maintains arrival order among patients with the same priority level.

This project demonstrates the practical implementation of Object-Oriented Programming (OOP) concepts in C++.

## Features

- **Patient Registration:** Add patients by entering their ID, name, age, and medical condition.
- **Patient Categorization:** Classify patients into General, Emergency, and Critical categories.
- **Priority-Based Queue Management:** Automatically arrange patients according to their assigned priority.
- **Arrival Order Management:** Maintain first-come, first-served order among patients with equal priority.
- **Waiting Queue Display:** View all registered patients and their current queue positions.
- **Next Patient Processing:** Call and remove the highest-priority patient from the waiting queue.
- **Input Validation:** Handle invalid patient category selections using exception handling.
- **Memory Management:** Dynamically allocate and release memory for patient objects.

## Patient Priority Levels

| Patient Category | Priority Level |
|---|---:|
| General Patient | 1 |
| Emergency Patient | 3 |
| Critical Patient | 5 |

**Priority Rule:** Patients with higher priority values are served first. If two patients have the same priority, the patient who arrived earlier is served first.

## Object-Oriented Programming Concepts

This project implements the following OOP concepts:

1. **Abstraction:** The `Patient` class is designed as an abstract base class with a pure virtual function.
2. **Inheritance:** `GeneralPatient`, `EmergencyPatient`, and `CriticalPatient` inherit from the `Patient` base class.
3. **Polymorphism:** Virtual functions enable different patient types to be handled through base-class pointers.
4. **Encapsulation:** Patient attributes are maintained within the class using protected access.
5. **Exception Handling:** A `try-catch` mechanism handles invalid patient type selections.

## Technologies Used

- **Programming Language:** C++
- **Programming Paradigm:** Object-Oriented Programming
- **Compiler:** Any C++ compiler supporting the required language features
- **Data Structure:** Array of base-class pointers
- **Memory Management:** Dynamic memory allocation using `new` and `delete`

## Application Menu

The application provides the following menu options:

1. Add Patient
2. View Waiting Queue
3. Call Next Patient
4. Exit

## Project Structure

```text
Patient-Triage-Appointment-System/
│
├── main.cpp
├── Patient_Triage_Appointment_System.pdf
└── README.md
```

## How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/Patient-Triage-Appointment-System.git
```

### Step 2: Navigate to the Project Directory

```bash
cd Patient-Triage-Appointment-System
```

### Step 3: Compile the Source Code

Using the GCC compiler:

```bash
g++ main.cpp -o patient_triage
```

### Step 4: Execute the Application

On Windows:

```bash
patient_triage.exe
```

On Linux or macOS:

```bash
./patient_triage
```

## Project Documentation

The complete project documentation, including the source code and technical overview, is available in:

**`Patient_Triage_Appointment_System.pdf`**

## Learning Outcomes

This project provides practical experience in:

- Designing abstract classes and derived classes.
- Implementing inheritance and runtime polymorphism.
- Managing objects through base-class pointers.
- Implementing priority-based patient scheduling.
- Applying exception handling and dynamic memory management.

## Conclusion

The Patient Triage & Appointment Management System demonstrates how C++ and Object-Oriented Programming principles can be applied to develop a basic patient prioritization and queue management application.

The project provides a structured approach to patient registration, priority assignment, waiting queue organization, and patient processing.

---

**Project Name:** Patient Triage & Appointment Management System  
**Language:** C++  
**Project Type:** Object-Oriented Programming  
