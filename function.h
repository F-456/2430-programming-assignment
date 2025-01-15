#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>


using namespace std;

ifstream file_in;
ofstream file_out;

class variable
{
private:
    int size;
    int record_number, individual_record_number = 0;
    vector<string> v1; // 10 vector as column to store data
    vector<string> v2;
    vector<string> v3;
    vector<string> v4;
    vector<string> v5;
    vector<string> v6;
    vector<string> v7;
    vector<string> v8;
    vector<string> v9;
    vector<string> v10;
    vector<string> header_key;

public:
    variable() : size(0) {}
    vector<vector<string>> records;
    string elements;
    string remove_non_alpha(string s)
    {

        int j;

        for (int i = 0; i < s.size(); i++)
        {
            // locate non alphabet character can remove it
            if ((s[i] >= 'A' && s[i] <= 'Z') || // loop to check if the character ASCII number is somewhere between A -> Z
                (s[i] >= 'a' && s[i] <= 'z'))   // '||' is use to return true if only the both statement is true
            {
                s[j] = s[i];
                j++;
            }
        }
        //  return the non special character string by using the locater j
        return s.substr(0, j);
    }

    void open_file(string s)
    {
        stringstream ss(s);
        string word;
        string file_name;

        while (ss >> word)
        {
            if (word.find('CREATE') != string::npos) // skipping the 'create' letter for retrieving the file name behind of it
            {
            }
            else
            {
                file_name = word;
                cout << file_name << endl;
                file_in.open(file_name);
            }
        }
    }

    void create_database()
    {

        cout << "creating databases" << endl;
    }

    string create_table(string s)
    {

        stringstream ss(s);
        bool keyword_checked = false;
        string word;
        string table_name;

        while (ss >> word) // loop through every word of the command itself
        {

            if (word.find('CREATE') != string::npos) // ignore and passes create
            {
            }
            else if (word.find('TABLE') != string::npos) // ignore and  passes table
            {
            }
            else
            {
                keyword_checked = true;
            }

            if (keyword_checked == true)
            {
                table_name = word;
                cout << remove_non_alpha(table_name) << endl; // output the table name after removing unecessary symbol
                break;
            }
        }
        while (ss >> word)
        {
            if (word.find('INT') != string::npos)
            {
            }
            else if (word.find('TEXT') != string::npos)
            {
            }
            else
            {
                header_key.push_back(word); // adding all the key into the header vector
            }
        }

        for (string i : header_key) // checking the header vector
        {

            // cout << i << " ";
        }

        return table_name;
    }

    void insert_record(string s, string table_name)
    {

        string word;
        stringstream ss(s);
        int sequence = 0;

        while (ss >> word)
        {
            if (word.find('INSERT') != string::npos || word.find('INTO') != string::npos) // passes insert or into
            {
            }

            else if (word.find('VALUES') != string::npos) // passes values

            {
            }

            else if (word.find(table_name) != string::npos) // passes table name
            {
            }
            else
            {
                // removing unwanted parenthesis in both side of the string
                elements = word.substr(1, word.size() - 2);
                // cout << elements << endl;
                // file_out << elements << endl;

                vector<string> record;
                string temp;
                istringstream stream(elements);

                while (getline(stream, temp, ',')) // while loop to form a usable vector which include all the data
                {
                    // Remove the single quotes
                    if (temp.front() == '\'')
                    {
                        temp = temp.substr(1, temp.size() - 2);
                    }
                    record.push_back(temp);
                }

                size = record.size(); // size of how many keys

                for (int i = 0; i < size; i++) // loop through all the data vector and insert the data into them
                {
                    if (i == 0) // insert into first column
                    {
                        v1.push_back(record[0]);
                    }
                    else if (i == 1) // insert into second column
                    {
                        v2.push_back(record[1]);
                    }
                    else if (i == 2)
                    {
                        v3.push_back(record[2]);
                    }
                    else if (i == 3)
                    {
                        v4.push_back(record[3]);
                    }
                    else if (i == 4)
                    {
                        v5.push_back(record[4]);
                    }
                    else if (i == 5)
                    {
                        v6.push_back(record[5]);
                    }
                    else if (i == 6)
                    {
                        v7.push_back(record[6]);
                    }
                    else if (i == 7)
                    {
                        v8.push_back(record[7]);
                    }
                    else if (i == 8)
                    {
                        v9.push_back(record[8]);
                    }
                    else if (i == 9)
                    {
                        v10.push_back(record[9]);
                    }
                    individual_record_number++;
                }
            }
        }
    }

