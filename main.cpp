#include <direct.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define GetCurrentDir _getcwd

using namespace std;

std::string canonize(std::string encoding)
{
	 // a pre-determined set list of acceptable characters.
	 std::vector<char> canon{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
										 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
										  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
										  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
										  'w', 'x', 'y', 'z', '.', '<', '>', ':', '\'', '/', '\\',
										  '|', '*', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
										  '!', '@', '#', '$', '%', '^', '&', '(', ')', '-', '_', '=', '+',
										  '`', '~', ',', '[', ']', '{', '}', '\"'};

	 //Loop through each character in the string and check to see if the 
	 //character is contained within the canon. If it isn't in the canon,
	 //print a message to the user.
	 for (int i = 0; i < encoding.size(); i++)
	 {

		auto result = std::find(canon.begin(), canon.end(), encoding[i]);

		if(result == end(canon)){
			std::cout << "There is an invalid character ";
			std::cout << encoding[i];
			std::cout << " at position ";
			std::cout << (i + 1);
			std::cout << endl;
		}

	 }


	 return encoding;
}



/**********************************************************************
 * GetCurrentPath
 * The function which gets current Path
 ***********************************************************************/
std::string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}

/**********************************************************************
 * fullPath
 * The function which checks full path
 ***********************************************************************/
string GetFullPathFromPartial(char* partialPath)
{
	char full[_MAX_PATH];
	if (_fullpath(full, partialPath, _MAX_PATH) != NULL)
	{
		  return full;
	}
	else
	{
		 return "Invalid path\n";
	}
}



/**********************************************************************
 * checkPath
 * The function which checks Path Homograph
 ***********************************************************************/
bool checkPath()
{
	string fName1 = "";
	string fName2 = "";
	string fFullPath1 = "";
	string fFullPath2 = "";

	// Retrieving Full path of file 1
	cin.ignore();
	cout << "File name 1> ";
	std::getline(std::cin, fName1); //changed from simple std::cin to std::getline to allow user to input whitespaces
	fFullPath1= get_current_dir() + "\\" + fName1;


	//Retrieving Full path of file 2
	cout << "File name 2> ";
	std::getline(std::cin, fName2); //changed from simple std::cin to std::getline to allow user to input whitespaces
	char* c = const_cast<char*>(fName2.c_str());
	fFullPath2 = GetFullPathFromPartial(c);

	if (fFullPath1 == fFullPath2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**********************************************************************
 * prompt
 * simple prompt function returning a bool 
 ***********************************************************************/
bool prompt()
{
	char answer = 'q'; // initialized on the off chance that an unitialized variable would be y or n.

	// this while loop makes sure that only y or n is accepted.
	while (tolower(answer) != 'y' && tolower(answer) != 'n')
	{
		 std::cout << "Would you like to do a homograph test? (y/n): ";
		 std::cin >> answer;
	}

	if(tolower(answer) == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	 while (prompt())
	 {
		  if (checkPath() == true)
		  {
				cout << "Homograph\n";
		  }
		  else
		  {
				cout << "Non-homograph\n";
		  }
	 }

}

