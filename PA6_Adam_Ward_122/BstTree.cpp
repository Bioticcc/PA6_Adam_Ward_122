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

	//goDAMN this is a work of art this is my favorite function of this PA. BEHOLD, the all mighty Sift! 
	//It bassically does the same thing as my print funciton, except I changed around things, and added a few more if statements!
	//It goes back and forth through the entire tree, except now instead of printing when EVERYTHING it finds, it insteads specifically only
	//returns when it finds the target character. (in upper case because morseLibrary.txt is all upper, or reaches the end of the tree
	//without finding anything!
	//dunno why it makes me so hype, but lordy this IS the magnum opus of PA6 imo. Its even got a cool ass name: "Sift" god i love it


	if (!root) {
		return "Sift Failed";
	}


	string str = sift(root->Lchi, target);
	if (str != "Sift Failed") {
		return str;
	}

	if (root->DataT == toupper(target)) {
		//cout << "found!" << root->DataT << ":";
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


string BstTree::readInput(string inputName) {
	std::ifstream input;
	input.open(inputName, std::ios::in);
	string text;
	string test1;
	test1.append("\n");

	while (!input.eof()) {
		std::getline(input, text);
		test1.append(text);
		test1.append("\n");
	}
	
	//text.append("test"); //its not actually saving the lines I read from input to text?? am i doin some thing wrong... :/
	//ahah, so the issue was text is wiped and reset everytime its called, and the last time its called is on an empty line
	//causing it to essentially return an EMPTY line of text, so yeah no shit it aint gon work lol ;3

	cout << test1;
	input.close();
	return test1;
}



void BstTree::search(BstNode* root) {
	string input;	
	input = readInput("Convert.txt");
	//string input;
	string translation;

	//ALright, well APPARANTLY this is meant to be translated from a .txt document I guess, so fml ig 
	//(kidding its super easy to make it read from .txt, but still hilariously aggravating) T^T
	
	//cout << "Enter sentence/word to be translated: ";
	//cin >> input; //apparantly this only reads up to the first whitespace character! WISH I KNEW THAT SOONER LMAO (>.>)
	//input.erase(1, 1); //not needed turns out you CAN just treat it like an array in C lmao
	//getline(std::cin, input);

	int j = input.length();
	for (int i = 0; i < j; i++) {
		//	cout << input[i] << ": ";
			/*
			string test = sift(root, input[i]);
			cout << test << "\n";
			cout << sift(root, input[i]) << "\n";
			*/
		char check1 = ' ';
		char check2 = '\n';
		if (input[i] != check1 && input[i]!=check2) {
			translation.append(sift(root, input[i]));
			translation.append(" ");

		}
		else if(input[i] == check1){
			translation.append("   ");
		}
		else if (input[i] == check2) {
			translation.append("\n");
		}
	}
	cout << "Translated string:\n" << translation;

}





