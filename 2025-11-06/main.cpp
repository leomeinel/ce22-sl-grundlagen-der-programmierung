#include <cstdio>   // Include-Statement, damit std::printf funktioniert.
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <algorithm>
#include <span>
#include <string_view>

namespace views = std::views;

int get_random_value(std::string& s) {
	return 42;
}


int main(int argc, char **argv) {

	std::span<char*> params {argv, argc};
	// span ist wie vector, aber auf "fremdem speicher"

	// string_view ist wie string, aber auf "fremdem speicher"
	for(std::string_view sv : params) {
		std::cout << sv << "\n";
	}

	std::vector<std::string> pi_hosts {
		"192.168.0.100",
		"192.168.0.101",
		"192.168.0.102"
	};

	std::vector<int> zahlen {
		1,2,3,4,5
	};

	std::vector<std::vector<int>> zahlen {
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	};

	std::string s = "Bar";

	// range based for loop
	for(const std::string& s : pi_hosts ) {
		std::cout << s << "\n";
	}
							// initializer list
	for(const std::string& s : { "eins", "zwei", "drei" } ) {
		std::cout << s << "\n";
	}

	// klassischen for loop
	for(int i = 0; (i < 10) && (i < pi_hosts.size()); i++) {
		std::cout << pi_hosts[i] << "\n";
		pi_hosts[i] = "Foo";
	}

	// late 2000s
	//std::vector<std::string>::iterator it;
	for(auto it = pi_hosts.begin(); it != pi_hosts.end(); it++) {
		if (*it == "192.168.0.101") {
			*it = "192.168.1.101";
			break;
		}
	}

	auto it = std::find(pi_hosts.begin(), pi_hosts.end(), "192.168.0.101");
	if (it != pi_hosts.end()) {
		// ich hab den string gefunden!!
		*it = "192.168.1.101";
	}




	//std::printf("Hallo Welt!\n");

	return 0;
}


// Kompilieren in der Kommandozeile mit:
//
//
// 1) ein Unterverzeichnis anlegen, z.B.:
//    mkdir build
//
// 2) in das Unterverzeichnis wechseln
//    cd build
//
// 3) CMake Konfigurationsschritt
//    cmake ..
//
// 4) CMake Compilieren
//    cmake --build ./
//
// jetzt sollte eine ausführbare Datei names my_program entstanden sein


