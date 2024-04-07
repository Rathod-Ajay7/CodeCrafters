# CodeCrafters

# PLACEMENT MANAGER SYSTEM


## DESCRIPTION
This project is a PLACEMENT MANAGER SYSTEM designed to manage a student data for interview rounds and selections. it allows users to sort data,search for students,insert new student records,and delete stuent records.
## Group Members
- **Ajay Rathod**:  202301221
- **Gaurav Patel**: 202301197
- **Mukund Patel**: 202301234
- **Vraj Makwana**: 202301436
 
## Features
- Sort data by name, program, or student ID.
- Search for a student by name or ID.
- **Authentication system for secure access.**
- Insert a new student record into a specific round.
- Delete a student record from any round.
- Track the number of students appearing in each round and selected for further rounds.
## Function List
- **vector<Student> readStudentData(const string &filename)**:
  This function is used to read csv file and store the data from   file in vector and return it.
- **void writeStudentData(const string &filename, const vector<Student> &students)**:
  This function write data in csv file.
- **bool compareStudentsByName(const Student &a, const Student &b)**:This is used to compare name of the student and sort it.
- **bool compareStudentsByProgram(const Student &a, const Student &b)**:This is used to sort the data using the Program.
- **bool compareStudentsByStudentId(const Student &a, const Student &b)**:This is used to sort data using Student ID.
- **bool authenticateUser(const string &username, const string &password)**:This function take username and password from user to check the authentication of user and if authentication is correct than we can add or delete data of student.For authentication to be successful, the username must be either "placementcell00" or "placementcell01", and the password must be "12345678".
## File Structure
- **main.cpp**: Contains the main C++ code for the Placement Manager System.
- **round1.csv, round2.csv, round3.csv, HRround.csv, finalselects.csv**: CSV files containing student data for each round of interview.
- **a1.csv, a2.csv, a3.csv, a4.csv, a5.csv**: Temporary CSV files for storing sorted student data.
- **short_by_name_round1.csv, short_by_name_round2.csv, short_by_name_round3.csv, short_by_name_hrRound.csv, short_by_name_finalSelects.csv**: CSV files containing student data sorted by name.
- **short_by_program_round1.csv, short_by_program_round2.csv, short_by_program_round3.csv, short_by_program_hrRound.csv, short_by_program_finalSelects.csv**: CSV files containing student data sorted by program.
- **short_by_id_round1.csv, short_by_id_round2.csv, short_by_id_round3.csv, short_by_id_hrRound.csv, short_by_id_finalSelects.csv**: CSV files containing student data sorted by student ID.

## Usage
1. Compile the `main.cpp` file using a C++ compiler.
2. Run the compiled executable.
3. Choose an option from the menu to perform specific tasks such as sorting data, searching for students, inserting new student records, or deleting student records.
## NOTE

As our group members don't have proper device. So we have upload our whole code from one of our group member whose id is 202301221@daiict.ac.in.
