CC = g++
CFLAGS = -g -Wall

TARGET = main

all: main

main: main.o Employee.o NonprofessionalEmployee.o ProfessionalEmployee.o
	$(CC) $(CFLAGS) -o main main.o Employee.o NonprofessionalEmployee.o ProfessionalEmployee.o

main.o: main.cpp Employee.h NonprofessionalEmployee.h ProfessionalEmployee.h Single_Linked_List.h
	$(CC) $(CFLAGS) -c main.cpp

Employee.o: Employee.h
	$(CC) $(CFLAGS) -c Employee.cpp

ProfessionalEmployee.o: Employee.h ProfessionalEmployee.h
	$(CC) $(CFLAGS) -c ProfessionalEmployee.cpp

NonprofessionalEmployee.o: Employee.h NonprofessionalEmployee.h
	$(CC) $(CFLAGS) -c NonprofessionalEmployee.cpp


clean:
	rm main.o Employee.o ProfessionalEmployee.o NonprofessionalEmployee.o
