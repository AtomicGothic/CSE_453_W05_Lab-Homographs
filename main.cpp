#include <direct.h>
#define GetCurrentDir _getcwd


//#ifdef WINDOWS
//#include <direct.h>
//#define GetCurrentDir _getcwd
//#else
//#include <unistd.h>
//#define GetCurrentDir getcwd
//#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/***********************************************************************************
* [TO DO] e should be the path that is possibly encoded. 
* [TO DO] r should be the file handle. In other words, this should be
	 something like ifstream fin.
* [TO DO] have a rendering function. This might be fin.open(e);. In other
	 words, this function turns an encoding into a rendition.
* [DONE] c should be a canon. What would that canon be? Since we are checking
	 for valid paths, only include english letters, ".", "/" , ":", and
	 "\", etc.
* [TO DO] we need a canonicalization function. Note, we must not use
	 "canonical()" because that's part of the <filesystem> library.
* [TO DO] we need a homograph function that will determine if two encodings are the
	 same.
***********************************************************************************/



std::string canonize(std::string encoding)
{
		 	 // possibly could use a pre-determined set list of acceptable characters.
	 std::vector<char> canon{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
										 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
										  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
										  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
										  'w', 'x', 'y', 'z', '.', '<', '>', ':', '\'', '/', '\\',
										  '|', '*', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
										  '!', '@', '#', '$', '%', '^', '&', '(', ')', '-', '_', '=', '+',
										  '`', '~', ',', '[', ']', '{', '}', '\"'};

//	 std::string scrubbedEncoding;
	 
	 // iterate through every element of the encoding and make sure
	 // each character is lower case and then fill the scrubbed string.

	 //Loop through each character in the string and check to see if the 
	 //character is contained within the canon. If it isn't in the canon,
	 //print a message to the user.
	 for (int i = 0; i < encoding.size(); i++)
	 {
//		  scrubbedEncoding.push_back(tolower(encoding[i]));


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
		return full;
	else
		return "Invalid path\n";
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

	cout << "File name 1> ";
	cin >> fName1;
	cout << "File name 2> ";
	cin >> fName2;

	// Retrieving Full path of file 1
	fFullPath1= get_current_dir() + "\\" + fName1;

	//Retrieving Full path of file 2
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


int main()
{
	 std::string temp = "";
	 std::cout << "Enter test text: ";
	 std::getline(std::cin, temp);
	 std::cout << canonize(temp);

	/*if (checkPath() == true)
	{
		cout << "Homograph\n";
	}
	else
	{
		cout << "Non-homograph\n";
	}*/
}

