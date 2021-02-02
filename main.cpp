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

std::string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}

/**********************************************************************
 * checkPath
 * The function which checks Path Homograph
 ***********************************************************************/
bool checkPath()
{
	string fName1 = "";
	string fName2 = "";

	cout << "File name 1> ";
	cin >> fName1;
	cout << "File name 2> ";
	cin >> fName2;

	cout << get_current_dir() << "\\" << fName1 << "\n";

	return true;
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

