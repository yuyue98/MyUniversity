#include "myheader.h"
#include "theList.h"

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
    stulist L;
	L = initlist(L);
    inputlist(L);
    blanklist(L); 
	reverlist(L);
    system("pause");
	return OK;
}