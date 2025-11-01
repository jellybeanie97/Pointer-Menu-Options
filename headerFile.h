// this is the header file for stating all the function prototypes
// needed for the testScores2.cpp main file to process.
// I decided to do it this way to provide a cleaner and neat code. 

#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <string>

// Class declaration

// used pointer notation so the user can input each test score from each test.

class Student
{
   private:
        std::string name;
        int grade;
    
    public:
    
    // default constructor:

        Student() : name(""), grade(0) {}


    // constructor with parameters

        Student(const std::string& n, int g) : name(n), grade(g) {}

    // Setter Function to get the input from the user :

        void setStudentReport(const std::string& n, int g)
        {
            name = n;
            grade = g;
        }

    // Getter Function : for granting access to modify and pass the classes into the selectionSort();

        int getGrade() const
        {
            return grade;
        }

        std::string getName() const
        {
            return name;
        }
    

        void displayNamescores() const
        {
            std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
        }

};



// Function Prototypes:
// ========================== //

    int displayProgramMenu();

    // Program 1 :
        void testScores();      // main title of the program #1 logic
        void selectionSort(int *array, int size);
        double avgtestScores(int *testScores, int numTests);
        void swap(int *a, int *b);


// =============================================================================== //



    // Program 2 :
        void studentLeaderboardScores();    // main title of the program #2 logic
        void clearUserInputBuffer();        // this clears any errors or mistypes during the user input validation process, and allows the user to input a new value.
        void selectionSort(Student* array, int n);
        void swap(Student* a, Student* b);
        double avgtestScores(Student *classRoster, int numTests);



// =============================================================================== //



    // Program 3 :
        void medianFunction();          // main title of the program #3 logic
        double findMedianValue(const double* array, int size);
            void oddSizeArray();
            void evenSizeArray();
            void fractionsEvenSizeArr();
            void handleErrors();


// ============================================================================== //

    // Program 4 : 
        void movieStatistics();         // main title of the program #4 logic
        void bubbleSort(double* arr, int size);
        double calculateMean(const double* arr, int size);
        double calculateMedian(const double* arr, int size);
        void calculateMode(const double* arr, int size);




// ================================================================================ //


#endif