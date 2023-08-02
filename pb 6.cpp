#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
void citire(std::ifstream& f, int& nr_mag, std::unordered_map<std::string, std::list<int>>& map) {
	f >> nr_mag;
	for (int index_mag = 0; index_mag < nr_mag; index_mag++) {
		int nr_prod;
		f >> nr_prod;
		std::string produs;
		for (int index_prod = 0; index_prod < nr_prod; index_prod++) {
			f >> produs;
			map[produs].push_front(index_mag);
		}
	}
}
void produseExclusiveMagazin(int nr_mag, std::unordered_map<std::string, std::list<int>>&
	map, std::vector<std::list<std::string>>& prod_exclusive) {
	prod_exclusive.resize(nr_mag);
	for (auto& p : map) {
		if (p.second.size() == 1) {
			prod_exclusive[p.second.front()].push_back(p.first);
		}
	}
}
void afisare(int poz_maxim, std::vector<std::list<std::string>>& prod_exclusive) {
	std::cout << "Index magazin cu numar maxim de produse exclusive : " << poz_maxim << '\n';
	std::cout << "Produse exclusive : ";
	for (auto& p : prod_exclusive[poz_maxim]) {
		std::cout << p << " ";
	}
	std::cout << '\n';
}
int main() {
	std::ifstream f("Text.txt");
	int nr_mag;
	std::unordered_map<std::string, std::list<int>> map;
	std::vector<std::list<std::string>> prod_exclusive;
	citire(f, nr_mag, map);
	produseExclusiveMagazin(nr_mag, map, prod_exclusive);
	int poz_maxim = 0;
	for (int index_mag = 0; index_mag < nr_mag; index_mag++) {
		if (prod_exclusive[index_mag].size() > prod_exclusive[poz_maxim].size()) {
			poz_maxim = index_mag;
		}
	}
	afisare(poz_maxim, prod_exclusive);
	return 0;
}