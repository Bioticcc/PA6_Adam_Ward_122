#include "Header.h"
#include "BstNode.h"
#include "BstTree.h"

int main(void){
	
	BstTree BST;
	BstNode* root = BST.getRoot();
	BST.print(root);
	BST.search(root);

	
}
