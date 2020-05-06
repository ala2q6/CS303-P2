// Alex Arbuckle
// Professor Ahmed Alkinani
// CS303 : Data Structures
// 8 May 2020

#include "bt.h"
#include <iostream>
using namespace std;

int main() {

	bt morseTree; // creating instance of binary tree
	string strVariable; // declaring string for getting input
	queue<char> charQueue; // declaring queue for characters
	queue<string> strQueue; // declaring queue for morse 
	while (true) { // always translate user input

		cout << "Input : ";
		getline(cin, strVariable); // getting sentence to convert

		int i = 0; // declaring and assigning integer for indexing sentence
		char charVariable; // declaring char to hold string index
		while (strVariable[i]) { // while there are characters to iterate

			charVariable = tolower(strVariable[i]); // assigning and making lowercase
			charQueue.push(charVariable); // adding character to queue
			i += 1; // iterating to next character

		}

		strQueue = morseTree.toMorse(charQueue); // translating to and returning morse
		morseTree.toCharacter(strQueue); // using morse to translate from

	}

	return 0;

}