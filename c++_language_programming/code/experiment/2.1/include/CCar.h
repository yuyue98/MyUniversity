#ifndef CCAR_H
#define CCAR_H

#include <iostream>
#include <string>

#include "CPerson.h"

using namespace std;

class CCar {
	private:
		string CID;
		CPerson* Owner;
		string Brand;
		string Color;
		string VIN; 
	public:
		CCar(string cid,string brand="未知",string color="未知",string vin="未知");
		CCar(string cid,CPerson& owner,string brand="未知",string color="未知",string vin="未知");
		~CCar();
		inline bool setOwner(CPerson& owner) { Owner=&owner;return true; };
		inline bool setBrand(string brand="") { if (brand=="") return false; else { Brand=brand;return true; } };
		inline bool setColor(string color="") { if (color=="") return false; else { Color=color;return true; } };
		inline bool setVIN(string vin="") { if (vin=="") return false; else { VIN=vin;return true; } };
		inline string getCID() const { return CID; };
		inline CPerson* getOwner() const { return Owner; };
		inline string getBrand() const { return Brand; };
		inline string getColor() const { return Color; };
		inline string getVIN() const { return VIN; };
		void putCar() const;
		void putOwner() const;
		void putAll() const; 
	protected:
};

#endif
