/*----------------------------------------------------------------------------------
@Judog24

Purpose: A program that reads a string of letters, digits or underscores and
determines whether it is an identifier in C++
----------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

void checkIdentifierValidity (string ident);

int main()
{
	//declare identifiers
	string name; 
	char decision;
	
	do
	{
		cout<<"\tEnter a string: "; getline(cin, name, '\n');
		checkIdentifierValidity(name);
		cout<<"CONTINUE(y/n)? "; cin>>decision;
		decision = tolower(decision); cin.ignore();
	} while (decision == 'y');

	//terminate program
	system("pause");
	return 0;
}

//Checks if the given string is an identifier in C++
void checkIdentifierValidity (string ident)
{
	//declare identifers
	bool pass; 
	char letter, first;
	for(int i=0; i<ident.length(); i++)
	{
		letter = ident[i]; first = ident[0];
		//Not an identifier if: begins with digit, has a space or special character
		if(isdigit(first)||isspace(letter)||(!isalnum(letter)&&(letter != '_')))
		{ pass = false; break; }
		//Is an identifier if it begins with letters or an underscore
		if(isalpha(letter)||'_')
		{ pass = true; }
	}
	if (pass == true)
	{ cout<<'\t'<<ident<<" is an identifier\n"; }
	else { cout<<'\t'<<ident<<" is not an identifier\n"; }
}

/*---------------------------OUTPUT---------------------------------------
        Enter a string: ab_23
        ab_23 is an identifier
CONTINUE(y/n)? y
        Enter a string: top Gun
        top Gun is not an identifier
CONTINUE(y/n)? y
        Enter a string: AB_23
        AB_23 is an identifier
CONTINUE(y/n)? y
        Enter a string: _ab_23
        _ab_23 is an identifier
CONTINUE(y/n)? y
        Enter a string: 23_ab
        23_ab is not an identifier
CONTINUE(y/n)? y
        Enter a string: ab*&23
        ab*&23 is not an identifier
CONTINUE(y/n)? n
Press any key to continue . . .
------------------------------------------------------------------------*/