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

	Element();
	Element(int newId, string data);

	void Rename(string newName);
	void AppendChild(Element* elmt);
	void Show(int depth=0);
	Element* GetInChildren(int id);
};

