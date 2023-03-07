# cs303-assignment02

## Building
Run `make all` to build. `./main` to run the program.

## Interaction
A menu is given to the user as shown below:

![The program's prompt](/pictures/prompt.png)

Choose an option (either case works. Fill in prompts as requested.

## Data Structure
The `Single_Linked_List.h` is a single header that includes a fully functional templated singly linked list with the interaction functions as specified in the spec doc.
Every function runs in constant time other than `pop_back`, `find`, `insert`, and `delete`, which all run in linear time.

## Employee Classes
The employee classes follow all of the specs given. Nonprofessional employees' weekly pay is based off of hours worked, and so is their healthcare and vacation time. Professional employees' weekly pay is 1/52 of their salary, and their healthcare costs and vacation time are based on the amount of years at the company. Here is an example of this, bob is the professional and Joe is the nonprofessional:

![Employee example](/pictures/employee.png)

This is outputted at the beginning of main.

## Demo
Here is a screenshot of a short demo showing the functionality:

![First image of demo](/pictures/demo1.png)
![Demo continued](/pictures/demo2.png)
![Demo continued](/pictures/demo3.png)
