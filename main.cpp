#include <iostream>
#include <algorithm>
#include <vector>
#include "element.hpp"

using namespace std;

bool isNumber(const std::string& s)
{
	return !s.empty() &&
		find_if(s.begin(), s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}

int main()
{
	Element ele(0,"Zero");

	ele.AppendChild(new Element(13,"Not Thirteen"));
	for(int i=0; i<3; i++)
	{
		ele.AppendChild(new Element(i,"Dummy"));
	}
	ele.GetInChildren(13)->setData("Thirteen");
	ele.AppendChild(new Element(666,"Number of the beast"));
	ele.GetInChildren(13)->AppendChild(new Element(420,"BlazeIt"));
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(420,"BlazzzzzIt"));
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(4200,"BlazzzzzIt"));
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(4200,"BlazzzzzIt"));
	ele.GetInChildren(13)->GetInChildren(420)->AppendChild(new Element(4202,"BlazzzzzIt"));
	ele.GetInChildren(13)->AppendChild(new Element(42, "The Answer"));
	ele.ShowTree();

	cout << endl <<
	"Avalilable commands are:"	<<endl<<
	"pwd," 				<<endl<<
	"ls,"				<<endl<<
	"cd [parent|<node id>],"	<<endl<<
	"touch <node id> <node data>"	<<endl<<
	"exit"<<endl<<endl;

	string cmd;
	string token;
	string delimiter=" ";
	Element* curEle;
	curEle = &ele;

	while(1)
	{
		cout<<endl<<"> ";
		getline(cin,cmd);
		token = cmd.substr(0, cmd.find(delimiter));
		if( token == "ls")
		{
			curEle->ShowTree();
		}
		if( token == "pwd")
		{
			curEle->ShowElement();
		}
		if( token == "exit")
		{
			exit(0);
		}
		if (token == "cd")
		{
			cmd.erase(0, cmd.find(delimiter) + delimiter.length());
			token = cmd.substr(0, cmd.find(delimiter));
			if (isNumber(token))
			{
				if ( curEle->GetInChildren(stoi(token)) != NULL )
					curEle = curEle->GetInChildren(stoi(token));
				else
					cout<<"Node does not exist"<<endl;
			}
			else if (token == "..")
				curEle = curEle->parent;
			curEle->ShowElement();
		}
		if (token == "touch")
		{
			cmd.erase(0, cmd.find(delimiter) + delimiter.length());
			token = cmd.substr(0, cmd.find(delimiter));
			cmd.erase(0, cmd.find(delimiter) + delimiter.length());
			if (isNumber(token))
			{
				if ( curEle->GetInChildren(stoi(token)) == NULL )
				{
					curEle->AppendChild(new Element(stoi(token),cmd.substr(0, cmd.find(delimiter))));
				}
				else
					cout<<"Node "<<stoi(token)<<" exists"<<endl;
			}
			curEle->ShowElement();
		}
	}


	return 0;
}
