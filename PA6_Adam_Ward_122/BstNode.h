
#ifndef BSTNODE_H
#define BSTNODE_H

#include "Header.h"

#pragma once
class BstNode
{
private:
	
public:
	BstNode* Rchi;
	BstNode* Lchi;
	string DataM;
	char DataT;
	//setting nullptrs by default
	BstNode() : Rchi(nullptr), Lchi(nullptr), DataM("none"), DataT('.') {}

	BstNode(char text, string& morse) : Rchi(nullptr), Lchi(nullptr), DataM(morse), DataT(text){}
	
	/*
	BstNode(BstNode* rightP, BstNode* leftP, string dataM, char dataT)
		: Rchi(rightP), Lchi(leftP), DataM(dataM), DataT(dataT) {}
		*/
	//aint these two things above do thesame thing? prolly, maybe idk. will change when less lazy

	//copy constructor
	BstNode(const BstNode& t) {
		Rchi = t.Rchi;
		Lchi = t.Lchi;
		DataM = t.DataM;
		DataT = t.DataT;
	}
	
	//deconstructor
	~BstNode() {}

	//getters/setters
	BstNode* getR() const { return Rchi; }
	BstNode* getL() const { return Lchi; }
	string getDataM() const { return DataM; }
	char getDataT() const { return DataT; }

	void setR(BstNode* ptr) { Rchi = ptr; }
	void setL(BstNode* ptr) { Lchi = ptr; }
	void setDataM(string& str) { DataM = str; }
	void setDataT(char chr) { DataT = chr; }
};


#endif BSTNODE_H
