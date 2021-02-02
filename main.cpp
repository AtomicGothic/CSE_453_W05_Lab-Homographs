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
#include <string>

using namespace std;







/**********************************************************************
 * GetFile
 * The function which gets the file name
 ***********************************************************************/
const string  GetFile()
{
	// get the fileName
	string fName = "";
	std::cout << "What is the filename? ";
	std::cin >> fName;
	return fName;
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
		//printf("Full path is: %s\n", full);
		return full;
	else
		//printf("Invalid path\n");
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

	//cout << get_current_dir() << "\\" << fName1 << "\n";

	//Retrieving Full path of file 2
	std::string str = fName2;
	char* c = const_cast<char*>(str.c_str());
	//std::cout << c;
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
	
    std::cout << "Hello World!\n";
}

