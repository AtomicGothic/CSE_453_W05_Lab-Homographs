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

using namespace std;


/***********************************************************************************
* [TO DO] e should be the path that is possibly encoded. 
* [TO DO] r should be the file handle. In other words, this should be
	 something like ifstream fin.
* [TO DO] have a rendering function. This might be fin.open(e);. In other
	 words, this function turns an encoding into a rendition.
* [TO DO] c should be a canon. What would that canon be? Since we are checking
	 for valid paths, only include english letters, ".", "/" , ":", and
	 "\".
* [TO DO] we need a canonicalization function. Note, we must not use
	 "canonical()" because that's part of the <filesystem> library.
* [TO DO] we need a homograph function that will determine if two encodings are the
	 same.
***********************************************************************************/





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
	if (checkPath() == true)
	{
		cout << "Homograph\n";
	}
	else
	{
		cout << "Non-homograph\n";
	}
}

