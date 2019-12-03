#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream ou, in;
	ou.open("a.dat",ios::out);
	ou<<"on fact"<<endl;
	ou<<"operating file "<<endl;
	ou<<"is the same as Inputing/outputing data on screen..."<<endl;
	ou.close();
	char buffer[80];
	in.open("a.dat",ios::in);
	while (!in.eof()) {
		in.getline(buffer,80);
		cout<<buffer<<endl;
	}
	in.close();
	return 0;
}
