#include "Header.h"
#include "BstNode.h"
#include "BstTree.h"
#include "BstTreeEC.h"
#include "BstNodeEC.h"

int main(void){
	
	BstTree BST;
	BstNode* root = BST.getRoot();
	BST.print(root);
	BST.search(root);
	BST.~BstTree();


	//class template thing for extra credit:
	const string test = "test";

	BstNodeEC<void> BstNode('T', test); //does this count? i think it does? idk tbh wasnt very specific. imma do the same for BstTree as well.
	BstTreeEC<void> BstTree();  //well, this is certainly a template for a morse code BST reader, but dunno if thats what is wanted
								//In any case, its extra credit so i dont care that much, check BstTreeEC.h, BstNodeEC.h, and BstTreeEC.cpp for code

	//finished 8/1/2024! fun ;3

	return 0;
	
}
