// *********************************************************
// Program: TC3L_G06_main.cpp
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC3L
// Tutorial Class: TT5L
// Trimester: 2430
// Member_1: 242UC244DD | TIEW FU SIANG | TIEW.FU.SIANG@student.mmu.edu.my |010-3706933
// Member_2: 242UC244PP | Nicholas Beh Zhi Yang | NICHOLAS.BEH.ZHI@student.mmu.edu.my | 011-65215166
// Member_3: 242UC24551 | LOW ZHENG HAO | LOW.ZHENG.HAO@student.mmu.edu.my | 013-8888444
// Member_4: ID | NAME | EMAIL | PHONE
// *********************************************************
// Task Distribution
// Member_1:
// Member_2:
// Member_3: Update
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

    file_in.open("fileInput2.mdb");
    file_out.open("fileOutput2.txt", ios::out);
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
    }

    file_in.clear();  // Clear any EOF or fail flags
    file_in.seekg(0); // set the reading process to the start of the file

    while (getline(file_in, command, ';')) // second get line
                                           // to prevent segmentation error because of incomplete process
    {
        stringstream iss(command);

        // Log the command to both terminal and file
        cout << command << endl;
        file_out << command << endl;

        if (command.find("SELECT") != string::npos)
        {
            // Handle SELECT COUNT(*) command
            if (command.find(" * ") != string::npos)
            {
                Variables.select(command);
            }

            else if (command.find("COUNT(*)") != string::npos)
            {
                Variables.select_count();
            }
            else if (command.find("all") != string::npos)
            {
                if (command.find("WHERE") != string::npos)
                {
                    Variables.select_where(command);
                }
            }
        }
        if (command.find("UPDATE") != string::npos)
        {
            Variables.update(command);
        }
    }

    file_in.close();
    return 0;
}
