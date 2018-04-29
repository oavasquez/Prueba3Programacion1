// color your text in Windows console mode

#include <iostream>
#include <windows.h>   // WinApi header
#include <string>
#include <regex>
#include <stdio.h>
#include <ctype.h>

using namespace std;
// std::cout, std::cin

void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

std::vector<std::string> explode(std::string const & s, char delim) {
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim);) {
		result.push_back(std::move(token));
	}

	return result;
}

int main() {

	string cadena, palabra;
	bool palabraUsada = false;
	string continuar;
	while (continuar != "q") {
		SetColor(15);
		cout << "Ingrese el parrafo o la linea ";

		getline(cin, cadena);

		if (cadena.length() <= 1000) {
			cout << endl << endl << "Ingrese la palabra a buscar ";
			getline(cin, palabra);
			cout << endl << endl;

			vector<string> vector = explode(cadena, ' ');

			//for (auto i = v.begin(); i != v.end(); ++i)
			//	std::cout << *i << endl;

			for (size_t i = 0; i < vector.size(); i++) {
				palabraUsada = false;

				if (palabra.compare(vector[i]) == 0) {
					//cout<<"son iguales";
					SetColor(10);
					cout << vector[i] << "";
					SetColor(15);
					palabraUsada = true;

				} else {

					string s("subject");
					regex e("(.*)(" + palabra + ")(.*)");

					cmatch cm;    // same as match_results<const char*> cm;

					// using explicit flags:
					regex_match(const_cast<char*>(vector[i].c_str()), cm, e,
							regex_constants::match_default);

					//cout << "the matches were: "<<endl;
					for (unsigned i = 1; i < cm.size(); ++i) {
						if (palabra.compare(cm[i]) == 0) {

							SetColor(10);
							cout << cm[i];
							SetColor(15);

							palabraUsada = true;
						} else {
							cout << cm[i];
						}
					}
					cout << " ";
				}

				if (!palabraUsada) {
					SetColor(15);

					cout << vector[i] << "";
					palabraUsada = false;
				}
			}

			cout << endl << endl
					<< "presione para continuar o tecle \"q\" salir ";
			getline(cin, continuar);

		} else {
			cout << endl << "su cadena excede el limite de 1000 carateres";
			cin.get();
		}

		return 0;
	}
}

