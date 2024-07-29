#include "Header.h"


#pragma once
class BstNode
{
private:
	BstNode* Rchi;
	BstNode* Lchi;
	string DataM;
	char DataT;
public:
	//setting nullptrs by default
	BstNode() : Rchi(nullptr), Lchi(nullptr), DataM("none"), DataT('n'){}
	
	BstNode(BstNode* Rchi, BstNode* Lchi, string DataM, char DataT) {
		Rchi = nullptr;
		Lchi = nullptr;
		DataM = "none";
		DataT = 'n';
	}
	//aint these two things above do thesame thing? prolly, maybe idk. will change when less lazy

	//copy constructor
	BstNode(const BstNode& t) {
		Rchi = t.Rchi;
		Lchi = t.Lchi;
		DataM = t.DataM;
		DataT = t.DataT;
	}
	
	//deconstructor
	~BstNode();

	//getters/setters
	BstNode* getR() const { return Rchi; }
	BstNode* getL() const { return Lchi; }
	string getDataM() const { return DataM; }
	char getDatat() const { return DataT; }
	void setR(BstNode* ptr) { Rchi = ptr; }
	void setL(BstNode* ptr) { Lchi = ptr; }
	void setDataM(string str) { DataM = str; }
	void setDataT(char chr) { DataT = chr; }

	

};

