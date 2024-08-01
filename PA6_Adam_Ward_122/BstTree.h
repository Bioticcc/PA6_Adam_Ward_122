#ifndef BSTTREE_H
#define BSTTREE_H


#include "Header.h"
#include "BstNode.h"

class BstTree
{
private:
	string inputName;
	BstNode* root;

public:
	//default constructor, should be opening the file by default? i think? thats what im going for with this at least
	BstTree() : inputName("morseLibrary.txt") { makeBST(); }
	
	
//just gonna keep it as this for now cause fuck if now tbh >.>

	//doesnt need a copy constructor as of now, cause all im tryna do is read from the file. i think? lmao i dunno ;-; this PA is WEIRD buddy
	//To whoever my TA ends up being, have MERCY on me with this one ong i might be cooked

	BstNode* readTree(string inputName, BstNode* root);
	BstNode* insertToTree(BstNode* root, char text, string morse);
	void makeBST();
	void print(BstNode* root);
	void search(BstNode* root);
	string readInput(string inputName);
	string sift(BstNode* root, char target);
	void sendRoot(BstNode* rootPtr) {
		root = rootPtr;
	}
	BstNode* getRoot() {
		return root;
	}



};


#endif BSTTREE_H
