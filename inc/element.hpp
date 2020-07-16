#include<iostream>
#include<vector>

using namespace std;

class Element
{
	private:
	int id;
	string data;

	public:
	vector<Element*> child;
	Element* parent;

	Element();
	Element(int newId, string data);

	void AppendChild(Element* elmt);
	void ShowTree(int depth=0); // Recursively show tree
	void ShowElement(); // Show just the element
	Element* GetInChildren(int id);

	int getId();
	string getData();
	void setId(int id);
	void setData(string data);
};

