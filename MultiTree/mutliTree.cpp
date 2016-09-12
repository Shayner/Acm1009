#include <string>
#include <sstream>
#include "MultiTree.h"

int main(){
	cout << sizeof(TreeNode) << endl;
	string str;
	TreeNode *root = NULL;
	int count = 1;
	while(getline(cin,str)){
		istringstream istr(str);
		int parent;
		istr >> parent;
		vector<int> branchVal;
		int num;
		while(istr >> num)
			branchVal.push_back(num);
		TreeNode* temp = findNode(root,parent);
		if(count == 1){
			root = temp;
			count = 0;
		}
		BuildTree(temp,branchVal);
		
	}
	printTree(root);
}