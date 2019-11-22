/*******************************************************************************
 *
 *  Workshop 7
 *
 * 1) Define an alias VecNames for the std::vector<std::string> datatype using the typedef keyword.
 *
 * 2) Create a function called toCountSurvived that obtains an input stream
 * object (given by reference) istream& (input.csv), reads the whole file line by line and get a
 * surname ("Braund; Mr. Owen Harris" will be just "Braund") of survived person
 * from input.csv (Survived column). Function returns VecNames data type -- vector of survived surnames.
 *
 * 3) Create a method printVec(const VecNames& aliveNames).
 * The method prints the content of the given vector out to the standard output with elements and its enumeration
 * 1) Name_1
 * 2) Name_2
 * ...
 * N) Name_n
 *
 * 4) Create a method named genNDigitNumber(const int& random_state).
 * The method return random three digit number as std::string.
 * Use:
 * std::mt19937 gen(time(nullptr));
 * std::uniform_int_distribution<int> distr(0,9);
 * int rNum = distr(gen); // random number
 *
 * 5) Create new vector newVec as VecNames and fill it by random numbers. newVec size should be the same as obtained
 * from toCountSurvived
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Workshop 8
 *
 * 6) Reverse newVec
 *
 * 7) Create a function countClasses which returns set of classes. Function returns set(int).
 *
 * 8) Create a function embarkedToSurvived which returns count of survived for all embarked types.
 * Function not returns map(char,int), map puts into function by reference
 * 
 * 9) Create a function diffAbbreviation which returns count of {Mr. Miss etc.} Function returns map(std::string,int)
 *
 * 10) Create a method printMap(const std::map(std::string, int)& mapToPrint).
 * The method prints the content of the given map where T is (std::string, char, etc.)
 *
 ******************************************************************************/

#include "implementation.h"

int main ()
{
    const std::string INP_FILE_NAME = "/home/georgii/WORK/DSBA/repositories/workshop8/workshop8/tasks/input.csv";
    std::ifstream inputFile;
    inputFile.open(INP_FILE_NAME);
    VecNames aliveNames = toCountSurvived(inputFile);
    inputFile.close();
    printVec(aliveNames);

    VecNames newVec;

    int size = aliveNames.size();
    int N = 5;
    while (size > 0)
        newVec.push_back(genNDigitNumber(size--,10));
    printVec(newVec);


}



