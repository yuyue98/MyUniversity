#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int a[] = {8,5,5,0,6,0,8,5,5,0,7,8};
	for (int i=0;i<5;i++) {
		try {
			cout<<"in for loop...."<<i<<"\t";
			if (a[i+1]==0) {
				throw i;
			}
			cout<<a[i]<<"/"<<a[i+1]<<"="<<a[i]/a[i+1]<<endl;
		} catch (int) {
			cout<<"end"<<endl;
		}
	}
	return 0;
}
