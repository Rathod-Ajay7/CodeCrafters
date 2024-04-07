#include <iostream>
#include <fstream> //for file handling
// https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
#include <vector>
#include <sstream>
#include <algorithm> //for data sorting
#include <cstdio>    //for delete file

using namespace std;

// structure for store student data
struct Student
{
    int srNo;
    string name;
    string interviewDate;
    string interviewStatus;
    string interviewStartTime;
    string interviewEndTime;
    string studentId;
    string email;
    string program;
    string contactNo;
    string whatsappNo;
    string alternateNo;
    string skypeId;
};

// For read student data from a CSV file
vector<Student> readStudentData(const string &filename)
{
    vector<Student> students;
    ifstream file(filename);
    string line;

    // for Skip the first line
    getline(file, line);

    // for Read each line of the file
    while (getline(file, line))
    {
        istringstream data(line); // https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
        Student student;
        char comma;

        // forRead data from CSV line into student structure
        data >> student.srNo >> comma;
        getline(data, student.name, ',');
        getline(data, student.interviewDate, ',');
        getline(data, student.interviewStatus, ',');
        getline(data, student.interviewStartTime, ',');
        getline(data, student.interviewEndTime, ',');
        getline(data, student.studentId, ',');
        getline(data, student.email, ',');
        getline(data, student.program, ',');
        getline(data, student.contactNo, ',');
        getline(data, student.whatsappNo, ',');
        getline(data, student.alternateNo, ',');
        getline(data, student.skypeId);

        students.push_back(student);
    }

    return students;
}

int nuberofstudent[5] = {0}; // for store number of students in each round in array
int x = 0;

// Function of writing student data into a CSV file
void writeStudentData(const string &filename, const vector<Student> &students)
{
    ofstream file(filename);
    int count = 0;
    file << "Sr. No.,Name,Interview Date,Interview Status,Interview Start Time,Interview End Time,Student ID,Email,Program,Contact No.,WhatsApp No.,Alternate No.,Skype ID," << endl;
    for (const auto &student : students) // https://stackoverflow.com/questions/22225148/what-does-for-const-auto-s-strs-mean
    {
        file << student.srNo << "," << student.name << "," << student.interviewDate << "," << student.interviewStatus << "," << student.interviewStartTime << ","
             << student.interviewEndTime << "," << student.studentId << "," << student.email << "," << student.program << "," << student.contactNo << ","
             << student.whatsappNo << "," << student.alternateNo << "," << student.skypeId << endl;
        count++;
    }
    nuberofstudent[x] = count;
    x++;
}

//  compare  by name for sorting
bool compareStudentsByName(const Student &a, const Student &b)
{
    return a.name < b.name;
}

//  compare  by program for sorting
bool compareStudentsByProgram(const Student &a, const Student &b)
{
    return a.program < b.program;
}

//  compare  by student ID for sorting
bool compareStudentsByStudentId(const Student &a, const Student &b)
{
    return a.studentId < b.studentId;
}

// structure for store user login detail
struct User
{
    string username;
    string password;
};

