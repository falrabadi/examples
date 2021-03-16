/**
 * @file    HW11.cc
 * @author  Akshobh Mirapurkar
 * @editor: Nathaniel Buchanan
 * @date    November 12, 2019
 *          Last edited: March 15, 2021
 * @university: Ohio University
 * @college: Russ College of Engineering
 * @brief   This program is an example of a three ballot
 *          system for voting. Known as Ballot Cryptograph
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    /// Declare an ifstream object
    std::ifstream instream;
    /// Open a text file with test names
    instream.open("HW10Test_test.txt");
    /// Used to read in Ballot keywords
    std::string temp;
    std::string name1;
    std::string name2;
    /// integers that to hold the counts
    int ballot_count = 0;
    int name1_count = 0;
    int name2_count = 0;
    bool is_valid = true;
    instream >> temp;

    /// Ignores the white spaces
    if(instream.peek() == '\n')
    {
        instream.ignore(100, '\n');
    }
    /// Go until the end of the file
    while(!instream.eof())
    {
        /// If the temp word is Ballot
        if(temp == "Ballot")
        {
            ballot_count++;
        }
        /// While loop that goes until 4
        while(ballot_count < 4)
        {
            /// Checks to see if it is valid or not
            is_valid = true;
            /// Ignores the white spaces
            if(instream.peek() == '\n')
            {
                instream.ignore(100, '\n');
            }
            char h;
            /// Get the vote number
            instream.get(h);
            instream >> temp;

            /// Function that removes the spaces
            remove_if(temp.begin(), temp.end(), isspace);

            /// Ignore the white spaces
            if(instream.peek() == '\n')
            {
                instream.ignore(100, '\n');
            }

            ///used for name1
            name1 = temp;
            name1_count += h;
            /// Empty the temp string
            temp = "";
            
            /// Ignore the white spaces
            if(instream.peek() == '\n')
            {
                instream.ignore(100, '\n');
            }

            /// Get the number of the vote with instream
            instream.get(h);
            instream >> temp;

            /// Function that removes the spaces
            remove_if(temp.begin(), temp.end(), isspace);

            /// Ignore the white spaces
            if(instream.peek() == '\n')
            {
                instream.ignore(100, '\n');
            }

            ///used for name2
            name2 = temp;
            name2_count += h;

            /// Ignore the white spaces
            if(instream.peek() == '\n')
            {
                instream.ignore(100, '\n');
            }

            instream >> temp;

            /// Ignore the white spaces
            if(instream.peek() == '\n')
            {
                instream.ignore(100, '\n');
            }

            /// Increment the total ballot count
            ballot_count++; 
        }
    /// Check #1
    /// Math that is using character value 
    /// If the name count is less than the equation below, this would mean
    /// that a specific row is not correctly filled out
    if(name1_count < '0' * 3 + 1 || name2_count < '0' * 3 + 1)
    {
        is_valid = false;
        std::cout << "Row not filled out" << std::endl;
    } 
    /// if a person votes for more than one candidate, it is not a valid ballot
    else if(name1_count > '1' * 3 - 1 || name2_count > '1' * 3 - 1)
    {
        is_valid = false;
        std::cout << "Too many votes for one candidate" << std::endl;
    } 
    /// if the counts are the same, then there is no winner
    else if(name1_count == name2_count)
    {
        is_valid = false;
        std::cout << "Preferred candidate unclear" << std::endl;
    }
    /// If name2 has a larger count, name2 is the winner
    if((name1_count < name2_count) && is_valid)
    { 
        std::cout << "Winner: " << name2 << std::endl;
    } 
    /// If name1 has a larger count, then name1 is the winner
    else if (is_valid)
    {
        std::cout << "Winner: " << name1 << std::endl;
    }

    /// Reset the the counts for the name1, name2, and the ballot
    name1_count = 0;
    name2_count = 0;
    ballot_count = 0;
}
    /// end of the main function
    return 0;
}
    
