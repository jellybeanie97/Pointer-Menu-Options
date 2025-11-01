// Janeyli Palma
// This includes a menu-driven option to access all the programs for chapter10.
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "headerFile.h"
using namespace std;



int main()
{
    int choice;

    do
    {
        choice = displayProgramMenu();

        switch (choice)
        {
        case 1:
           testScores();
            break;

        case 2: 
            studentLeaderboardScores();
            break;

        case 3:
            medianFunction();
            break;

        case 4:
            movieStatistics();
            break;

        case 5:
            cout << "\n Exiting the program. G O O D B Y E!~ :D" << endl;
            break;

        default:
            cout << "\nUnknown type. Please enter the following options on the menu!\n";
            break;
        }
    } while (choice != 5);

    return 0;
    
}




// Function definitions :

int displayProgramMenu()
{
    int choice;

        cout << "\n=== CH. 10 P R O G R A M S  M E N U ====\n" << endl;
        cout << "1. TestScores Program " << endl;
        cout << "2. Testscores 2.0 Program " << endl;
        cout << "3. Median Function Program " << endl;
        cout << "4. Movie Statistics Program " << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice (1-5): ";


// user input validation

    while (!(cin >> choice))
    {
        cout << "Invalid input. Please enter a number (1-5): ";
        // Assuming clearUserInputBuffer() is prototyped in headerFile.h
        clearUserInputBuffer(); 
    }
    clearUserInputBuffer(); // Clear any trailing characters (like newline)


    return choice;
}




// P R O G R A M  #1 FUNCTION DEFINITIONS :)
// ============================================================================= //

void clearUserInputBuffer()
{
    cin.clear();        // clears any error flag on console input
    cin.ignore(1000, '\n');     // discards all remaining characters up to the newline
}





void testScores()
{
    int *testScores = nullptr;           // to dynamically allocate an array
    double  total = 0.0,                        // Accumulating each testScore provided by the user.
            average;                        // Holds the average of the testScores

    int numTests,                           // This holds the number of testScores provided by the user.
        inputValue;
    
    // Ask the user to input the number of testScores

        cout << "Enter the number of tests: \n";
       cin >> numTests;

    
    // Dynamically allocates an array large enough to hold the test scores.

        testScores = new int[numTests];            // Allocate memory

    
    // User Input Validation (validating if the value is negative integer)

    for (int count = 0; count < numTests; ++count)
    {
        bool valid = false;


        while (!valid)
        {
            cout << "Test " << (count + 1) << ": ";


            // This checks for any error type mismatch from the prompted user.

            if (cin >> inputValue)     
            {
                if (inputValue < 0)
                {
                    cout << "Invalid value. Must be a positive value. Please try again. \n";
                }
                else
                {
                    // This is only if the prompted user input is valid and matches the criteria.

                        *(testScores + count) = inputValue;
                        valid = true;       // this exits the inner loop :)
                }
            }
            else
            {

               // Validates the user input :  

                    cout << "Invalid value. Must be a positive integer. Please enter a positive value: \n";

                // This removes any error input from the user,
                // So it can clear the next line to get the,
                // positive value needed to process the array.

                    cin.clear();                    
                    string temp;                 
                    getline(cin, temp);         

            }
        }
        
    }


    // Get the grades for each test

        cout << "\nHere are the unsorted test scores for each test: \n";
            for (int count = 0; count < numTests; ++count)
            {
                cout << "Test " << (count + 1) << ": " <<
                *(testScores + count) << endl;

            }                



    // Sort the grades in ascending order

        selectionSort(testScores, numTests);


    // Calculate and display the testGrades to get the average

        average = avgtestScores(testScores, numTests);


    // Displays the sorted list from ascending order

        cout << "\nSorted Test Scores: \n";
        for (int count = 0; count < numTests; ++count)
        {
            cout << "Test " << count + 1 << ": " << *(testScores + count) << endl;
        }


    // Display the results

        cout << setprecision(2) << fixed << showpoint;
        cout << "\n\n Average of the Test Scores: " << average << endl;


    // This will remove any unnecessary garbage and non-reusable code no longer needed

        delete [] testScores;
        testScores = nullptr;
}



