#include <iostream>

using namespace std;

class excep {
	private:
		char* ch;
	public:
		excep(char* m=(char*)"exception class...") {
			cout<<this<<": start excep!"<<endl;
			ch = m;
		}
		void print() {
			cerr<<ch<<endl;
		}
};

void err1() {
	cout<<"enter err1"<<endl;
	throw excep((char*)"exception");
}

void err2() {
	try {
		cout<<"enter err2"<<endl;
		err1();
	} catch (int) {
		cerr<<"err2:catch"<<endl;
		throw;
	}
}

void err3() {
	try {
		cout<<"enter err3"<<endl;
		err2();
	} catch (...) {
		cerr<<"err3:catch"<<endl;
		throw;
	}
}

int main(int argc, char** argv) {
	try {
		err3();
	} catch(...) {
		cerr<<"main:catch"<<endl;
	}
	return 0;
}
