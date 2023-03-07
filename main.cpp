#include "Single_Linked_List.h"
#include "ProfessionalEmployee.h"
#include "NonprofessionalEmployee.h"
#include <iostream>
using namespace std;

int main() {
  ProfessionalEmployee bob("bob", 70000);
  cout << "Bob salary: " << bob.calculate_weekly_salary() << endl;
  cout << "Bob healthcare: " << bob.calculate_health_care() << endl;
  cout << "Bob vacation: " << bob.calculate_vacation_days() << endl;

  NonprofessionalEmployee joe("joe", 34);
  cout << "Joe salary: " << joe.calculate_weekly_salary() << endl;
  cout << "Joe healthcare: " << joe.calculate_health_care() << endl;
  cout << "Joe vacation: " << joe.calculate_vacation_days() << endl;
  cout << endl;

  Single_Linked_List<int> list;

  char option;
  int value, index;
  bool successful;
  
  // Loop until the user wants to quit
  do {
    // Prompt the user and save that value
    cout << "(F) push to the front" << endl;
    cout << "(B) push to the back" << endl;
    cout << "(P) pop from the front" << endl;
    cout << "(p) pop from the back" << endl;
    cout << "(f) show the front" << endl;
    cout << "(b) show the back" << endl;
    cout << "(e) is the list empty" << endl;
    cout << "(i) insert at an index" << endl;
    cout << "(r) remove from an index" << endl;
    cout << "(s) search for the index of an item" << endl;
    cout << "(Q) quit" << endl;
    cout << "Enter your choice: ";
    cin >> option;

    cout << endl;

    // Decide what to do based on the inputted option
    switch(option) {
    case 's':
      // Prompt the user for a value to search
      cout << "\tEnter a value to search for: ";
      cin >> value;

      // Search the array, saving the value to `index`
      index = list.find(value);

      // Output either the index, or that the value could not be found
      cout << "\t";
      if (index == -1) {
	cout << value << " could not be found." << endl;
      } else {
	cout << value << " was first found at index " << index << endl;
      }
      
      break;
    case 'B':
      // Prompt the user for a value to append
      cout << "\tEnter a value to add to the end of the array: ";
      cin >> value;

      // Append the value
      list.push_back(value);
      
      break;
    case 'F':
      // Prompt the user for a value to prepend
      cout << "\tEnter a value to add to the front of the array: ";
      cin >> value;

      // Append the value
      list.push_front(value);
      
      break;
    case 'b':
      // Output the value at the end
      if (list.empty()) {
	cout << "\tThe list is empty" << endl;
      } else {
	cout << "\tThe value at the end is: " << list.back() << endl;
      }
      break;
    case 'f':
      // Output the value at the front
      if (list.empty()) {
	cout << "\tThe list is empty" << endl;
      } else {
	cout << "\tThe value at the front is: " << list.front() << endl;
      }
      break;
    case 'P':
      // Pop from the front
      if (list.empty()) {
	cout << "\tUnable to pop from an empty list!" << endl;
      } else {
	cout << "\tThe popped value was: " << list.pop_front() << endl;
      }
      break;
    case 'p':
      // Pop from the back
      if (list.empty()) {
	cout << "\tUnable to pop from an empty list!" << endl;
      } else {
	cout << "\tThe popped value was: " << list.pop_back() << endl;
      }
      break;
    case 'r':
      // Prompt the user for an index to delete
      cout << "\tEnter index to delete: ";

      // Try to delete the index, and output whether or not it was successful
      cin >> index;
      successful = list.remove(index);
      if (successful)
	cout << "\t" << index << " was successfully deleted" << endl;
      else
	cout << "\tInvalid index" << endl;
      break;
    case 'i':
      // Prompt the user for an index to delete
      cout << "\tEnter index to insert at: ";

      // Try to delete the index, and output whether or not it was successful
      cin >> index;
      cout << "\tEnter an value to insert:";
      cin >> value;
      
      list.insert(index, value);
      cout << "\tItem inserted" << endl;
      break;
    case 'e':
      // Test if list is empty
      if (list.empty())
	cout << "\tThe list is empty" << endl;
      else
	cout << "\tThe list is not empty" << endl;
      break;
    case 'Q':
      // End the loop
      break;
    default:
      // Output invalid option
      cout << "Invalid option; please enter a valid option." << endl;
      break;
    }
    cout << endl;
  } while (option != 'Q');
}
