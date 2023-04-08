#include <string>
#include <iostream>
#include <fstream>
#include <map>

// Here is our CreateMenu function, this function initializes a loop that ask a user for input and then display based that input.
void CreateMenu()
{
    while (bool active = true)
    {
        int userDecision;

        // We use outfile and infile streams in order to open files on our machine.
        std::ofstream outFile;

        // I created a map so that I could pair food names and their frequency, and in this case the FileReader function is call from FileReader.c++.
        // Which returns the necessary type.
        std::map<std::string, int> foodList = FileReader();

        std::string foodName;
        std::cout << "Please enter an option: " << std::endl;
        std::cout << "Press 1 to search for a food items frequency." << std::endl;
        std::cout << "Press 2 to print list of frequencies. " << std::endl;
        std::cout << "Press 3 to print frequencies in the form of a histogram. " << std::endl;
        std::cout << "Press 4 to quit the program." << std::endl;
        std::cin >> userDecision;

        //This try catch block will ask for a user input and then try to execute the switch case;
        try
        {
            switch (userDecision)
            {
            case 1:
                outFile.open("C:/Users/Michael Ladderbush/Desktop/CS-210/CornerGrocer/frequency.dat");
                std::cout << "Please enter a food item: " << std::endl;
                std::cin >> foodName;
                std::cout << foodList[foodName] << std::endl;
                outFile << foodName << " " << foodList[foodName] << std::endl;
                outFile.close();
                break;
            case 2:
                outFile.open("C:/Users/Michael Ladderbush/Desktop/CS-210/CornerGrocer/frequency.dat");
                std::cout << "List of food items: " << std::endl;
                for (auto const pair : foodList)
                {
                    std::cout << "" << pair.first << ": " << pair.second << "\n";
                    outFile << "" << pair.first << ": " << pair.second << "\n";
                }
                outFile.close();
                break;
            case 3:
                outFile.open("C:/Users/Michael Ladderbush/Desktop/CS-210/CornerGrocer/frequency.dat");
                for (auto const &pair : foodList)
                {
                    std::cout << "" << pair.first << ": ";
                    outFile << "" << pair.first << ": ";
                    for (int i = 0; pair.second > i; ++i)
                    {
                        std::cout << "*";
                        outFile << "*";
                    }
                    std::cout << std::endl;
                    outFile << std::endl;
                }
                outFile.close();
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                throw std::runtime_error("Invalid entry");
                break;
            }
        }
        catch (std::exception error)
        {
            std::cout << error.what() << std::endl;
        }
    }
}