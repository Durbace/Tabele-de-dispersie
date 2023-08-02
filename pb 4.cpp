#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
void citire(int& Nr, std::vector<int>& vector) {
	int x;
	std::ifstream fin("Text.txt");
	fin >> Nr;
	for (int i = 0; i < Nr; i++) {
		fin >> x;
		vector.push_back(x);
	}
	for (int i = 0; i < Nr; i++) {
		std::cout << vector[i] << " ";
	}
	fin.close();
}
void sumePartiale(int Nr, std::unordered_map<int, std::vector<std::pair<int, int>>>& sume_part,
	std::vector<int>& vector) {
	int sum;
	for (int i = 0; i < Nr; i++) {
		sum = 0;
		for (int j = i; j < Nr; j++) {
			sum += vector[j];
			sume_part[sum].push_back({ i,j });
		}
	}
}
void afisarePerechi(std::unordered_map<int, std::vector<std::pair<int, int>>> sume_part) {
	int k;
	do {
		std::cout << "Introduceti suma pe care o cautati: ";
		std::cin >> k;
		std::unordered_map<int, std::vector<std::pair<int, int>>>::iterator it =
			sume_part.find(k);
		if (it != sume_part.end()) {
			for (auto p : it->second) {
				std::cout << "Intervale cu suma " << k << " sunt: ";
				std::cout << "[" << p.first << "," << p.second << "] ";
			}
			std::cout << std::endl;
		}
		else
			if (k > 0)
				std::cout << "Suma de negasit.Introduceti alta." << std::endl;
	} while (k > 0);
}
int main()
{
	int Nr = 0;
	std::vector<int>vector;
	std::unordered_map<int, std::vector<std::pair<int, int>>> sume_part;
	citire(Nr, vector);
	sumePartiale(Nr, sume_part, vector);
	afisarePerechi(sume_part);
	return 0;
}
