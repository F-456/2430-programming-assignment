// *********************************************************
// Program: TC3L_G06_main.cpp
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC3L
// Tutorial Class: TT5L
// Trimester: 2430
// Member_1: ID | TIEW FU SIANG | TIEW.FU.SIANG@student.mmu.edu.my |010-3706933
// Member_2: ID | NAME | EMAIL | PHONE
// Member_3: ID | NAME | EMAIL | PHONE
// Member_4: ID | NAME | EMAIL | PHONE
// *********************************************************
// Task Distribution
// Member_1:
// Member_2:
// Member_3:
// Member_4:
// *********************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "function.h"

using namespace std;

int main()
{
    variable Variables;
    ifstream file_in;
    ofstream file_out;
    string o1, o2, o3, o4, o5, o6, o7, o8, o9, o10;

    file_in.open("fileInput1.mdb");
    file_out.open("fileOutput1.txt");
    // open the input file

    if (!file_in.is_open())
    {
        cerr << "The file cannot be opened ,please check the file name \n";
        // return error if the file name is incorrect
        return 1;
    }
    string command;
    string id;
    string file_name; // initialize file name
    string table_name;

    vector<string> headers = {"customer_id", "customer_name", "customer_city", "customer_state", "customer_country", "customer_phone", "customer_email"};
    vector<vector<string>> records;

    while (getline(file_in, command, ';')) // loop through command to find keyword
    {
        stringstream iss(command);

        cout << command << endl;
        file_out << command << endl;

        if (command.find("CREATE") != string::npos) // npo = no position no keyword is found in the string
                                                    // to make checking the keyword possible
        {
            if (command.find("TABLE") != string::npos)
            {

                table_name = Variables.create_table(command);
            }
            else
            {

                Variables.open_file(command); // passing command to process in the function
                // creating file for output
            }
        }

        else if (command.find("INSERT INTO") != string::npos) // inserting data
        {

            Variables.insert_record(command, table_name); // passing command and table name to insert the data
            file_out << Variables.elements << endl;
        }
        else if (command.find("SELECT") != string::npos)
        {
            Variables.select_record(command, table_name, headers, records);
        }
    }

        file_in.close();
    return 0;
}
