#include <iostream>
#include <string>

using namespace std;

string verschluesseln(string wort, char tabelle[2][26]);
string entschluesseln(string wort, char tabelle[2][26]);


int main() {
	string wort;
	char tabelle[2][26]= {{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
			              {'L','M','N','O','P','Q','R','S','T','A','B','C','D','E','F','G','H','I','J','K','U','V','W','X','Z','Y'}};
	cout << "Lookup-Tabelle: " << endl;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 26; j++) {
			cout << tabelle[i][j] << "\t";
		}
		cout << "\n" << endl;
	}

	cout << "Geben Sie ein Wort in Großbuchstaben ein: ";
	cin >> wort;
	string verschluesselt = verschluesseln(wort, tabelle);
	cout << "Das Wort " << wort << " wurde in " << verschluesselt << " verschlüsselt.";

	string entschluesselt = entschluesseln(verschluesselt, tabelle);
	cout << "\nEntschluesselt: " << entschluesselt << endl;
	return 0;
}

string verschluesseln(string wort, char tabelle[2][26]){
	string verschluesselt;
	for (int i = 0; i < wort.length(); ++i) {
		for (int j = 0; j < 26; ++j) {
			if (wort[i] == tabelle[0][j]){
				verschluesselt += tabelle[1][j];
				break;
			}
		}

	}
   return verschluesselt;
}

string entschluesseln(string wort, char tabelle[2][26]){
	string entschluesselt;
	for (int i = 0; i < wort.length(); ++i) {
		for (int j = 0; j < 26; ++j) {
			if (wort[i] == tabelle[1][j]){
				entschluesselt += tabelle[0][j];
				break;
			}
		}

	}
   return entschluesselt;
}
