#include <string>
#include <map>
#include "FileReader.c++"
#include "Menu.c++"

std::map<std::string, int> FileReader();
void CreateMenu();
int CountFrequency(std::vector<std::string> foodVector, std::string foodName);