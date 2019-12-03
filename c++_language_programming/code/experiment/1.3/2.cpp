#include <iostream>

using namespace std;

void err(int t) {
	try {
		if (t>100) {
			throw (char*)"biger than 100";
		} else if (t<-100) {
			throw t;
		} else {
			cout<<"t in right range..."<<endl;
		}
	} catch (int x) {
		cout<<"error---"<<x<<endl;
	} catch (char *s) {
		cout<<"error---"<<s<<endl;
	} catch (float f) {
		cout<<"error---"<<f<<endl;
	}
}

int main(int argc, char** argv) {
	err(200);
	err(99);
	err(-1220);
	return 0;
}
