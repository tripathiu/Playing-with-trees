#include <iostream>
#include <vector>

using namespace std;

class Element
{
	public:
	int id;
	string data;
	vector<Element*> child;

	Element()
	{
		this->id=0;
	}	

	Element(int newId, string data)
	{
		this->id=newId;
		this->data=data;
	}

	void AppendChild(Element* elmt)
	{
		this->child.push_back(elmt);
	}

	void Show(int depth=0)
	{
		int numChild=this->child.size();
		cout << this->id  << " : " << this->data << endl;
		for(int i=0; i<numChild; i++)
		{
			for(int j=0; j<=depth; j++) cout<<"--";
			cout<<" ";
			this->child[i]->Show(depth+1);
		}
	}

	Element* GetInChildren(int id)
	{
		int numChild=this->child.size();
		for(int i=0; i<numChild; i++)
		{
			if(this->child[i]->id == id)
			{
				return this->child[i];
			}
		}
		cout<<"Not found ID: "<<id<<endl<<"Exiting"<<endl;
		exit(1);
		return NULL;
	}
};

int main()
{
	Element ele(0,"Zero");

	cout<<endl<<"~~ Show ~~"<<endl<<endl;
	ele.Show();

	cout<<endl<<"~~ Adding new 13 element ~~"<<endl;
	ele.AppendChild(new Element(13,"Not Thirteen"));

	cout<<endl<<"~~ Adding 3 dummy emelents ~~"<<endl;
	for(int i=0; i<3; i++)
	{
		ele.AppendChild(new Element(i,"Dummy"));
	}

	cout<<endl<<"~~ Modifying data in 13 element ~~"<<endl;
	ele.GetInChildren(13)->data="Thirteen";

	cout<<endl<<"~~ Show ~~"<<endl;
	ele.Show();

	cout<<endl<<"~~ Appending new element ~~"<<endl;
	ele.AppendChild(new Element(666,"Number of the beast"));

	cout<<endl<<"~~ Show ~~"<<endl;
	ele.Show();

	cout<<endl<<"~~ Adding 420 : \"Blazit\" to 13 ~~"<<endl;
	ele.GetInChildren(13)->AppendChild(new Element(420,"BlazeIt"));

	cout<<endl<<"~~ Adding 42 : \"The Answer\" to 13 ~~"<<endl;
	ele.GetInChildren(13)->AppendChild(new Element(42, "The Answer"));

	cout<<endl<<"~~ Show 13 from a.GetInChildren(13) ~~"<<endl;
	ele.GetInChildren(13)->Show();
	
	cout<<endl<<"~~ Show ~~"<<endl;
	ele.Show();

	return 0;
}
