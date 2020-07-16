#include <iostream>
#include <vector>
#include "element.hpp"

using namespace std;

int main()
{
	Element ele(0,"Zero");

	cout<<endl<<"~~ Show ~~"<<endl<<endl;
	ele.ShowTree();

	cout<<endl<<"~~ Adding new 13 element ~~"<<endl;
	ele.AppendChild(new Element(13,"Not Thirteen"));

	cout<<endl<<"~~ Adding 3 dummy emelents ~~"<<endl;
	for(int i=0; i<3; i++)
	{
		ele.AppendChild(new Element(i,"Dummy"));
	}

	cout<<endl<<"~~ Modifying data in 13 element ~~"<<endl;
	ele.GetInChildren(13)->setData("Thirteen");

	cout<<endl<<"~~ Show ~~"<<endl;
	ele.ShowTree();

	cout<<endl<<"~~ Appending new element ~~"<<endl;
	ele.AppendChild(new Element(666,"Number of the beast"));

	cout<<endl<<"~~ Show ~~"<<endl;
	ele.ShowTree();

	cout<<endl<<"~~ Adding 420 : \"Blazit\" to 13 ~~"<<endl;
	ele.GetInChildren(13)->AppendChild(new Element(420,"BlazeIt"));

	cout<<endl<<"~~ Adding 4200 : \"Blazzzzit\" to 420 : \"Blazit\" THRICE ~~"<<endl;
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(420,"BlazzzzzIt"));
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(4200,"BlazzzzzIt"));
	// This will not append the child as a child with the same id already exists
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(4200,"BlazzzzzIt"));
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(4202,"BlazzzzzIt"));

	cout<<endl<<"~~ Parent of 0/13/420 ~~"<<endl;
	Element* eblazeit = ele.GetInChildren(13)->GetInChildren(420);
	eblazeit->parent->ShowElement();

	cout<<endl<<"~~ Adding 42 : \"The Answer\" to 13 ~~"<<endl;
	ele.GetInChildren(13)->AppendChild(new Element(42, "The Answer"));

	cout<<endl<<"~~ Show 13 from a.GetInChildren(13) ~~"<<endl;
	ele.GetInChildren(13)->ShowTree();
	
	cout<<endl<<"~~ Parent of id 13 ~~"<<endl;
	ele.GetInChildren(13)->parent->ShowElement();

	cout<<endl<<"~~ Show ~~"<<endl;
	ele.ShowTree();

	return 0;
}