// decided to go with selection sort for a faster and efficient
// approach at sorting the testScores in ascending order.

    void selectionSort(int *array, int size)         
    {
        int minIndex, minValue;

            for (int start = 0; start < (size - 1); start++)
            {
                minIndex = start;
                minValue = *(array + start);        // using pointer notation to get the start value of the test score.

                    for (int index = start + 1; index < size; index++)
                    {
                        if (*(array + index) < minValue)        // this compares the values from the test score in 
                                                                // the array to the minValue.
                        {
                            minValue = *(array + index);        
                            minIndex = index;
                        }
                    }
                    swap(*(array + minIndex), *(array + start));        // after comparing, then it swaps the values in order.
            }
    } 




// this function will accumulate the total of the testScores and
// then take the average by the numTests and return the average.

double avgtestScores(int *testScores, int numTests)
{
    double total = 0.0,     // accumulating the test scores.
            average;

    for (int count = 0; count < numTests; count++)
    {
        total += *(testScores + count);
    }

    average = (total / numTests);

        if (numTests == 0)
            return 0.0;     // this prevents any division by zero.

    return average;
    
}




// this will swap the ptr values in the array so
// it can be sorted in ascending order.

void swap(int *a, int *b)
{       
    int temp = *a;
    *a = *b;
    *b = temp;
}



// =============================================================================== //




// these are the FUNCTION DEFINITIONS for the  P R O G R A M  #2 :

// ========================================================================== //

void studentLeaderboardScores()
{
        int numStudents;

    // this will prompt the user to enter the number of students for grades and names

        cout << "Enter the number of students in the class: ";

        // I decided to add the input validation for the user if they enter a negative integer.

            while (!(cin >> numStudents) || numStudents <= 0)
            {
                cout << "Invalid value. Please enter a positive integer: ";
                clearUserInputBuffer();
            }
            clearUserInputBuffer();

    // Dynamically allocating an array of classes
    
        Student* classRoster = new Student[numStudents];

        cout << "\n This is the dynamically allocated array for " << numStudents << " students for this classroom." << endl;

    // Prompts the user to fill and enter the necessary data for the given allocated array :

        for (int index = 0; index < numStudents; ++index)
        {
            string studentName;
            int studentGrade;

            cout << "\n ==== Student's Name and Grade ==== \n" << index + 1 << "    " << endl;
            cout << "Enter the student's name: ";
            getline(cin, studentName);

            cout << "Enter the student's grade: ";

            // input validation incase the user enters a negative value :
                while (!(cin >> studentGrade) || studentGrade < 0)
                {
                    cout << "Invalid value. Please enter a positive integer value: ";
                    clearUserInputBuffer();
                }
                clearUserInputBuffer();


            // Now we will be arranging and setting the data reported by the user 
            // and implement them using the objects granted by the class while using pointer notation.

                (classRoster + index)->setStudentReport(studentName, studentGrade);
        }


    // Sort the array by grades using selection sort for efficiency and utilizing less computer resources.

        selectionSort(classRoster, numStudents);

    // Display the sorted grades

        cout << "\n ==== S O R T E D  S T U D E N T ' S  G R A D E ==== \n" << endl;
        cout << "Name | Grade\n";
        cout << "===========================\n";
        
            for (int index = 0; index < numStudents; ++index)
            {
                cout << setw(3) << index + 1 << "  | "
                    << setw(5) << (classRoster + index)->getGrade() << " | "
                     << (classRoster + index)->getName() << endl;            
            }

        cout << "============================================" << endl;

    // Deallocate the dynamic memory

        delete [] classRoster;
        classRoster = nullptr;
}


// this is the modified selectionSort for the testScores 2.0
// this will allow it to pass an array of classes and objects

    void selectionSort(Student* array, int n)
    {
        // this will be in charge of iterating through the U N S O R T E D array

            int minIndex;       // track the index position of the min. element

            for (int start = 0; start < n - 1; start++)
            {
                minIndex = start;        // minPointer stores the address of the Student type object with the smallest grade.

                for (int index = start + 1; index < n; index++)
                {
                    // using the getter function to read the class member variable for the grades :
                        if ((array + index)->getGrade() < (array + minIndex)->getGrade())
                        {
                           minIndex = index;
                        }
                }

                // if the values match the logic above which is comparing both values to see which
                // one is the smallest to perform the swap logic:
                
                if (minIndex != start)
                {
                    swap(*(array + start) , *(array + minIndex));
                }

            }
    }

