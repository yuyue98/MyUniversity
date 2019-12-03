#include "IndentManage.h"

IndentManage::IndentManage() {
}

IndentManage::IndentManage(vector<Indent*>& indentlist):IndentList(indentlist) {
}

IndentManage::~IndentManage() {
	clear();
}

Indent* IndentManage::operator[](int id) {
	if (IndentList.empty()||id<0||id>=IndentList.size()) {
		return nullptr;
	} else {
		return IndentList[id];
	}
}

bool IndentManage::DeleteIndentWithNo(int id) {
	if (IndentList.empty()||id<0||id>=IndentList.size()) {
		return false;
	}
	vector<Indent*>::iterator pd = IndentList.begin()+id;
	if (IndentList[id]) {
		delete IndentList[id];
		IndentList[id] = nullptr;
	}
	IndentList.erase(pd);
	return true;
}

int IndentManage::SearchIndentWithID(string id) {
	if (IndentList.empty()) {
		return -1;
	}
	for (int i=0;i<IndentList.size();i++) {
		if (id==IndentList[i]->getID()) {
			return i;
		}
	}
	return -1;
}

bool IndentManage::DeleteIndentWithID(string id) {
	int i = SearchIndentWithID(id);
	if (-1==i) {
		return false;
	}
	vector<Indent*>::iterator pd = IndentList.begin()+i;
	if (IndentList[i]) {
		delete IndentList[i];
		IndentList[i] = nullptr;
	}
	IndentList.erase(pd);
	return true;
}

bool IndentManage::setIndentList(vector<Indent*>& indentlist) {
	try {
		IndentList = indentlist;
		return true;
	} catch(...) {
		return false;
	}
}

bool IndentManage::setIndent(Indent* indent) {
	try {
		int i;
		if ((i=SearchIndentWithID(indent->getID()))!=-1) {
			Indent* pd = IndentList[i];
			IndentList[i] = indent;
			if (nullptr!=pd) {
				delete pd;
			}
		} else {
			IndentList.push_back(indent);
		}
		return true;
	} catch(...) {
		return false;
	}
}
		
void IndentManage::clear() {
	for (int i=0;i<IndentList.size();i++) {
		if (IndentList[i]) {
			delete IndentList[i];
			IndentList[i] = nullptr;
		}
	}
	IndentList.clear();
}

void IndentManage::display() {
	if (IndentList.empty()) {
		cout<<"当前订单列表没有内容！"<<endl;
		return;
	}
	cout<<"++++++++++++++++++订单列表++++++++++++++++++"<<endl;
	putStr("No",3);
	putStr("ID",INDENTIDLEN-1);
	putStr("APrice",7);
	putStr("Type",5);
	cout<<endl;
	for (int i=0;i<IndentList.size();i++) {
		putStr(toString(i),3);
		IndentList[i]->putIndent();
	}
}
