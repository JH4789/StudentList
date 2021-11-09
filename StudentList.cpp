/*
Name: Jayden Huang
Date: 11/9/2021
Functionality: Creates editable database of students with characteristics
*/
//Setup
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;
//Struct definition
struct studentinfo {
  int studentid;
  char firstname[20];
  char lastname[20];
  float gpa; 
};
//Function prototyping
void addStudent(vector <studentinfo*> &v);
void printStudent(vector <studentinfo*> &v);
void delStudent(vector <studentinfo*> &v);
int main() {
  //Variable setup
  char commandinput[7];
  bool running = true;
  vector<studentinfo*> v;
  while(running == true) {
    cout << "Enter ADD to add a student, enter PRINT to print all current students, enter DELETE to delete a student, and enter QUIT to quit the program" << endl;
    cin >> commandinput;
    //Getting inputs 
    if(strcmp(commandinput, "ADD") == 0){
      addStudent(v);
    }
    else if(strcmp(commandinput, "PRINT") == 0) {
      printStudent(v);
    }
    else if(strcmp(commandinput, "DELETE") == 0){
      delStudent(v);
    }
    else if(strcmp(commandinput, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid input";
    }
  }
}
void addStudent(vector <studentinfo*> &v) {
  //Make new struct in vector and add values to it
  studentinfo* newstudent = new studentinfo();
  cout << "What is the first name of your student" << endl;
  cin >> newstudent -> firstname;
  cout << "What is the last name of your student" << endl;
  cin >> newstudent -> lastname;
  cout << "What is the student id of your student?" <<endl;
  cin >> newstudent->studentid;
  cout << "What is the GPA of your student" << endl;
  cin >> newstudent->gpa;
  //Makes space for the new struct
  v.push_back(newstudent);
}
void printStudent(vector <studentinfo*> &v) {
  vector<studentinfo*>::iterator ptr;
  //Goes through the struct and prints out the elements
  for(ptr = v.begin(); ptr < v.end() ; ptr++) {
    cout << (*ptr) -> firstname << " ";
    cout << (*ptr) -> lastname << ", ";
    cout << (*ptr) -> studentid << ", ";
    //Set precision code taken from https://stackoverflow.com/questions/14369673/round-double-to-3-points-decimal
    cout << setprecision(3) << (*ptr) -> gpa << endl;
  }
}
void delStudent(vector <studentinfo*> &v) {
  int findnumber;
  cout << "Enter the student ID of the student you want to delete" << endl;
  cin >> findnumber;
  //Reads in an int and then goes through the vector again to find matching values to delete
  vector<studentinfo*>::iterator ptr1;
  for(ptr1 = v.begin(); ptr1 < v.end() ; ptr1++) {
    if((*ptr1)->studentid == findnumber) {
       v.erase(ptr1);
    }
  }
}