double avgtestScores(Student *classRoster, int numTests)
{
   long double total = 0.0;     // accumulating the test scores and using long to ensure 
                                // closest precision for the average.
    double  average;

// this will test for any division by zero 

    if (numTests <= 0)
    {
        return 0.0;
    }

 
//  this will iterate using the pointer arithmetic 

    for (int count = 0; count < numTests; count++)
    {
        total += (classRoster + count)->getGrade();     // using pointer notation and getter function
                                                        // access for the grade.
    }

    average = (double)(total / numTests);

    return average;
    
}

// this is also the modified swap so it 
// can switch the class objects values to
// sort the grades in ascending order 

    void swap(Student& a, Student& b)
    {
        Student temp = a;
        a = b;
        b = temp;
    }




// ================================================================================== //




void medianFunction()
{
    int choice;

    // used a do while loop to test all the cases for all circumstances of finding the median
    // i believed it would compact the code better and efficiently.

        do
        {
            cout << "\n =================================== \n" << endl;
            cout << " =========    F I N D I N G  M E D I A N  V A L U E S   ==========" << endl;
            cout << "\n ================================================================ \n" << endl;
            cout << "1. ODD SIZE ARRAY \n" << endl;
            cout << "2. EVEN SIZE ARRAY \n" << endl;
            cout << "3. FRACTION EVEN SIZE ARRAY \n" << endl;
            cout << "4. Encountering Errors\n" << endl;
            cout << "5. Exit the program\n" << endl;
            cout << "Enter your desired program of choice :) (1-5): ";


            // Ask the user for their choice and validate their input to verify and pass the logic below

                if (!(cin >> choice))
                {
                    cout << "\n Invalid value. Please enter a positive integer from the following options: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    choice = 0;         // this is set to be passed as an invalid value to continue the loop
                    continue;
                }


                    switch (choice)
                    {
                    case 1:
                        oddSizeArray();
                        break;

                    case 2:
                        evenSizeArray();
                        break;

                    case 3:
                        fractionsEvenSizeArr();
                        break;
                    

                    case 4:
                        handleErrors();
                        break;

                    case 5:
                        cout << "Exiting the program :( \n" << endl;

                    default:
                        cout << "\nInvalid option. Must choose from the menu options! :)" << endl;
                        break;
                    }

        } while (choice != 5);
}


