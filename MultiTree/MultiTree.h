#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef struct TreeNode{
	int val;
	int branch;
	//TreeNode *left;
	//TreeNode *right;
	TreeNode* next[];
	TreeNode(int num):val(num),branch(0){
		next[0] = NULL;
	}
};
//�ҵ�Ҫ����Ľڵ�
TreeNode* findNode(TreeNode* root,int num){
	if(root == NULL)
		return new TreeNode(num);
	queue<TreeNode*> record;
	record.push(root);
	while(!record.empty()){
		TreeNode* temp = record.front();
		record.pop();
		if(temp->val == num) return temp;
		int branch = temp->branch;
		for(int i = 0; i < branch; i++)
			record.push(temp->next[i]);
	}
	return NULL;
}

//���������
//����1��ΪҪ����ĸ��ڵ�
//����2��Ϊ�����Ľڵ�ֵ
void BuildTree(TreeNode* root,vector<int> nums){
	int branch = nums.size();
	int preBranch = root->branch;
	root->branch += branch;
	TreeNode* temp = NULL;
	for(int i = preBranch; i < branch; i++){
		temp = new TreeNode(nums[i]);
		root->next[i] = temp;
	}
}

void printTree(TreeNode* root){
	if(root == NULL)
		cout << "empty tree";
	queue<TreeNode*> record;
	int count = 1;
	record.push(root);
	while(!record.empty()){
		TreeNode* temp = record.front();
		record.pop();
		count--;
		cout << temp->val << "  ";
		int num = temp->branch;
		for(int i = 0; i < num; i++){
			record.push(temp->next[i]);
		}
		if(count == 0){
			cout << endl;
			count = record.size();
		}
	}
}