#include "element.hpp"

Element::Element()
{
	this->id=0;
}	

Element::Element(int newId, string data)
{
	this->id=newId;
	this->data=data;
}

void Element::Rename(string newName)
{
	this->data=newName;
}

void Element::AppendChild(Element* elmt)
{
	if( this->GetInChildren(elmt->id) != NULL )
		cout<<"Element with id "<<elmt->id<<" already exists"<<endl;
	else
		this->child.push_back(elmt);
}

void Element::Show(int depth)
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

Element* Element::GetInChildren(int id)
{
	int numChild=this->child.size();
	for(int i=0; i<numChild; i++)
	{
		if(this->child[i]->id == id)
		{
			return this->child[i];
		}
	}
	return NULL;
}