double findMedianValue(const double* array, int size)
{
    if (size <= 0)
    {
        cout << "Invalid number for the following array. Must be a positive integer." << endl;

        return 0.0;
    }

    // will be using the modulus operator to check if the size is odd or an even value

        if (size % 2 != 0)
        {

        // this will validate and test for odd values in the elements located in the array.

            int middleValue = size / 2;     // this will calculate the index of the mid. element

            // using pointer arithmetic, i will access the element from the array

                 const double* middlePointer = (array + middleValue);
                 return *middlePointer;
        }
        else 
        {
            // this will validate and test for even values in the elements located in the array.

                // these two middle values indices are of (size/2 - 1) and (size/2)

                    int lowerValue = (size / 2) - 1;
                    int upperValue = (size / 2);

                // Accessing the pointers for the 2 middle elements provided in the array

                    const double* lowerPointer = (array + lowerValue);
                    const double* upperPointer = (array + upperValue);
                
                // This will perform the calculation for the median of the 2 middle values

                    return (*lowerPointer + *upperPointer) / 2.0;
        }
}


        void oddSizeArray()
            {
                // Case 1 : ====== O D D   S I Z E  A R R A Y ========== //
                // Sorted Array: {1.0, 3.0, 5.0, 7.0, 9.0}
                // Size: 5. Middle value: 2. Median: 5.0

                    double arrayOddValues[] = {1.0, 3.0, 5.0, 7.0, 9.0};
                    int sizeOdd = 5;

                        double medianOddVals =  findMedianValue(arrayOddValues, sizeOdd);

                            cout << "Here are the array of Odd Size Elements : {1.0, 3.0, 5.0, 7.0, 9.0} " << endl;
                            cout << "The Median Value: " << medianOddVals << " (The Predicted Value will be 5.0)" << endl;
                            cout << "===============================================================================" << endl;

            }

        void evenSizeArray()
            {
                // Case 2: ============ E V E N  S I Z E  A R R A Y ================ //
                // SORTED ARRAY VALUES: {2.0, 4.0, 6.0, 8.0}
                // SIZE: 4. MIDDLE VALUES: 1 and 2. Median : 5.0

                    double arrayEvenValues[] = {2.0, 4.0, 6.0, 8.0};
                    int sizeEvenValues = 4;

                        double medianEvenValues = findMedianValue(arrayEvenValues, sizeEvenValues);
            
                            cout << "Here are the array of EVEN SIZE ELEMENTS : {2.0, 4.0, 6.0, 8.0}" << endl;
                            cout << "The Median value: " << medianEvenValues << " (The Predicted value will be 5.0)" << endl;
                            cout << "================================================================================" << endl;

            }

        void fractionsEvenSizeArr()
            {
                // Case 3: =================== E V E N  S I Z E  A R R A Y (fractions) ================== //
                // SORTED ARRAY VALUES: {10.0, 20.0, 25.0, 30.0, 40.0, 50.0}
                // SIZE IS 6. MIDDLE VALUES IS 2 AND 3. MEDIAN : 27.5

                    double arrEvenFractions[] = {10.0, 20.0, 25.0, 30.0, 40.0, 50.0};
                    int sizeEvenFraction = 6;

                        double medianEvenFractions = findMedianValue(arrEvenFractions, sizeEvenFraction);
            
                            cout << "Here are the array of FRACTION ELEMENTS : {10.0, 20.0, 25.0, 30.0, 40.0, 50.0}" << endl;
                            cout << "The Median value: " << medianEvenFractions << " (The Predicted value will be 27.5)" << endl;
                            cout << "================================================================================" << endl;


            }

        void handleErrors()
            {
                // Case 4: ================ ERRORS OCCURING WITH (SIZE <= 0) ==================

                    double arrEmpty[] = {};
                    int sizeEmptyValues = 0;
                    double medianEmpty = findMedianValue(arrEmpty, sizeEmptyValues);

                        cout << "The provided array tested and passed as empty. Here is the Median Value that was returned: "
                            << medianEmpty << endl;
            }






// ================================================================================== //


