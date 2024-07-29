#include "BstTree.h"
#include "BstNode.h"

int BstTree::readTree(string& inputName){
	//initializing BstNode? i guess? seems i need to do that here 
	BstNode Node;

	std::ifstream input;
	input.open(inputName, std::ios::in);
	//reading in a line from the .txt
	string line;
	std::getline(input, line);
	//now i gotta split the line at the " " and put the first half in BstNode.DataT and etc
	//using isstringstream can apparantly do this way easier then strtok(), so imma go with that!
	std::istringstream parse(line);
	//im TRYING to set this parse stuff equal to parse >> DataT >> DataM, but for some reason it aint registering that those exist here??? idunno
	char text;
	string morse;
	parse >> text >> morse;
	Node.setDataT(text);
	Node.setDataM(morse);
	//alrighty, ive got a semblence of a node. What now? This first one is the root, but how do i put these in afterwards?
	//do i just alternate? was that the point of balancing the library? what about the Rchi and Lchi? what do i do with those?
	//a problem for tommorow me, i think my brain hurts enough as it is >.> anywho im gonna start logging the dates and times as well
	//because why not it will look cooler. 
	//Lots of progress made today! 7/29/2024 - 10:06 AM





}

