//Huffman Code
#include <bits/stdc++.h>
using namespace std;

// To store the frequency of character of the input data
map<char, int> frequency;

// To store character and huffman code assigned to each character.
map<char, string> code;

// A Huffman tree node
struct MinHeapNode
{
	char ele;
	int freq;
	MinHeapNode *left, *right;

	MinHeapNode(char ele, int freq)
	{
		left = right = NULL;
		this->ele = ele;
		this->freq = freq;
	}
};

// Function which tells how elements should be arranged in the priority queue
//i.e. on the basis of frequency.
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

//Function to print character with their codes.
void printCode(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCode(root->left, str + "0");
	printCode(root->right, str + "1");
}

//To store characters and their code in a hash table.
void storeCode(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		code[root->data]=str;
	storeCode(root->left, str + "0");
	storeCode(root->right, str + "1");
}

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> pq;

// To build Huffman Tree
void Huffman(int size)
{
	struct MinHeapNode *left, *right, *temp;
    map<char,int> :: iterator it=frequency.begin();
    while(it!=frequency.end()){
        pq.push(new MinheapNode(it->first,it->second));
        it++;
    }

	while (pq.size() != 1)
	{
		left = pq.top();
		pq.pop();
		right = pq.top();
		pq.pop();
		temp = new MinHeapNode('$', left->freq + right->freq);
		temp->left = left;
		temp->right = right;
		pq.push(temp);
	}
	storeCode(pq.top(), "");
}

//To decode the encoded string
string decode(struct MinHeapNode* root, string str)
{
    string out = "";

    struct MinHeapNode* curr = root;
    for (int i=0;i<str.size();i++){
       if (str[i] == '0'){
           //if current bit is 0 move to the left node.
           curr = curr->left;
       }else{
           //if current bit is 1 move to the right node.
           curr = curr->right;
       }

        //leaf node is encountered
        if (curr->left==NULL and curr->right==NULL){
            out += curr->data;
            curr = root;
        }
    }
    return out+'\0';
}


int main()
{
	string str = "opengenus";
	string s1,s2;

	for (int i=0; i<str.size(); i++){
		frequency[str[i]]++;
    }

	Huffman(str.length());
	cout << "Character With there Huffman codes:"<<endl;
    map<char,string> ::iterator it=code.begin();
	while(it!=code.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

	for(int i=0;i<str.size();i++){
        s1=s1+code[str[i]];
    }

	cout << "Encoded Huffman data:" << s1 << endl;

	s2 = decode(pq.top(),s1);
	cout << "Decoded Huffman Data:" << s2 << endl;
	return 0;

}
