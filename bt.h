#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

class bt { // class binary tree acronym

	private:

		struct node { // strcture node 

			node* left; // declaring node left
			node* right; // declaring node right
			string morse; // declaring string to hold morse identity
			char character; // declaring string to hold character identity

		};

		struct node* create(int i) { // strcuture to create binary tree iteratively

			while (i != 0) { // iterate recursively i times

				node* root = new node(); // create new node n

				root->left = create(i - 1); // branching left
				root->right = create(i - 1); // branching right

				return root; // returning node value

			}

		};

		node* root = create(5); // creating empty unordered binary tree with depth 4

	public:

		bt(); // default constructor

		queue<string> toMorse(queue<char>& queueParameter); // translating and returning morse
		void findMorse(int i, node* ptr, char charParameter, queue<string>& queueParameter); // finding morse in unordered binary tree

		void toCharacter(queue<string> queueParameter); // translating back to characters
		void findCharacter(int i, node* ptr, string strParameter); // finding character in unordered binary tree

};