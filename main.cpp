// stores a list of students, their ID, and their GPA
// has ADD, PRINT, DELETE, and HELP functions
#include <iostream>
#include <vector> // for vector data type
#include <cstring> // for strcmp()
#include <cstdlib> // for strtol() + strtof()
#include <cmath> // for round()
using namespace std;

struct Student{
  // struct used for storing student values
  const char* name1 = "Anita"; // first name
  const char* name2 = "Jabłońskí"; // last name
  int id = 123456; // ID
  float gpa = 3.0; // GPA
};

namespace studentlist{
  // public objects for this program
  char version[20] = "0.1.1";
  vector<Student> students;

}

using namespace studentlist;

void print(const char* text = ""){
  // cout wrapper, similar to python print()
  cout << text << '\n' << flush;
  return;
}

const char* input(const char* text = ""){
  // cin wrapper, similar to python input()
  cout << text << flush;
  char input[81]; // handle up to 80 chars
  cin >> input;
  const char* input1 = input;
  return input1;
}

void add_student(){
  // adds a student based on user input
  char* pEnd; // this is needed for some low-level memory stuff in strtol and strtof
  const char* name1 = input("Enter the student's first name: ");
  const char* name2 = input("Enter the student's last name: ");
  const char* id = input("Enter the student ID: ");
  int id1 = strtol(id, &pEnd, 10); // cast to int
  const char* gpa = input("Enter the student's GPA: ");
  float gpa1 = strtof(gpa, &pEnd); // cast to float
  float gpa2 = round(100 * gpa1) / 100; // round to 2 decimal points
  Student student;
  student.name1 = name1; // first name
  student.name2 = name2; // last name
  student.id = id1; // id
  student.gpa = gpa2; // gpa
  students.push_back(student); // finally, add this student to the vector
  return;
}

void print_students(){
  // print the students that are stored
  print("Student list:");
  for (Student student : students){
    cout << student.name1 << ' ' << student.name2 << ", ";
    cout << student.id << ", ";
    cout << student.gpa << "\n";
  }
  cout << flush;
  return;
}
  
int main(){
  print("Student List - 10/9/25");
  print("Welcome! Type 'HELP' for a list of commands.");
  bool running = 1;
  while (running){ // main loop
    const char* cmd = input("$ ");
    // command list starts here
    if (strcmp(cmd, "HELP") == 0){ // HELP
      print("HELP: print list of commands");
      print("QUIT: quit this program");
      print("ADD: add a student");
      print("PRINT: print all the students currently stored");
    }
    if (strcmp(cmd, "QUIT") == 0){ // QUIT
      running = 0; // program will stop after completing this loop
      print("Goodbye!");
    }
    if (strcmp(cmd, "ADD") == 0){ // ADD
      add_student();
    }
    if (strcmp(cmd, "PRINT") == 0){ // PRINT
      print_students();
    }
  }
  return 0;
}
