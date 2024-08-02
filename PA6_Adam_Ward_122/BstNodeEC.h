
#ifndef BSTNODEEC_H
#define BSTNODEEC_H
#include "Header.h"


//trying the template thing for extra credit
template <class T>
class BstNodeEC {
private:
	//nothin here cause i put everything in public 
public:
	T* Rchi;
	T* Lchi;
	string DataM;
	char DataT;

	BstNodeEC() : Rchi(nullptr), Lchi(nullptr), DataM("none"), DataT('.') {}
	BstNodeEC(char text, string morse) : Rchi(nullptr), Lchi(nullptr), DataM(morse), DataT(text) {}

	//copy constructor
	BstNodeEC(const BstNodeEC& t) {
		Rchi = t.Rchi;
		Lchi = t.Lchi;
		DataM = t.DataM;
		DataT = t.DataT;
	}

	//deconstructor
	~BstNodeEC() {}

	//getters/setters
	BstNodeEC* getR() const { return Rchi; }
	BstNodeEC* getL() const { return Lchi; }
	string getDataM() const { return DataM; }
	char getDataT() const { return DataT; }

	void setR(BstNodeEC* ptr) { Rchi = ptr; }
	void setL(BstNodeEC* ptr) { Lchi = ptr; }

	void setDataM(string& str) { DataM = str; }
	void setDataT(char chr) { DataT = chr; }
};

#endif