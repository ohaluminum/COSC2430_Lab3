#include <iostream>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

//----------------------------------------------------- MAIN FUNCTION -----------------------------------------------

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    //Get the filename of argument name "input" and "output" and "command"
    //string input = am.get("input");
    //string output = am.get("output");

    //Test
    string input = "input1.txt";
    string output = "output1.txt";

    ifstream inFS;
    ofstream outFS;

    //Open file
    inFS.open(input);
    outFS.open(output);

    try
    {
        //Throw exception if the file doesn't exist
        if (!inFS.is_open())
        {
            throw runtime_error("ERROR: File not found");
        }

        //Throw exception if the file is empty
        if (inFS.peek() == EOF)
        {
            throw runtime_error("ERROR: File is empty");
        }




    }
    catch (runtime_error & e)
    {
        outFS << e.what() << endl;
    }

    inFS.close();
    outFS.close();

    return 0;
}