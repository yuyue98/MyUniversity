#ifndef CVEHICLE_H
#define CVEHICLE_H

#include "CPerson.h"

class CVehicle {
	private:
		static int VehicleNum;
		CPerson* Owner;    // 所有人 
		CPerson* Driver;   // 驾驶人
		string VID;        // 车牌号 
		string Brand;      // 品牌 
		string Color;      // 颜色 
		string VIN;        // 车架号 
	public:
		CVehicle(string vid="未知",string brand="未知",string color="未知",string vin="未知");
		CVehicle(CPerson& owner,string vid="未知",string brand="未知",string color="未知",string vin="未知");
		CVehicle(CPerson& owner,CPerson& driver,string vid="未知",string brand="未知",string color="未知",string vin="未知");
		virtual ~CVehicle();
		inline bool setOwner(CPerson& owner) { Owner=&owner;return true; };
		inline bool setDriver(CPerson& driver) { Driver=&driver;return true; };
		inline bool setVID(string vid="") { if (vid=="") return false; else { VID=vid;return true; } };
		inline bool setBrand(string brand="") { if (brand=="") return false; else { Brand=brand;return true; } };
		inline bool setColor(string color="") { if (color=="") return false; else { Color=color;return true; } };
		inline bool setVIN(string vin="") { if (vin=="") return false; else { VIN=vin;return true; } };
		inline CPerson* getOwner() const { return Owner; };
		inline CPerson* getDriver() const { return Driver; };
		inline string getVID() const { return VID; };
		inline string getBrand() const { return Brand; };
		inline string getColor() const { return Color; };
		inline string getVIN() const { return VIN; };
		inline static int getVehicleNum() { return VehicleNum; };
		void putVehicle() const;
		void putOwner() const;
		void putDriver() const;
		virtual void putAll() const;
	protected:
};

#endif
