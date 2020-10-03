#include <iostream>
#include <fstream>
#include <ctime>
#include "ArgumentManager.h"

using namespace std;

// ----------------------------------------------------- BUBBLE SORT -----------------------------------------------
void bubbleSort(int* arr, int n)
{
    int temp = 0;
    bool isSwapped = false;

    for (int i = 0; i < n - 1; i++)
    {
        isSwapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSwapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break 
        if (isSwapped == false)
        {
            break;
        }
    }
}

// --------------------------------------------------- SELECTION SORT ----------------------------------
void selectionSort(int* arr, int n)
{

}


//void bubbleSort(int a[], int n) {
//    for (int i = n - 1; i >= 1; i--) {
//        for (int j = 1; j <= i; j++) {
//            if (a[j - 1] > a[j])
//                swap(a[j], a[j - 1]);


//----------------------------------------------------- MAIN FUNCTION -----------------------------------------------

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    //Get the filename of argument name "input" and "output" and "command"
    //string input = am.get("input");
    //string output = am.get("output");

    //Test
    string input = "input.txt";
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

        //Read array size 
        int size = 0;
        inFS >> size;

        //Store the number into array (keep original version)
        int* numArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            inFS >> numArr[i];
        }

        // ----------------------------------------- BUBBLE SORT -----------------------------------------------

        //Create a array for bubble sort
        int* bubbleArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            bubbleArr[i] = numArr[i];
        }

        //Start timer
        clock_t startTime = clock();
        
        //Bubble sort 
        bubbleSort(bubbleArr, size);

        //Stop Timer
        clock_t endTime = clock();
        clock_t bubbleTime = (endTime - startTime) / CLOCKS_PER_SEC;
        
        cout << "Elapsed time: " << bubbleTime * 1000 << " ms" << endl;


    }
    catch (runtime_error & e)
    {
        outFS << e.what() << endl;
    }

    inFS.close();
    outFS.close();

    return 0;
}