#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <set>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

ifstream file_in;
ofstream file_out;
string o1, o2, o3, o4, o5, o6, o7, o8, o9, o10;

class variable
{
private:
    int size;
    int record_number = 0;
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
                cout << remove_non_alpha(table_name) << " is created" << endl; // output the table name after removing unecessary symbol
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
                    record_number++;
                }
            }
        }
    }

    void select(string s)
    {
        file_out.open("fileOutput1.txt", fstream::app); // writting in append mode to prevent overwritting file

        record_number = record_number / size; // deviding record number with size to get the precise number of
        // how many record is inserted (important)
        string word;
        stringstream ss(s);

        cout << "There are " << record_number << "record" << endl;
        cout << "size are " << size << endl;
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

}; // don't delete this line