void movieStatistics()
{
    int numStudents;

    cout << "\n=====================================\n" << endl;
    cout << "            Movie Report                 " << endl;
    cout << "\n=====================================\n" << endl;



    // Prompt the user for the student data for the movie report

        while (true)
        {
            cout << "Enter the number of students: ";

            // input validation
                if (cin >> numStudents && numStudents > 0)
                {
                    break;
                }
                else 
                {
                    cout << "Invalid value. Please enter a positive integer." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
        }


    // Dynamically allocated an array for the report

        double* watchedMovies = new double[numStudents];

            cout << " === Movie Consesus Report ===" << endl;

    // Input the following data into the array

        for (int index = 0; index < numStudents; ++index)
        {
            double numMovies;

            // input validation: just to verify and pass it is a positive value.
                while (true)
                {
                    cout << "Enter movies watched per student " << (index + 1) << " (positive whole integer value): ";

                        if (cin >> numMovies && numMovies >= 0 && numMovies == static_cast<int>(numMovies))
                        {
                            *(watchedMovies + index) = numMovies;       // it would be easier to utilize pointer notation for the user's input
                                break;
                        } else
                            {
                                cout << "Invalid entry. Please enter a positive whole integer." << endl;
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                }
        }


        // Sorting the given numbers of movies watched by student
        // an array for median and mode calculations.

            bubbleSort(watchedMovies, numStudents);

                cout << "=======================================================" << endl;
                cout << "  Sorting the Amount of Movies by Mean, Median and Mode " << endl;
                cout << "=========================================================" << endl;

        
        // Display the Sorted Report

            cout << "Student Movie Data Size: " << numStudents << " students " << endl;
            cout << "Sorted Movie Report: {";
                for (int index = 0; index < numStudents; ++index)
                {
                    cout << static_cast<int>(*(watchedMovies + index));
                        if (index < numStudents - 1)
                        {
                            cout << ", ";
                        }
                }
    
                cout << "}" << endl;
                cout << "===========================================================" << endl;
                
        // Calculating the mean array data report

            double studentMean = calculateMean(watchedMovies, numStudents);
                cout << "Here is the Average (Mean) of the Data Report: " << studentMean 
                    << setprecision(2) << fixed << showpoint << right << setw(5) << 
                 " this is the Amount of Movies that were watched Per Month." << endl;
        
        // Calculating the Median of the array data report

            double studentMedianValue = calculateMedian(watchedMovies, numStudents);
                cout << "Here is the Median value(s) for the Data Report: " << studentMedianValue
                    << setprecision(2) << fixed << showpoint << right << setw(5) <<
                    " this is the Amount of Movies that were watched Per Month." << endl;

        // Calculating the Mode of the array data report

            calculateMode(watchedMovies, numStudents);

            cout << "======================================================================" << endl;

    
// Making sure to deallocate the memory to prevent any errors/bugs into the program.

    delete [] watchedMovies;
    watchedMovies = nullptr;


}




void bubbleSort(double* moviesWatchedArray, int size)
{
    bool performSwap = true;            // allowing the loop to begin iterating

    for (int maxElement = size - 1; maxElement > 0 && performSwap; maxElement--)
    {
      performSwap = false;      // No swapping values have occured during this pass

        for (int index = 0; index < maxElement; index++)
        {
            if (*(moviesWatchedArray + index) > *(moviesWatchedArray + index + 1))
            {
                // this will swap the values to be sorted in ascending order
                    swap(*(moviesWatchedArray + index), *(moviesWatchedArray + index + 1));
                    performSwap = true;
            }
        }
    }
}




double calculateMean(const double* moviesWatchedArray, int size)
{
    // this will handle any input less than 0

        if (size <= 0)
        {
            return 0.0;
        }

    double sum = 0.0;

        // using pointer notation will help me iterate it through the array

            for (int index = 0; index < size; ++index)
            {
                sum += *(moviesWatchedArray + index);
            }
            
            return sum / size;
}




double calculateMedian(const double* moviesWatchedArray, int size)
{
    if (size <= 0)
    {
        return 0.0;
    }

    if (size % 2 != 0)
    {
        int middleValue = size / 2;
            return *(moviesWatchedArray + middleValue);
    }
    else
    {
        int lowerValue = (size / 2) - 1,
            upperValue = (size / 2);

        const double* lowerPOINTER = (moviesWatchedArray + lowerValue);
        const double* upperPOINTER = (moviesWatchedArray + upperValue);

        return (*lowerPOINTER + *upperPOINTER) / 2.0;
    }
}



void calculateMode(const double* moviesWatchedArray, int size)
{
    if (size <= 0)
    {
        cout << "Movie Report's Mode: {Empty Data Set}" << endl;
        return;
    }

    int maxCount = 0,
        ongoingCount = 1;
    
    vector<double> modes;

    // this will go through the first pass of the array 
    // and find the frequent most occured value.

        for(int index = 1; index < size; ++index)
        {
            if (*(moviesWatchedArray + index) == *(moviesWatchedArray + index - 1))
            {
                ongoingCount++;
            }
            else 
            {
                if (ongoingCount > maxCount)
                {
                    maxCount = ongoingCount;
                }
                ongoingCount = 1;       // this allows for the loop to reset the count
            }
        }

        // Verifies and checks the last sequence of values

            if (ongoingCount > maxCount)
            {
                maxCount = ongoingCount;
            }

        // This will collect all values through the second pass

            ongoingCount = 1;

        // Validation for when it says there is no mode; similar to a default option

            if (maxCount == 1)
            {
                cout << "This mode has no repeated values. " << endl;
                return;
            }

        // Resetting the loop for the second pass

            for (int index = 1; index < size; ++index)
            {
                if (*(moviesWatchedArray + index) == *(moviesWatchedArray + index - 1))
                {
                    ongoingCount++;
                }
                else
                {
                    if (ongoingCount == maxCount)
                    {
                        modes.push_back(*(moviesWatchedArray + index - 1));
                    }
                    ongoingCount = 1;
                }
            }

            // Verifying the last sequence of values

                if (ongoingCount == maxCount)
                {
                    modes.push_back(*(moviesWatchedArray + size - 1));
                }

                cout << "3. Mode(s): ";
                    for (size_t index = 0; index < modes.size(); ++index)
                    {
                        cout << static_cast<int>(modes[index]);

                            if (index < modes.size() - 1)
                            {
                                cout << ", ";
                            }
                    }

                    cout << " (This value appeared " << maxCount << " times)" << endl;


}


void swap(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}