#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
void Competitii(const std::string&) {
	std::unordered_map<std::string, int> participanti;
	std::vector<std::string> multiParticipanti;
	std::ifstream fin("Text.txt");
	std::string nume, prenume;
	while (fin >> nume >> prenume) {
		std::string nume_complet = nume + " " + prenume;
		participanti[nume_complet]++;
		if (participanti[nume_complet] > 1) {
			if (std::find(multiParticipanti.begin(), multiParticipanti.end(), nume_complet) ==
				multiParticipanti.end()) {
				multiParticipanti.push_back(nume_complet);
			}
		}
	}
	fin.close();
	std::cout << "Persoane care participa la mai mult de o singura competitie: \n";
	for (const auto& participiant : multiParticipanti) {
		std::cout << "- " << participiant << "\n";
	}
}
int main()
{
	std::string fisier = "Text.txt";
	Competitii(fisier);
	return 0;
}