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

// --------------------------------------------------- INSERTION SORT ----------------------------------
void insertionSort(int* arr, int n)
{
    int i = 0;
    int j = 0;
    int key = 0;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        //Move elements of arr[0, 1, 2, ... , i - 1], which are greater than key, to one position ahead of their current position.
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// --------------------------------------------------- SELECTION SORT ----------------------------------
void selectionSort(int* arr, int n)
{
    int i = 0;
    int j = 0;
    int min = 0;
    int temp = 0;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        //Unsorted array
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                //Update min
                min = j;
            }
        }

        //Swap 
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// --------------------------------------------------- SELECTION SORT ----------------------------------
void mergeSort()
{

}

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
        clock_t t = clock();
        
        //Bubble sort 
        bubbleSort(bubbleArr, size);

        //Stop Timer
        t = clock() - t;
        double bubbleTime = ((double)t) / CLOCKS_PER_SEC;
        
        cout << "Bubble Sort: " << bubbleTime * 1000 << " ms" << endl;

        // ---------------------------------------- INSERTION SORT ----------------------------------------

        //Create a array for insertion sort
        int* insertionArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            insertionArr[i] = numArr[i];
        }

        //Start timer
        t = clock();

        //Bubble sort 
        insertionSort(insertionArr, size);

        //Stop Timer
        t = clock() - t;
        double insertionTime = ((double)t) / CLOCKS_PER_SEC;

        cout << "Insertion Sort: " << insertionTime * 1000 << " ms" << endl;

        // ---------------------------------------- SELECTION SORT ----------------------------------------

        //Create a array for insertion sort
        int* selectionArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            selectionArr[i] = numArr[i];
        }

        //Start timer
        t = clock();

        //Bubble sort 
        selectionSort(selectionArr, size);

        //Stop Timer
        t = clock() - t;
        double selectionTime = (double(t)) / CLOCKS_PER_SEC;

        cout << "Selection Sort: " << selectionTime * 1000 << " ms" << endl;

        // ---------------------------------------- MERGE SORT ----------------------------------------

       


        /*for (int i = 0; i < size; i++)
        {
            cout << selectionArr[i] << " ";
        }*/



        


    }
    catch (runtime_error & e)
    {
        outFS << e.what() << endl;
    }

    inFS.close();
    outFS.close();

    return 0;
}