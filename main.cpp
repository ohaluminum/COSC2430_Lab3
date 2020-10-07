#include <iostream>
#include <fstream>
#include <ctime>
#include "ArgumentManager.h"

using namespace std;

struct sortingTime
{
    string type;
    double time;

    sortingTime()
    {
        type = "";
        time = 0.0;
    }

    sortingTime(string type, double time)
    {
        this->type = type;
        this->time = time;
    }
};

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

// --------------------------------------------------- MERGE SORT ----------------------------------
void merge(int arr[], int low, int mid, int high)
{
    //Figure out the size of the array
    int size = high - low + 1;

    //Create temp dynamic array  
    int* temp = new int[size];

    //Initiate the array
    for (int i = 0; i < size; i++)
    {
        temp[i] = 0;
    }

    //Devide into two parts (left and right)
    int left = low;
    int right = mid + 1;
    int index = 0;

    //Start merging
    while (left <= mid && right <= high && index < size)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }

    //Check if the left side is empty
    while (left <= mid && index < size)
    {
        temp[index] = arr[left];
        index++;
        left++;
    }

    //Check if the right side is empty
    while (right <= high  && index < size)
    {
        temp[index] = arr[right];
        index++;
        right++;
    }

    for (int i = 0; i < size; i++)
    {
        arr[low + i] = temp[i];
    }

    delete[] temp;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// --------------------------------------------------- QUICK SORT ----------------------------------
int partition(int arr[], int i, int j)
{
    //Choose the first element to be the pivot
    int pivot = arr[i];
    int mid = i;

    for (int k = i + 1; k <= j; k++)
    {
        if (arr[k] < pivot)
        {
            mid++;
            swap(arr[k], arr[mid]);
        }
    }

    swap(arr[i], arr[mid]);
    return mid;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

//----------------------------------------------------- MAIN FUNCTION -----------------------------------------------

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    //Get the filename of argument name "input" and "output" and "command"
    string input = am.get("input");
    string output = am.get("output");

    //Test
    //string input = "input3.txt";
    //string output = "output3.txt";

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

        bubbleSort(bubbleArr, size);

        //Stop Timer
        t = clock() - t;

        double bubbleTime = double(t) / double(CLOCKS_PER_SEC);

        // ---------------------------------------- INSERTION SORT ----------------------------------------

        //Create a array for insertion sort
        int* insertionArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            insertionArr[i] = numArr[i];
        }

        //Start timer
        t = clock();

        insertionSort(insertionArr, size);

        //Stop Timer
        t = clock() - t;
        double insertionTime = ((double)t) / CLOCKS_PER_SEC;

        // ---------------------------------------- SELECTION SORT ----------------------------------------

        //Create a array for insertion sort
        int* selectionArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            selectionArr[i] = numArr[i];
        }

        //Start timer
        t = clock();

        selectionSort(selectionArr, size);

        //Stop Timer
        t = clock() - t;
        double selectionTime = (double(t)) / CLOCKS_PER_SEC;

        // ---------------------------------------- MERGE SORT ----------------------------------------

        //Create a array for insertion sort
        int* mergeArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            mergeArr[i] = numArr[i];
        }

        //Start timer
        t = clock();

        mergeSort(mergeArr, 0, size - 1);

        //Stop Timer
        t = clock() - t;
        double mergeTime = (double(t)) / CLOCKS_PER_SEC;

        // ---------------------------------------- QUICK SORT ----------------------------------------

        //Create a array for insertion sort
        int* quickArr = new int[size];

        for (int i = 0; i < size; i++)
        {
            quickArr[i] = numArr[i];
        }

        //Start timer
        t = clock();

        quickSort(quickArr, 0, size - 1);

        //Stop Timer
        t = clock() - t;
        double quickTime = (double(t)) / CLOCKS_PER_SEC;

        // --------------------------------------- STRUCT & ARRAY ------------------------------------------------
        
        //Using struct to store sort type and sort time
        sortingTime bubble("Bubble Sort", bubbleTime);
        sortingTime selection("Selection Sort", selectionTime);
        sortingTime insertion("Insertion Sort", insertionTime);
        sortingTime merge("Merge Sort", mergeTime);
        sortingTime quick("Quick Sort", quickTime);

        //Initiate a fixed array
        sortingTime timeMap[5] = {bubble, selection, insertion, merge, quick};
        
        //Sort the array by time using bubble sort (from short to long)
        bool isSort;

        for (int i = 0; i < 4; i++)
        {
            isSort = true;
            for (int j = 0; j < 4 - i; j++)
            {
                if (timeMap[j].time > timeMap[j + 1].time)
                {
                    swap(timeMap[j], timeMap[j + 1]);
                    isSort = false;
                }
            }

            if (isSort == true)
            {
                break;
            }
        }

        //Output to output file
        for (int i = 0; i < 4; i++)
        {
            outFS << timeMap[i].type << ", ";
        }

        outFS << timeMap[4].type << endl;

    }
    catch (runtime_error & e)
    {
        outFS << e.what() << endl;
    }

    inFS.close();
    outFS.close();

    return 0;
}