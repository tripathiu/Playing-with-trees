#include "element.hpp"

Element::Element()
{
	this->id=0;
	//self is parent
	this->parent=this;
}	

Element::Element(int newId, string data)
{
	this->id=newId;
	this->data=data;
	this->parent=this;
}

void Element::AppendChild(Element* elmt)
{
	if( this->GetInChildren(elmt->id) != NULL )
		cout<<"Element with id "<<elmt->id<<" already exists"<<endl;
	else
		this->child.push_back(elmt);
		this->GetInChildren(elmt->id)->parent=this;
}

void Element::ShowElement()
{
	cout << this->id  << " : " << this->data << endl;
}

void Element::ShowTree(int depth)
{
	int numChild=this->child.size();
	this->ShowElement();
	for(int i=0; i<numChild; i++)
	{
		for(int j=0; j<=depth; j++) cout<<"--";
		cout<<" ";
		this->child[i]->ShowTree(depth+1);
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

int Element::getId()
{
	return this->id;
}

string Element::getData()
{
	return this->data;
}

void Element::setId(int id)
{
	this->id = id;
}

void Element::setData(string data)
{
	this->data = data;
}
