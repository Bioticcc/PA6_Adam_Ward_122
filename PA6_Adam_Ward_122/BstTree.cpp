#include "BstTree.h"
#include "BstNode.h"

BstNode* BstTree::insertToTree(BstNode* root, char text, string morse) {
	//essentially this versions head ptr: root

	if (root == nullptr) {
		//means its the initial root, so 'M'? i think? bababooey cause hell if i know tbh
		return new BstNode(text, morse);
		//so new is C++'s version of malloc it seems
	}
	if (text < root->DataT) {
		//recursive shenanigans
		root->Lchi = insertToTree(root->Lchi, text, morse);
	}
	if (text > root->DataT) {
		root->Rchi = insertToTree(root->Rchi, text, morse);
	}
	return root;
}


BstNode* BstTree::readTree(string inputName, BstNode* root){
//initializing BstNode? i guess? seems i need to do that here //nevermind we do it the way we did all the linked lists previously bassically

	std::ifstream input;
	input.open(inputName, std::ios::in);
	//reading in a line from the .txt
	string line;


	while (!input.eof()) {
		std::getline(input, line);
		//now i gotta split the line at the " " and put the first half in BstNode.DataT and etc
		//using isstringstream can apparantly do this way easier then strtok(), so imma go with that!

		std::istringstream parse(line);
		char text;
		string morse;
		parse >> text >> morse;

		//alrighty, ive got a semblence of a node. What now? This first one is the root, but how do i put these in afterwards?
		//do i just alternate? was that the point of balancing the library? what about the Rchi and Lchi? what do i do with those?
		//a problem for tommorow me, i think my brain hurts enough as it is >.>
		// 
		// 
		//Well well well i was overthinking this like a lot. Turns out, much like any other linked list (whitch this is essentially a really weird version of),
		//I just make a insert function, then read in the file and insert what ive read into said linked list using the insert function. lot less confusing
		//then i initially thought! yippee ;3
		root = insertToTree(root, text, morse);
	}
	input.close();
	return root;
}


void BstTree::print(BstNode* root) {
	//root = getRoot();
	if (!root) return;
	print(root->Lchi);
	cout << "(" << root->DataT << " | " << root->DataM << ")\n";
	print(root->Rchi);
}

string BstTree::sift(BstNode* root, char target) {
	if (!root) {
		return "Sift Failed";
	}


	string str = sift(root->Lchi, target);
	if (str != "Sift Failed") {
		return str;
	}

	if (root->DataT == toupper(target)) {
		cout << "found!" << root->DataT << ":" << root->DataM;
		return root->DataM;
	}

	str = sift(root->Rchi, target);
	if (str != "Sift Failed") {
		return str;
	}

	return "Sift Failed";
}



void BstTree::makeBST() {
	BstNode* root = nullptr;
	root = readTree("morseLibrary.txt", root);
	sendRoot(root);
	//showTree(root); //assignment wants me to do this seperately i guess, so bah humbug spose ill move it
}

void BstTree::search(BstNode* root) {
	string input;
	string translation;
	char inputC = '.';
	cout << "Enter sentence/word to be translated: ";
	cin >> input;
	//input.erase(1, 1); //not needed turns out you CAN just treat it like an array in C lmao
	int j = input.length();
	for (int i = 0; i < j; i++) {
	//	cout << input[i] << ": ";
		cout << sift(root, input[i]) << "\n";
	}


}


