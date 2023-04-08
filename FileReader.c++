#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

// This function will take in a vector of strings and a singular string. Based on that information the function will look over the
// entirety of the vector for instances of the same string and then add them together for the int "count".
int CountFrequency(std::vector<std::string> foodVector, std::string foodName)
{
    int count = std::count(foodVector.begin(), foodVector.end(), foodName);
    return count;
}

//This function accesses our test file and then puts that file within vectors, and from there puts them into a returnable map which will later
//allow us search for key value pairs.
std::map<std::string, int> FileReader()
{
    std::string fileName = "C:/Users/Michael Ladderbush/Desktop/CS-210/CornerGrocer/test.dat";
    //  std::cout << "Please enter a file name: " << std::endl;
    //  std::cin >> fileName; easier to use a path right now for my purposes

    std::map<std::string, int> foodList;
    std::vector<std::string> foodVector;
    std::vector<int> frequencyVector;
    std::string foodString;
    std::ifstream groceryFile;
    groceryFile.open(fileName.c_str());

    //This goes over the entirety of our specified file and puts them into a vector.
    while (!groceryFile.eof())
    {
        std::getline(groceryFile, foodString);
        foodVector.push_back(foodString);
    }

    //this loop then takes our string vector and pairs them with their frequency and adds them to the map.
    for (int i = 0; foodVector.size() > i; i++)
    {
        int frequency = CountFrequency(foodVector, foodVector.at(i));
        foodList.insert({foodVector.at(i), frequency});
    }
    return foodList;
}