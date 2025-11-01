// This program is testScores #2 and it will represent as a leaderboard
// but with the student's name and their test score.
#include <iostream>
#include <iomanip>
#include <string>
#include "namescores.h"
using namespace std;


int main()
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
                while (!(cin >> studentGrade) || studentGrade <= 0)
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

            for (int index = 0; index < numStudents; ++index)
            {
                cout << "Student: " << index + 1 << " (SORTED): ";
                (classRoster + index)->displayNamescores();
            }


    // Deallocate the dynamic memory

        delete [] classRoster;
        classRoster = nullptr;
        return 0;

}






// Function defintions

void selectionSort(Student* array, int n)
{
    // this will be in charge of iterating through the U N S O R T E D array
    
        for (int start = 0; start < n - 1; start++)
        {
            Student* minPointer = array + start;        // minPointer stores the address of the Student type object with the smallest grade.

            for (int index = start + 1; index < n; index++)
            {
                // using the getter function to read the class member variable for the grades :
                    if ((array + index)->getGrade() < minPointer->getGrade())
                    {
                        minPointer = array + index;
                    }
            }

            // if the values match the logic above which is comparing both values to see which
            // one is the smallest to perform the swap logic:
            
            if (minPointer != (array + start))
            {
                swap(array + start, minPointer);
            }


        }
}

void swap(Student* a, Student* b)
{
   Student temp = *a;
   *a = *b;
   *b = temp;
}



void clearUserInputBuffer()
{
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(256, '\n');
}