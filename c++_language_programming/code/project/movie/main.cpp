#include "menu.h"

using namespace std;

int main(int argc, char* argv[]) {
    /**
     * The c++ language project main program
     */
    menu_4 menu;
	menu.menu_00(10, 5);
	int judge = 0;
	while (1)
	{
		menu.menu_01();
		while (1)
		{
			menu.menu_02();
			if (menu.get_judge_return() == 0)break;
			menu.menu_03();
			if (menu.get_judge_return() == 2 && menu.get_judge_return_2() == 0)continue;
			if (menu.get_judge_return() == 2 && menu.get_judge_return_2() != 0)break;
			menu.menu_04();
			judge = 1; 
			break;
		}
		if (judge == 1)break;
	}
	// Sleep(1000000);

    system("pause");
    return 0;
}