#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
void duplicateApropiate(int& nr, int& dist, std::unordered_map<int, int>& ultima_pozitie,
	std::unordered_set<int>& numere_deja_afisate)
{
	int pozitie = 1;
	std::ifstream f("Text.txt");
	f >> dist;
	while (f >> nr) {
		if (ultima_pozitie[nr] > 0 && pozitie - ultima_pozitie[nr] <= dist) {
			if (numere_deja_afisate.find(nr) == numere_deja_afisate.end()) {
				numere_deja_afisate.insert(nr);
				std::cout << nr << " ";
			}
		}
		else
			ultima_pozitie[nr] = pozitie++;
	}
}
int main() {
	int nr = 0, dist = 0;
	std::unordered_map<int, int> ultima_pozitie;
	std::unordered_set<int> numere_deja_afisate;
	duplicateApropiate(nr, dist, ultima_pozitie, numere_deja_afisate);
	return 0;
}