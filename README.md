# CSE_453_W05_Lab-Homographs
Lab on Homographs

Path Homograph
****************

One common form of the homograph attack is for the user to attempt to access a forbidden resource. The programmer may attempt to prevent such requests by creating a blacklist of forbidden files. The problem arises when the attacker finds a way to specify the forbidden file that circumvents the blacklist. This is done, of course, with a homograph attack.

Write a program to prompt the user for a file path. Compare this path against a forbidden file such as secret/password.txt. Display whether these two paths are the same or whether they refer to different resources. To do this, research what types of symbols are available on your command shell, demonstrate code that is vulnerable to the homograph attack, and write code that detects path homographs. An example of the program execution might be:

</home/cs453/week05> lab05.out
Specify the first filename:  test.txt
Specify the second filename: ../../cs453/week05/test.txt
The paths are homographs

Path Symbols
*************

There are many ways to specify a path to a given file system resource. Your specific file system (be that Windows, Macintosh, or Linux) provides a rich set of symbols to help with this. Some include slashes (/ for Macintosh and Linux, \ for Windows), single dots (.) to indicate the current directory, and double dot (..) to indicate the previous directory. The first task is to research which path symbols are available on your file system.

The second task is to identify a set of test cases called "Non Homographs" to represent file paths that are similar to but different than the forbidden file. For example, if your system is Linux, your current director is /home/user/cse453/ and the forbidden file is on /home/user/secret/password.txt, then a non homograph file path would be home/user/secret/password.txt. Write a function to compare each of these test cases against the forbidden file to demonstrate that they are different (not homographs). Justify why each test case in the "Non Homographs" set is not equivelent to the forbidden file and why the set of test cases is representative of distinct file paths.

The third task is to identify a set of test cases called "Homographs" to represent file paths that are equivelent to the forbidden file but are different strings. For example, if your current director is /home/user/cse453/ and the forbidden file is on /home/user/secret/password.txt, then an example file path would be ./../secret/password.txt. Write a function to compare each of these test cases against the forbidden file. Justify why each test case in the "Homographs" set is equivelent to the forbidden file and why the set of test cases is representative of equivelent file paths.


Canonicalization
*****************

Create a canonicalization function to convert an encoding (the input path) into some canon. This function will then be used to see if two file paths are homographs of each other. Note that you are not allowed to use the canonical() function available in the <filesystem> library.

Demonstrate that all of the paths in "Non Homographs" are not homographs and that all the paths in "Homographs" are in fact homographs. This demonstration is in the form of program output and descriptive text explaining what the output means. When generating these test cases, it is a good rule of thumb to have 2-3 test cases per construct. For example, have 2-3 test cases to verify that the single-dot "/./" works as you expect.


Hint
*****

When working through this problem, ask yourself six questions: what is e, r, R(), c, C(), and what is H()?

    e: What is the encoding in this scenario?
    r: This can be a bit difficult to figure out, so I will help. The rendition is a file handle. In the case of C++, it would be ifstream fin;. This points to a given resource on the file system.
    R(): This is the rendering function. In the case of our scenario, this might be fin.open(e);. In other words, it turns an encoding into a rendition. Note that we cannot use ifstream for this problem because it treats all paths the same that do not refer to resources on the system. In other words, it would report two non-homographs as the same even when they are obviously different.
    c: This is the canon. You need to identify an appropriate canon.
    C(): The bulk of your work will be to create an appropriate canonicalization function. This should be informed by the functionality of R() but should not use it.
    H(): This is the homograph function. It determines if two encodings are the same. It should leverage the work done in C(). Check the textbook for an idea of what this will look like.

Report
*******

The main deliverable for this lab will be the lab report. This concise, professionally written document will include the code fragments, test cases, the relevant output, a brief description of what is presented, and justification that the code matches the theoretical framework described in the textbook.

This lab report is the most important deliverable. This report should honor all of the guidelines presented in the Scholarly Writing document.
Assignment

There will be one submission constituting all of the work of your team. This submission will include:

    Lab Report: A lab report in PDF format.
    Source Code: All the source code generated for this assignment must be in a single C++ file. By downloading the file and compiling it, it should be possible to execute any of the test cases in the report. A simple menu structure should be provided to facilitate this.