    void select(string s)
    {
        file_out.open("fileOutput3.txt", fstream::app); // writting in append mode to prevent overwritting file

        record_number = individual_record_number / size; // deviding record number with size to get the precise number of
        // how many record is inserted (important)
        string word;
        stringstream ss(s);

        // cout << "There are " << record_number << "record" << endl;
        // cout << "size are " << size << endl;
        while (ss >> word)
        {
            if (word.find('*') != string::npos)
            {
                for (int y = 0; y < size; y++)
                {
                    cout << header_key[y] << ',';
                    file_out << header_key[y] << ',';
                }
                cout << endl;
                file_out << endl;

                for (int i = 0; i < record_number; i++) // nested loop to cout two dimensional vector at once
                {
                    for (int x = 0; x < size; x++)
                    {
                        if (x == 0) // cout the first column
                        {
                            cout << v1[i] << ",";
                            file_out << v1[i] << ',';
                        }
                        else if (x == 1) // cout the second column
                        {
                            cout << v2[i] << ",";
                            file_out << v2[i] << ',';
                        }
                        else if (x == 2)
                        {
                            cout << v3[i] << ",";
                            file_out << v3[i] << ',';
                        }
                        else if (x == 3)
                        {
                            cout << v4[i] << ",";
                            file_out << v4[i] << ',';
                        }
                        else if (x == 4)
                        {
                            cout << v5[i] << ",";
                            file_out << v5[i] << ',';
                        }
                        else if (x == 5)
                        {
                            cout << v6[i] << ",";
                            file_out << v6[i] << ',';
                        }
                        else if (x == 6)
                        {
                            cout << v7[i] << ",";
                            file_out << v7[i] << ',';
                        }
                        else if (x == 7)
                        {
                            cout << v8[i] << ",";
                            file_out << v8[i] << ',';
                        }
                        else if (x == 8)
                        {
                            cout << v9[i] << ",";
                            file_out << v9[i] << ',';
                        }
                        else if (x == 9)
                        {
                            cout << v10[i] << ",";
                            file_out << v10[i] << ',';
                        }
                    }
                    cout << endl;
                    file_out << endl;
                }
            }
        }
    }

    void select_count()
    {
        file_out.open("fileOutput3.txt", fstream::app);         // Open file in append mode to prevent overwriting
        cout << "Total records: " << record_number << endl;     // Directly print record_number
        file_out << "Total records: " << record_number << endl; // Write it to the output file
        file_out.close();
    }

    void select_where(const string &command)
    {
        file_out.open("fileOutput3.txt", fstream::app); // Open file in append mode

        string column_name, condition_value;
        int column_index = -1;

        // Parse the command to extract the column name and condition value
        size_t where_pos = command.find("WHERE");
        if (where_pos != string::npos)
        {
            size_t equals_pos = command.find("=", where_pos);
            if (equals_pos != string::npos)
            {
                // Extract column name
                column_name = command.substr(where_pos + 6, equals_pos - where_pos - 6);
                column_name.erase(column_name.find_last_not_of(" ") + 1); // Trim trailing spaces

                // Extract condition value
                condition_value = command.substr(equals_pos + 1);
                condition_value.erase(0, condition_value.find_first_not_of(" ")); // Trim leading spaces
                condition_value.erase(condition_value.find_last_not_of(" ") + 1); // Trim trailing spaces

                // Remove quotes from condition value if present
                if (condition_value.front() == '\'' && condition_value.back() == '\'')
                {
                    condition_value = condition_value.substr(1, condition_value.size() - 2);
                }
            }
        }

        // Find the column index for the given column name
        for (int i = 0; i < header_key.size(); i++)
        {
            if (header_key[i] == column_name)
            {
                column_index = i;
                break;
            }
        }

        if (column_index == -1)
        {
            cout << "Column not found: " << column_name << endl;
            file_out << "Column not found: " << column_name << endl;
            file_out.close();
            return;
        }

        // Print the header
        for (int y = 0; y < size; y++)
        {
            cout << header_key[y] << ',';
            file_out << header_key[y] << ',';
        }
        cout << endl;
        file_out << endl;

        bool match_found = false; // Track if any row matches the condition

        // Filter and print rows matching the condition
        for (int i = 0; i < record_number; i++)
        {
            string current_value;

            // Get the value from the appropriate column
            if (column_index == 0)
                current_value = v1[i];
            else if (column_index == 1)
                current_value = v2[i];
            else if (column_index == 2)
                current_value = v3[i];
            else if (column_index == 3)
                current_value = v4[i];
            else if (column_index == 4)
                current_value = v5[i];
            else if (column_index == 5)
                current_value = v6[i];
            else if (column_index == 6)
                current_value = v7[i];
            else if (column_index == 7)
                current_value = v8[i];
            else if (column_index == 8)
                current_value = v9[i];
            else if (column_index == 9)
                current_value = v10[i];

            // Debug output
            // cout << "Comparing: current_value = '" << current_value << "' with condition_value = '" << condition_value << "'" << endl;

            if (current_value == condition_value) // Check the condition
            {
                match_found = true; // A match was found
                for (int x = 0; x < size; x++)
                {
                    if (x == 0)
                        cout << v1[i] << ",", file_out << v1[i] << ',';
                    else if (x == 1)
                        cout << v2[i] << ",", file_out << v2[i] << ',';
                    else if (x == 2)
                        cout << v3[i] << ",", file_out << v3[i] << ',';
                    else if (x == 3)
                        cout << v4[i] << ",", file_out << v4[i] << ',';
                    else if (x == 4)
                        cout << v5[i] << ",", file_out << v5[i] << ',';
                    else if (x == 5)
                        cout << v6[i] << ",", file_out << v6[i] << ',';
                    else if (x == 6)
                        cout << v7[i] << ",", file_out << v7[i] << ',';
                    else if (x == 7)
                        cout << v8[i] << ",", file_out << v8[i] << ',';
                    else if (x == 8)
                        cout << v9[i] << ",", file_out << v9[i] << ',';
                    else if (x == 9)
                        cout << v10[i] << ",", file_out << v10[i] << ',';
                }
                cout << endl;
                file_out << endl;
            }
        }
        if (!match_found)
        {
            cout << "No matching records found for " << column_name << " = " << condition_value << endl;
            file_out << "No matching records found for " << column_name << " = " << condition_value << endl;
        }

        file_out.close();
    }

}; // don't delete this line