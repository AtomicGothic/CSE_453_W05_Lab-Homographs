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
		cout << "Nonhomograph\n";
	}
		
	
    std::cout << "Hello World!\n";
}

