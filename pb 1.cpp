#include <iostream>
#include <fstream>
#include <unordered_map>
class HashMap {
public:
	int m_size = 0;
	std::unordered_map<int, std::string> m_map;
	void insert(std::pair<int, std::string>p) {
		m_map[p.first] = p.second;
		m_size++;
		checkLoadFactor();
	}
	void remove(int key) {
		if (m_map.find(key) != m_map.end()) {
			m_map.erase(key);
			m_size--;
		}
	}
	std::string find(int key) {
		if (m_map.find(key) != m_map.end())
			return m_map[key];
		return " ";
	}
	void print() {
		for (std::pair<int, std::string> elm : m_map)
			std::cout << "<" << elm.first << "," << elm.second << ">" << std::endl;
	}
private:
	void checkLoadFactor() {
		float loadFactor = m_size / m_map.bucket_count();
		if (loadFactor > 1.0) {
			std::unordered_map<int, std::string> newmap(m_map);
			m_map.swap(newmap);
		}
	}
};
int main()
{
	HashMap map;
	std::ifstream fin("Text.txt");
	int n;
	fin >> n;
	int key;
	std::string value;
	for (int i = 0; i < n; i++) {
		fin >> key >> value;
		map.insert(std::make_pair(key, value));
	}
	fin.close();
	int option;
	std::cout << "1. Adaugare element" << std::endl;
	std::cout << "2. Stergere element" << std::endl;
	std::cout << "3. Cautare element" << std::endl;
	std::cout << "4. Afisare elemente" << std::endl;
	std::cout << "0. Iesire" << std::endl;
	do {
		std::cout << "Alege o optiune: ";
		std::cin >> option;
		switch (option) {
		case 1: {
			int key;
			std::string value;
			std::cout << "Introdu cheia: ";
			std::cin >> key;
			std::cout << "Introdu valoarea: ";
			std::cin >> value;
			map.insert(std::make_pair(key, value));
			break;
		}
		case 2: {
			int key;
			std::cout << "Introdu cheia elementului de sters: ";
			std::cin >> key;
			map.remove(key);
			break;
		}
		case 3: {
			int key;
			std::cout << "Introdu cheia elementului de cautat: ";
			std::cin >> key;
			std::string value = map.find(key);
			if (value.empty()) {
				std::cout << "Elementul nu exista" << std::endl;
			}
			else {
				std::cout << "Valoarea elementului este " << value << std::endl;
			}
			break;
		}
		case 4: {
			map.print();
			break;
		}
		case 0:
			break;
		default:
			std::cout << "Optiune invalida" << std::endl;
			break;
		}
	} while (option != 0);
	return 0;
}
