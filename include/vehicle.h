#include <string>
#include <iostream>
using namespace std;
enum Type{
    ELECTRIC=1,
    GAS,
    DIESEL,
    HYBRID
};
enum CarType{
    HATCHBAG=1,
    SEDAN,
    SUV
};
enum GasType{
    CNG=1,
    PREMIUM,
    E85
};
enum EmissionStandard{
    BS6=1,
    Euro6,
    China6,
    CALIFORNIALEV
};
istream& operator>>(istream& in, Type& type) {
    int value;
    in >> value;
    switch (value) {
        case 1: type = static_cast<Type>(ELECTRIC); break;
        case 2: type = static_cast<Type>(GAS); break;
        case 3: type = static_cast<Type>(DIESEL); break;
        case 4: type = static_cast<Type>(HYBRID); break;
        default:
            in.setstate(ios::failbit); // mark input as failed
            break;
    }
    return in;
}
istream& operator>>(istream& in, CarType& type) {
    int value;
    in >> value;
    switch (value) {
        case 1: type = static_cast<CarType>(HATCHBAG); break;
        case 2: type = static_cast<CarType>(SEDAN); break;
        case 3: type = static_cast<CarType>(SUV); break;
        default:
            in.setstate(ios::failbit); // mark input as failed
            break;
    }
    return in;
}
istream& operator>>(istream& in, GasType& type) {
    int value;
    in >> value;
    switch (value) {
        case 1: type = static_cast<GasType>(CNG); break;
        case 2: type = static_cast<GasType>(PREMIUM); break;
        case 3: type = static_cast<GasType>(E85); break;
        default:
            in.setstate(ios::failbit); // mark input as failed
            break;
    }
    return in;
}
istream& operator>>(istream& in, EmissionStandard& type) {
    int value;
    in >> value;
    switch (value) {
        case 1: type = static_cast<EmissionStandard>(BS6); break;
        case 2: type = static_cast<EmissionStandard>(Euro6); break;
        case 3: type = static_cast<EmissionStandard>(China6); break;
        case 4: type = static_cast<EmissionStandard>(CALIFORNIALEV); break;
        default:
            in.setstate(ios::failbit); // mark input as failed
            break;
    }
    return in;
}
ostream& operator<<(ostream& out, Type& type){
    switch(type){
        case ELECTRIC: out<<"Electric"; break;
        case GAS: out<<"Gas"; break;
        case DIESEL: out<<"Diesel"; break;
        case HYBRID: out<<"Hybrid"; break;
        default: out.setstate(ios::failbit);break;
    }
    return out;
}
class Automobile{
    protected:
    string id;
    int odometerReading;
    int year;
    string make;
    string model;
    CarType carType;
    public:
        Automobile(){}
        Automobile(string id,string make, string model, int odometerReading, int year, CarType carType){
            this->id = id;
            this->make = make;
            this->model = model;
            this->year = year;
            this->odometerReading = odometerReading;
            this->carType = carType;
        }
        
        int getOdometerReading() const { return odometerReading; }
        void setOdometerReading(int odometerReading_) { odometerReading = odometerReading_; }
        
        int getYear() const { return year; }
        void setYear(int year_) { year = year_; }
        
        string getMake() const { return make; }
        void setMake(const string &make_) { make = make_; }
        
        string getModel() const { return model; }
        void setModel(const string &model_) { model = model_; }
        string getCarType(){
            switch(carType){
                case 1:return "HatchBag";
                case 2:return "Sedan";
                case 3:return "SUV";
            }
        }
        virtual string getType() = 0;

        string getId() const { return id; }
        void setId(string id_) { id = id_; }

};
class ElectricCar:public Automobile{
    private:
        float batteryCapacity;
        float batteryLevel;

    public:
        ElectricCar(string id,string make, string model, int odometerReading, int year, CarType type, float batteryCapacity, float batteryLevel)
        :Automobile(id, make, model, odometerReading, year, type){
            this->batteryCapacity = batteryCapacity;
            this->batteryLevel = batteryLevel;
        }
        float getBatteryCapacity() const { return batteryCapacity; }
        void setBatteryCapacity(float batteryCapacity_) { batteryCapacity = batteryCapacity_; }

        float getBatteryLevel() const { return batteryLevel; }
        void setBatteryLevel(float batteryLevel_) { batteryLevel = batteryLevel_; }
        string getType() {return "Electric";}
};
class GasCar: virtual public Automobile{
    protected:
        float cylinderSize;
        GasType gasType;
    public:
        GasCar(string id,string make, string model, int odometerReading, int year, CarType type,float cylinderSize, GasType gasType)
        :Automobile(id, make, model, odometerReading, year, type){
            this->cylinderSize = cylinderSize;
            this->gasType = gasType; 
        }
        float getCylinderSize() const { return cylinderSize; }
        void setCylinderSize(float cylinderSize_) { cylinderSize = cylinderSize_; }
        string getGasType() const { 
            switch (gasType)
            {
            case 1:
                return "CNG";
            case 2:
                return "Premium";
            case 3:
                return "E85";
            default:
                return "";
            }
         }
        void setGasType(const GasType &gasType_) { gasType = gasType_; }
        string getType() {return "Gas";}
};
class DieselCar:virtual public Automobile{
    protected:
        float tankSize;
        bool coldStartAssist;
        EmissionStandard emissionStandard;
    public:
        DieselCar(string id,string make, string model, int odometerReading, int year, CarType type,float tankSize, bool coldStartAssist, EmissionStandard emissionStandard)
        :Automobile(id, make, model, odometerReading, year, type){
            this->tankSize = tankSize;
            this->coldStartAssist = coldStartAssist;
            this->emissionStandard = emissionStandard;
        };
        float getTankSize() const { return tankSize; }
        void setTankSize(float tankSize_) { tankSize = tankSize_; }

        bool getColdStartAssist() const { return coldStartAssist; }
        void setColdStartAssist(bool coldStartAssist_) { coldStartAssist = coldStartAssist_; }

        string getEmissionStandard() const { 
            switch(emissionStandard){
                case 1: return "BS6";
                case 2: return "Euro6";
                case 3: return "China6";
                case 4: return "Californial EV";
            }
        }
        void setEmissionStandard(const EmissionStandard &emissionStandard_) { emissionStandard = emissionStandard_; }

        string getType(){return "Diesel";}
};
class HybridCar: public GasCar, public DieselCar{
    private:
        bool isSwitchable;

    public:
        HybridCar(string id,string make, string model, int odometerReading, int year, CarType type,float cylinderSize, GasType gasType,float tankSize, bool coldStartAssist, EmissionStandard emissionStandard, bool isSwitchable)
        :Automobile(id, make, model, odometerReading, year, type),GasCar(id, make, model, odometerReading, year, type,cylinderSize, gasType),DieselCar(id, make, model, odometerReading, year, type,tankSize, coldStartAssist, emissionStandard){
            this->isSwitchable = isSwitchable;
        }
        bool getIsSwitchable() const { return isSwitchable; }
        void setIsSwitchable(bool isSwitchable_) { isSwitchable = isSwitchable_; }
        string getType(){return "Hybrid";}
    
};