// Authentication based on username and password
bool authenticateUser(const string &username, const string &password)
{
    vector<User> users = {{"placementcell00", "12345678"}, {"placementcell01", "12345678"}};

    // Check if the provided detial match or not
    for (const auto &user : users)
    {
        if (user.username == username && user.password == password)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Read data from each round of interview's CSV file into vectors
    vector<Student> round1 = readStudentData("round1.csv");
    vector<Student> round2 = readStudentData("round2.csv");
    vector<Student> round3 = readStudentData("round3.csv");
    vector<Student> hrRound = readStudentData("HRround.csv");
    vector<Student> finalSelects = readStudentData("finalselects.csv");

    // for get number of student in each round and maintaing last sr.no for insert student detail
    // https://www.geeksforgeeks.org/csv-file-management-using-c/
    writeStudentData("a1.csv", round1);
    writeStudentData("a2.csv", round2);
    writeStudentData("a3.csv", round3);
    writeStudentData("a4.csv", hrRound);
    writeStudentData("a5.csv", finalSelects);
    remove("a1.csv");
    remove("a2.csv");
    remove("a3.csv");
    remove("a4.csv");
    remove("a5.csv");

    int choice;
    string input;
    Student studentDetails;
    Student newStudent;
    string deleteNameOrId;
    int roundsFound = 0;
    int same_name_found = 0;
    string username, password;

    do
    {
        cout << endl
             << endl;
        cout << "Welcome to our project!" << endl;
        cout << "                         P2. DA-IICT Placement Manager:                     " << endl;
        cout << " Please choose an option:  " << endl;
        cout << "1. Sort data by name               " << endl;
        cout << "2. Sort data by program            " << endl;
        cout << "3. Sort data by student ID         " << endl;
        cout << "4. Search for a student            " << endl;
        cout << "5. Insert a new student in a round " << endl;
        cout << "6. Delete a student from a round   " << endl;
        cout << "0. Exit                            " << endl;
        cout << "Enter your choice:                 " << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
            // sort by name
            // https://www.geeksforgeeks.org/sort-c-stl/
            sort(round1.begin(), round1.end(), compareStudentsByName);
            sort(round2.begin(), round2.end(), compareStudentsByName);
            sort(round3.begin(), round3.end(), compareStudentsByName);
            sort(hrRound.begin(), hrRound.end(), compareStudentsByName);
            sort(finalSelects.begin(), finalSelects.end(), compareStudentsByName);
            writeStudentData("short_by_name_round1.csv", round1);
            writeStudentData("short_by_name_round2.csv", round2);
            writeStudentData("short_by_name_round3.csv", round3);
            writeStudentData("short_by_name_hrRound.csv", hrRound);
            writeStudentData("short_by_name_finalSelects.csv", finalSelects);
            break;
        case 2:
            // sort by programe
            sort(round1.begin(), round1.end(), compareStudentsByProgram);
            sort(round2.begin(), round2.end(), compareStudentsByProgram);
            sort(round3.begin(), round3.end(), compareStudentsByProgram);
            sort(hrRound.begin(), hrRound.end(), compareStudentsByProgram);
            sort(finalSelects.begin(), finalSelects.end(), compareStudentsByProgram);
            writeStudentData("short_by_program_round1.csv", round1);
            writeStudentData("short_by_program_round2.csv", round2);
            writeStudentData("short_by_program_round3.csv", round3);
            writeStudentData("short_by_program_hrRound.csv", hrRound);
            writeStudentData("short_by_program_finalSelects.csv", finalSelects);
            break;
        case 3:
            // sort by student id
            sort(round1.begin(), round1.end(), compareStudentsByStudentId);
            sort(round2.begin(), round2.end(), compareStudentsByStudentId);
            sort(round3.begin(), round3.end(), compareStudentsByStudentId);
            sort(hrRound.begin(), hrRound.end(), compareStudentsByStudentId);
            sort(finalSelects.begin(), finalSelects.end(), compareStudentsByStudentId);
            writeStudentData("short_by_id_round1.csv", round1);
            writeStudentData("short_by_id_round2.csv", round2);
            writeStudentData("short_by_id_round3.csv", round3);
            writeStudentData("short_by_id_hrRound.csv", hrRound);
            writeStudentData("short_by_id_finalSelects.csv", finalSelects);
            break;

        case 4:
            // Searching for a student detail
            cout << "Enter student name or ID: ";
            cin.ignore(); // https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
            getline(cin, input);

            for (const auto &temp : round1)
            {

                if (temp.name == input)
                {
                    same_name_found++;
                }
            }

            if (same_name_found > 1)
            {
                cout << "Enter student ID: ";
                getline(cin, input);
            }

            // Search for the student in each round and count the rounds found

            // Search in Round 1
            for (const auto &student : round1)
            {
                if (student.name == input || student.studentId == input)
                {
                    studentDetails = student;
                    roundsFound++;

                    cout << "Student Name: " << studentDetails.name << endl;
                    cout << "Student ID: " << studentDetails.studentId << endl;
                    cout << "Program: " << studentDetails.program << endl
                         << endl;
                    cout << "Found in Round 1:" << endl;
                    cout << "Interview status:" << studentDetails.interviewStatus << endl;
                    cout << "Interview date:" << studentDetails.interviewDate << endl;
                    cout << "Interview start time :" << studentDetails.interviewStartTime << endl;
                    cout << "Interview end time :" << studentDetails.interviewEndTime << endl
                         << endl;
                }
            }

            // Search in Round 2
            for (const auto &student : round2)
            {
                if (student.name == input || student.studentId == input)
                {
                    studentDetails = student;
                    roundsFound++;
                    cout << "Found in Round 2:" << endl;

                    cout << "Interview status:" << studentDetails.interviewStatus << endl;
                    cout << "Interview date:" << studentDetails.interviewDate << endl;
                    cout << "Interview start time :" << studentDetails.interviewStartTime << endl;
                    cout << "Interview end time :" << studentDetails.interviewEndTime << endl
                         << endl;
                }
            }

            // Search in Round 3
            for (const auto &student : round3)
            {
                if (student.name == input || student.studentId == input)
                {
                    studentDetails = student;
                    roundsFound++;
                    cout << "Found in Round 3:" << endl;

                    cout << "Interview status:" << studentDetails.interviewStatus << endl;
                    cout << "Interview date:" << studentDetails.interviewDate << endl;
                    cout << "Interview start time :" << studentDetails.interviewStartTime << endl;
                    cout << "Interview end time :" << studentDetails.interviewEndTime << endl
                         << endl;
                }
            }

            // Search in HR Round
            for (const auto &student : hrRound)
            {
                if (student.name == input || student.studentId == input)
                {
                    studentDetails = student;
                    roundsFound++;
                    cout << "Found in HR Round:" << endl;

                    cout << "Interview status:" << studentDetails.interviewStatus << endl;
                    cout << "Interview date:" << studentDetails.interviewDate << endl;
                    cout << "Interview start time :" << studentDetails.interviewStartTime << endl;
                    cout << "Interview end time :" << studentDetails.interviewEndTime << endl
                         << endl;
                }
            }

            // Search in Final Selects
            for (const auto &student : finalSelects)
            {
                if (student.name == input || student.studentId == input)
                {
                    studentDetails = student;
                    roundsFound++;
                    cout << "Found in Final Selects:" << endl;

                    cout << "Interview status:" << studentDetails.interviewStatus << endl;
                    cout << "Interview date:" << studentDetails.interviewDate << endl;
                    cout << "Interview start time :" << studentDetails.interviewStartTime << endl;
                    cout << "Interview end time :" << studentDetails.interviewEndTime << endl
                         << endl;
                }
            }

            cout << "Total rounds found: " << roundsFound << endl;

            break;
        case 5:
        {

            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (authenticateUser(username, password))
            {

                cout << "Authentication successful. You can now insert student records." << endl;

                cout << "Enter details for the new student:" << endl;

                int roundChoice;
                cout << "Select the round to insert the student:" << endl;
                cout << "1. Round 1" << endl;
                cout << "2. Round 2" << endl;
                cout << "3. Round 3" << endl;
                cout << "4. HR Round" << endl;
                cout << "5. Final Selects" << endl;
                cout << "Enter your choice: ";
                cin >> roundChoice;

                switch (roundChoice)
                {
                case 1:
                    newStudent.srNo = nuberofstudent[0] + 1;
                    cout << "Name: ";
                    cin.ignore(); // Ignore newline character in the buffer
                    getline(cin, newStudent.name);
                    cout << "Interview Date: ";
                    getline(cin, newStudent.interviewDate);
                    cout << "Interview Status: ";
                    getline(cin, newStudent.interviewStatus);
                    cout << "Interview Start Time: ";
                    getline(cin, newStudent.interviewStartTime);
                    cout << "Interview End Time: ";
                    getline(cin, newStudent.interviewEndTime);
                    cout << "Student ID: ";
                    getline(cin, newStudent.studentId);
                    cout << "Email: ";
                    getline(cin, newStudent.email);
                    cout << "Program: ";
                    getline(cin, newStudent.program);
                    cout << "Contact No.: ";
                    getline(cin, newStudent.contactNo);
                    cout << "Whatsapp No.: ";
                    getline(cin, newStudent.whatsappNo);
                    cout << "Alternate No.: ";
                    getline(cin, newStudent.alternateNo);
                    cout << "Skype ID: ";
                    getline(cin, newStudent.skypeId);
                    round1.push_back(newStudent);
                    break;
                case 2:
                    newStudent.srNo = nuberofstudent[1] + 1;
                    cout << "Name: ";
                    cin.ignore(); // Ignore newline character in the buffer
                    getline(cin, newStudent.name);
                    cout << "Interview Date: ";
                    getline(cin, newStudent.interviewDate);
                    cout << "Interview Status: ";
                    getline(cin, newStudent.interviewStatus);
                    cout << "Interview Start Time: ";
                    getline(cin, newStudent.interviewStartTime);
                    cout << "Interview End Time: ";
                    getline(cin, newStudent.interviewEndTime);
                    cout << "Student ID: ";
                    getline(cin, newStudent.studentId);
                    cout << "Email: ";
                    getline(cin, newStudent.email);
                    cout << "Program: ";
                    getline(cin, newStudent.program);
                    cout << "Contact No.: ";
                    getline(cin, newStudent.contactNo);
                    cout << "Whatsapp No.: ";
                    getline(cin, newStudent.whatsappNo);
                    cout << "Alternate No.: ";
                    getline(cin, newStudent.alternateNo);
                    cout << "Skype ID: ";
                    getline(cin, newStudent.skypeId);
                    round2.push_back(newStudent);
                    break;
                case 3:
                    newStudent.srNo = nuberofstudent[2] + 1;
                    cout << "Name: ";
                    cin.ignore(); // Ignore newline character in the buffer
                    getline(cin, newStudent.name);
                    cout << "Interview Date: ";
                    getline(cin, newStudent.interviewDate);
                    cout << "Interview Status: ";
                    getline(cin, newStudent.interviewStatus);
                    cout << "Interview Start Time: ";
                    getline(cin, newStudent.interviewStartTime);
                    cout << "Interview End Time: ";
                    getline(cin, newStudent.interviewEndTime);
                    cout << "Student ID: ";
                    getline(cin, newStudent.studentId);
                    cout << "Email: ";
                    getline(cin, newStudent.email);
                    cout << "Program: ";
                    getline(cin, newStudent.program);
                    cout << "Contact No.: ";
                    getline(cin, newStudent.contactNo);
                    cout << "Whatsapp No.: ";
                    getline(cin, newStudent.whatsappNo);
                    cout << "Alternate No.: ";
                    getline(cin, newStudent.alternateNo);
                    cout << "Skype ID: ";
                    getline(cin, newStudent.skypeId);
                    round3.push_back(newStudent);
                    break;
                case 4:
                    newStudent.srNo = nuberofstudent[3] + 1;
                    cout << "Name: ";
                    cin.ignore(); // Ignore newline character in the buffer
                    getline(cin, newStudent.name);
                    cout << "Interview Date: ";
                    getline(cin, newStudent.interviewDate);
                    cout << "Interview Status: ";
                    getline(cin, newStudent.interviewStatus);
                    cout << "Interview Start Time: ";
                    getline(cin, newStudent.interviewStartTime);
                    cout << "Interview End Time: ";
                    getline(cin, newStudent.interviewEndTime);
                    cout << "Student ID: ";
                    getline(cin, newStudent.studentId);
                    cout << "Email: ";
                    getline(cin, newStudent.email);
                    cout << "Program: ";
                    getline(cin, newStudent.program);
                    cout << "Contact No.: ";
                    getline(cin, newStudent.contactNo);
                    cout << "Whatsapp No.: ";
                    getline(cin, newStudent.whatsappNo);
                    cout << "Alternate No.: ";
                    getline(cin, newStudent.alternateNo);
                    cout << "Skype ID: ";
                    getline(cin, newStudent.skypeId);
                    hrRound.push_back(newStudent);
                    break;
                case 5:
                    newStudent.srNo = nuberofstudent[4] + 1;
                    cout << "Name: ";
                    cin.ignore(); // Ignore newline character in the buffer
                    getline(cin, newStudent.name);
                    cout << "Interview Date: ";
                    getline(cin, newStudent.interviewDate);
                    cout << "Interview Status: ";
                    getline(cin, newStudent.interviewStatus);
                    cout << "Interview Start Time: ";
                    getline(cin, newStudent.interviewStartTime);
                    cout << "Interview End Time: ";
                    getline(cin, newStudent.interviewEndTime);
                    cout << "Student ID: ";
                    getline(cin, newStudent.studentId);
                    cout << "Email: ";
                    getline(cin, newStudent.email);
                    cout << "Program: ";
                    getline(cin, newStudent.program);
                    cout << "Contact No.: ";
                    getline(cin, newStudent.contactNo);
                    cout << "Whatsapp No.: ";
                    getline(cin, newStudent.whatsappNo);
                    cout << "Alternate No.: ";
                    getline(cin, newStudent.alternateNo);
                    cout << "Skype ID: ";
                    getline(cin, newStudent.skypeId);
                    finalSelects.push_back(newStudent);
                    break;
                default:
                    cout << "Invalid round choice. No student added." << endl;
                    break;
                }

                writeStudentData("round1.csv", round1);
                writeStudentData("round2.csv", round2);
                writeStudentData("round3.csv", round3);
                writeStudentData("HRround.csv", hrRound);
                writeStudentData("finalselects.csv", finalSelects);

                cout << "New student added successfully." << endl;
            }
            else
            {

                cout << "Authentication failed. Invalid username or password." << endl;
            }
            break;
        }

        case 6:
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter the name or ID of the student to delete: ";
            if (authenticateUser(username, password))
            {

                cout << "Authentication successful. You can now delete student records." << endl;

                cin.ignore(); // Ignore newline character in the buffer
                getline(cin, deleteNameOrId);

                // Search and remove the student from each round
                // https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-and-when-should-i-use-one
                // https://youtu.be/OQ_lR9y0eqI
                auto removeStudentFromRound = [&](vector<Student> &round)
                {
                    auto it = remove_if(round.begin(), round.end(), [&](const Student &student)
                                        { return student.name == deleteNameOrId || student.studentId == deleteNameOrId; });
                    if (it != round.end())
                    {
                        round.erase(it, round.end());
                        return true;
                    }
                    return false;
                };

                bool studentRemoved = false;
                studentRemoved |= removeStudentFromRound(round1);
                studentRemoved |= removeStudentFromRound(round2);
                studentRemoved |= removeStudentFromRound(round3);
                studentRemoved |= removeStudentFromRound(hrRound);
                studentRemoved |= removeStudentFromRound(finalSelects);

                if (studentRemoved)
                {

                    writeStudentData("round1.csv", round1);
                    writeStudentData("round2.csv", round2);
                    writeStudentData("round3.csv", round3);
                    writeStudentData("HRround.csv", hrRound);
                    writeStudentData("finalselects.csv", finalSelects);
                    cout << "Student deleted successfully." << endl;
                }
                else
                {
                    cout << "Student not found." << endl;
                }
            }
            else
            {
                cout << "Authentication failed. Invalid username or password." << endl;
            }
            break;
        }

        default:
            cout << "you are successfully exited." << endl;
            break;
        }
    } while (choice != 0);

    if (choice == 0)
    {
        cout << "total number of student which appear in interview : " << nuberofstudent[0] << endl;
        cout << "total number of student for selected for round 2  : " << nuberofstudent[1] << endl;
        cout << "total number of student for selected for round 3  : " << nuberofstudent[2] << endl;
        cout << "total number of student for selected for HR round : " << nuberofstudent[3] << endl;
        cout << "total number of student selected for company      : " << nuberofstudent[4] << endl;

        cout << endl;
        int percentage = (nuberofstudent[4] * 100) / nuberofstudent[0];
        if (percentage < 1)
        {

            cout << "Placement in this company poses greater challenges." << endl;
        }
        else if (percentage <= 5 && percentage >= 1)
        {

            cout << "Placement in this company is average." << endl;
        }
        else if (percentage > 5)
        {

            cout << "Placement in this company is more accessible." << endl;
        }
    }

    return 0;
}
