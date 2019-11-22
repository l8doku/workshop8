//
// Here you can find answers for tasks from Workshop 8
//

#ifndef WORKSHOP8_IMPLEMENTATION_H
#define WORKSHOP8_IMPLEMENTATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <set>
#include <map>
#include <algorithm>

typedef std::vector<std::string> VecNames;

VecNames toCountSurvived(std::istream& inputFile);
void printVec(const VecNames& vectorToPrint);
std::string genNDigitNumber(int randomState, int N);
void reverseVector(VecNames& vectorToPrint);
std::set<int> countClasses(std::istream& inputFile);
void embarkedToSurvived(std::istream& inputFile,std::map<char,int>& embarkedMap);
std::map<std::string,int> diffAbbreviation(std::istream& inputFile);
void printMap(const std::map<std::string, int>& mapToPrint);


std::vector<std::string> toCountSurvived(std::istream& inputFile)
{
    std::string line;
    VecNames aliveNames;

    while (!inputFile.eof() && inputFile.good ())
    {
        std::getline (inputFile, line);
        std::stringstream ss(line);
        std::string token;

        int iToken = 0;
        bool isSurvived = false;
        while (!ss.eof() && ss.good())
        {
            std::getline(ss, token,',');

            if (iToken == 1)
            {
                short survived;
                std::stringstream tokenString(token);
                tokenString >> survived;
                if (survived == 1)
                    isSurvived = true;
            }

            if (iToken == 3 && isSurvived)
            {
                std::string surname;
                std::stringstream surStream(token);
                std::getline(surStream, surname,';');
                aliveNames.push_back(surname);
            }

            ++iToken;
        }
    }

    return aliveNames;
}

void printVec(const VecNames& vectorToPrint)
{
    for (int i = 0; i < vectorToPrint.size(); ++i)
        std::cout << (i+1) << ") " << vectorToPrint[i] << '\n';
}

// OR
void printVecV2(const VecNames& vectorToPrint)
{
    int i = 1;
    for (std::string name : vectorToPrint)
        std::cout << i++ << ") " << name <<'\n';
}

// OR
void printVecV3(const VecNames& vectorToPrint)
{
    int i = 1;
    for (VecNames::const_iterator it = vectorToPrint.begin(); it != vectorToPrint.end(); ++it)
        std::cout << i++ << ") " << *(it) <<'\n';
}


std::string genNDigitNumber(int randomState, int N)
{
    std::mt19937 gen; // random generator
    gen.seed(randomState); // seed, an output for the same number will be the same

    std::uniform_int_distribution<int> distributionFrom_0(0,9);
    std::uniform_int_distribution<int> distributionFrom_1(1,9);

    std::stringstream numberStream;
    for (int i = 0; i < N; i++)
        numberStream << (i > 0 ? distributionFrom_0(gen) : distributionFrom_1(gen)); // a ternary operator ==
        //              ((statement) ? ifTrue : ifFalse)

    std::string number;
    std::getline(numberStream,number);
    return number;
}


#endif //WORKSHOP8_IMPLEMENTATION_H
