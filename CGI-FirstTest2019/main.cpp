#include <iostream>
#include <fstream>
using namespace std;

void show_form();

void main()
{
	cout << "Content-type: text/html; charset=windows1251\n\n";

	ifstream f("index.tmplt");
	if (f.is_open())
	{
		char* ln = new char[1024];
		while (!f.eof())
		{
			f.getline(ln, 1024);
			if (strcmp(ln, "<!--maincontent-->")==0)
			{
				show_form();
			} else
				cout << ln;
		}
		delete[] ln;
		f.close();
	}
	
}

void show_form()
{
	cout << "<form action=\"index.cgi\" method=\"GET\">";
	cout << "���� ���: <input type=\"text\" name=\"first_name\" placeholder=\"������� ���� ���� ���\">";
	cout << "<br>";
	cout << "���� ��������: <input type=\"date\" name=\"birth\">";
	cout << "<br>";
	cout << "<input type=\"submit\" value=\"�������\">";
	cout << "</form>";
}