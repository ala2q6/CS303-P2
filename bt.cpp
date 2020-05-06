#include "bt.h"

bt::bt() { // binary tree default constructor

	int i = 1; // declaring and assigning integer for indexing starting at 1
	string strVariable; // declaring string for pulling lines from morsetable.txt
	ifstream fin("morseTable.txt"); // declaring and assigning file to read
	while (fin.good()) { // while there are lines in the file

		node* ptr = root; // declaring and assigning temporary pointer to root node
		getline(fin, strVariable); // getting entire line from file
		while (strVariable[i]) { // while there are segments to iterate

			if (strVariable[i] == '.') { // if segment is ' . '

				ptr = ptr->left; // assign to go right

			}

			else if (strVariable[i] == '_') { // if segment is ' _ '

				ptr = ptr->right; // assign to go right

			}

			i += 1; // increment to next segment

		}
		
		ptr->morse = strVariable.substr(1, 4); // assigning morse value node with collection of morse segments
		ptr->character = strVariable.at(0); // assigning character value node with first line segment
		i = 1; // assigning indexd back to 1 for next line in file

	}

}

queue<string> bt::toMorse(queue<char>& queueParameter) { // method to ouptut and return translation

	cout << "\ntoMorse : ";

	char charVariable; // declaring to hold character from queueParameter
	queue<string> strQueue; // declaring queue to hold translations
	while (!queueParameter.empty()) { // while there are character to translate

		node* ptr = root; // declaring node and assigning it to root node
		charVariable = queueParameter.front(); // assigning next character from queue
		findMorse(0, ptr, charVariable, strQueue); // finding morse and assigning it to queue by reference
		queueParameter.pop(); // removing character from queue

	}

	return strQueue; // returning queue of morse for later use

}

void bt::findMorse(int i, node* ptr, char charParameter, queue<string>& queueParameter) { // recursive method to find specific morse and add to queue by reference

	if (ptr->character == charParameter) { // if node value character is equal to what we're looking for

		if (charParameter == ' ') { // if it is a space between words

			cout << '\t'; // tab over
			queueParameter.push(" "); // add a space

		}

		cout << ptr->morse << ' '; // output morse
		queueParameter.push(ptr->morse); // add morse string to queue

	}

	if (i == 4) { // if we have reached the end of the tree

		return; // exit

	}

	findMorse(i + 1, ptr->left, charParameter, queueParameter); // branch left
	findMorse(i + 1, ptr->right, charParameter, queueParameter); // branch right
	return; // exit

}

void bt::toCharacter(queue<string> queueParameter) { // method to find character from morse

	cout << "\ntoCharacter : ";

	string strVariable; // declaring string to hold morse string we need to reverse
	while (!queueParameter.empty()) { // while there are morse strings we need to reverse

		node* ptr = root; // declaring and assigning node to root node
		strVariable = queueParameter.front(); // assigning string to current morse
		findCharacter(0, ptr, strVariable); // calling method to find character value given morse
		queueParameter.pop(); // removing addressed morse string

	}

	cout << endl << endl;

}

void bt::findCharacter(int i, node* ptr, string strParameter) { // method to find character given morse

	if (ptr->morse == strParameter) { // if character

		cout << ptr->character; // output character
		return; // exit

	}

	if (i == 4) { // if we branched too far

		return; // exit

	}

	findCharacter(i + 1, ptr->left, strParameter); // branch left
	findCharacter(i + 1, ptr->right, strParameter); // branch right
	return; // exit

}