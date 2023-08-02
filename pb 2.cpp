#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
void citire_fisier(std::string& sir1, std::string& sir2)
{
	std::ifstream fin("Text.txt");
	std::string line;
	std::getline(fin, line);
	sir1 = line;
	std::cout << sir1 << '\n';
	std::getline(fin, line);
	sir2 = line;
	std::cout << sir2 << '\n';
}
bool permutare(std::string sir1, std::string sir2)
{
	std::unordered_set<char> set1, set2;
	if (sir1.length() != sir2.length())
		return false;
	for (char c : sir1)
		set1.insert(c);
	for (char c : sir2) {
		if (set1.find(c) == set1.end())
			return false;
		set2.insert(c);
	}
	return(set1.size() == set2.size());
}
int main()
{
	std::string sir1, sir2;
	citire_fisier(sir1, sir2);
	std::cout << permutare(sir1, sir2);
	return 0;
}