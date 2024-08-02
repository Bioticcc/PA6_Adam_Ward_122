#ifndef BSTTREEC_H
#define BSTTREEC_H

#include "Header.h"
#include "BstNodeEC.h"


template <class T>
class BstTreeEC {
private:
	string inputName;
	BstNodeEC<T>* root;

public:
	//default constructor, should be opening the file by default? i think? thats what im going for with this at least
	BstTreeEC();


	//just gonna keep it as this for now cause fuck if now tbh >.>

		//doesnt need a copy constructor as of now, cause all im tryna do is read from the file. i think? lmao i dunno ;-; this PA is WEIRD buddy
		//To whoever my TA ends up being, have MERCY on me with this one ong i might be cooked

	BstNodeEC<T>* readTree(string inputName, BstNodeEC<T>* root);
	BstNodeEC<T>* insertToTree(BstNodeEC<T>* root, T text, string morse);
	void makeBST();
	void print(BstNodeEC<T>* root);
	void search(BstNodeEC<T>* root);
	string readInput(string inputName);
	string sift(BstNodeEC<T>* root, char target);
	void sendRoot(BstNodeEC<T>* rootPtr) {
		root = rootPtr;
	}
	BstNodeEC<T>* getRoot() {
		return root;
	}	
	int deleteTree(BstNodeEC<T>* root);


	~BstTreeEC() { deleteTree(root); }
};


#endif

