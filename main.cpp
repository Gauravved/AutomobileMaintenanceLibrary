#include<iostream>
#include "maintenanceLibrary.h"
#include<typeinfo>
using namespace std;
int main(){
    MaintenanceLibrary maintenanceLibrary;
    int choice = 0;
    do{
        cout<<"1> Add Vehicle \n2> List Vehicles \n3> Remove Vehicle \n4> Add Maintenance task \n5> List all Tasks \n6> Remove a task \n7> Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:{
                Automobile* vehicle;
                Type carType;
                cout<<"\t1> Electric \n\t2> Gas \n\t3> Diesel \n\t4> Hybrid \n\tEnter your car type:";
                cin>>carType;
                while(carType>4 || carType<1){
                    cout<<"Please re-enter:";
                    cin>>carType;
                }
                int odometer,year;
                string make, model, id;
                cout<<"Enter car ID(number plate): ";
                cin>>id;
                cin.ignore();
                cout<<"Make:";
                getline(cin,make);
                cout<<"Model:";
                getline(cin,model);
                cout<<"Odometer Reading:";
                cin>>odometer;
                cout<<"Year (of model):";
                cin>>year;
                CarType type;
                cout<<"1> HatchBag \n2> Sedan \n3> SUV \nEnter car type:";
                cin>>type;
                switch(carType){
                    case 1:
                        float batteryCapacity, batteryLevel;
                        cout<<"Enter Battery Capacity:";
                        cin>>batteryCapacity;
                        cout<<"Enter Battery Level:";
                        cin>>batteryLevel;
                        vehicle = new ElectricCar(id,make, model,odometer,year,type,batteryCapacity,batteryLevel);
                        break;
                    case 2:
                        float cylinderSize;
                        GasType gt;
                        cout<<"Enter Cylinder Size:";
                        cin>>cylinderSize;
                        cout<<"\n\t1> CNG \n\t2> Premium \n\t3> E85 \nEnter Gas Type: ";
                        cin>>gt;
                        vehicle = new GasCar(id, make, model, odometer, year, type, cylinderSize, gt);
                        break;
                    case 3:
                        bool coldStart;
                        float tankSize;
                        EmissionStandard est;
                        cout<<"Enter Tank Size:";
                        cin>>tankSize;
                        cout<<"Is cold start assist feature present? (1- Yes , 0- No):";
                        cin>>coldStart;
                        cout<<"\n\t1> BS6 \n\t2> Euro6 \n\t3> China6 \n\t4> Californial EV \nEnter your emission standard:";
                        cin>>est;
                        vehicle = new DieselCar(id, make, model, odometer, year, type, tankSize, coldStart, est);
                        break;
                    case 4:
                        // float cylinderSize;
                        // GasType gt;
                        cout<<"Enter Cylinder Size:";
                        cin>>cylinderSize;
                        cout<<"\n\t1> CNG \n\t2> Premium \n\t3> E85 \nEnter Gas Type: ";
                        cin>>gt;
                        // bool coldStart, isSwitchable;
                        // float tankSize;
                        // EmissionStandard est;
                        bool isSwitchable;
                        cout<<"Enter Tank Size:";
                        cin>>tankSize;
                        cout<<"Is cold start assist feature present? (1- Yes , 0- No):";
                        cin>>coldStart;
                        cout<<"\n\t1> BS6 \n\t2> Euro6 \n\t3> China6 \n\t4> Californial EV \nEnter your emission standard:";
                        cin>>est;
                        cout<<"Is it switchable? (1- Yes, 0- No):";
                        cin>>isSwitchable;
                        vehicle = new HybridCar(id, make, model, odometer, year, type, cylinderSize, gt, tankSize, coldStart, est, isSwitchable);
                        break;
                    default:
                        break;
                }
                maintenanceLibrary.addVehicle(vehicle);

                break;}
            case 2:{
                string id;
                int i=0;
                if(maintenanceLibrary.getVehicle().size() == 0){
                    cout<<"No vehicles added!!"<<endl;
                    break;
                }
                for(auto j: maintenanceLibrary.getVehicle()){
                    cout<< i+1 <<"> "<<j->getId()<<endl;
                    i++;
                }
                cout<<"Enter the vehile ID (number plate) to view more details (else press N):";
                cin>>id;
                cin.ignore();
                if(id == "N"){
                    break;
                }
                else{
                    Automobile* v = maintenanceLibrary.searchVehicle(id);
                    if(v == nullptr){
                        cout<<"Vehicle not available!!!"<<endl;
                    }
                    else{
                        cout<<"ID : "<<v->getId()<<endl;
                        cout<<"Make : "<<v->getMake()<<endl;
                        cout<<"Model : "<<v->getModel()<<endl;
                        cout<<"Odometer Reading : "<<v->getOdometerReading()<<endl;
                        cout<<"Year : "<<v->getYear()<<endl;
                        cout<<"Car type : "<<v->getCarType()<<endl;
                        if(ElectricCar* ec = dynamic_cast<ElectricCar*>(v)){
                            cout<<"Battery Capacity : "<<ec->getBatteryCapacity()<<endl;
                            cout<<"Battery Level : "<<ec->getBatteryLevel()<<endl;
                        }else if(HybridCar* hc = dynamic_cast<HybridCar*>(v)){
                            cout<<"Cylinder Size : "<<hc->getCylinderSize()<<endl;
                            cout<<"Gas Type : "<<hc->getGasType()<<endl;
                            cout<<"Tank Size : "<<hc->getTankSize()<<endl;
                            cout<<"Cold Start Assist : "<<hc->getColdStartAssist()<<endl;
                            cout<<"Emission Standard : "<<hc->getEmissionStandard()<<endl;
                        }else if(GasCar* gc = dynamic_cast<GasCar*>(v)){
                            cout<<"Cylinder Size : "<<gc->getCylinderSize()<<endl;
                            cout<<"Gas Type : "<<gc->getGasType()<<endl;
                        }else if(DieselCar* dc = dynamic_cast<DieselCar*>(v)){
                            cout<<"Tank Size : "<<dc->getTankSize()<<endl;
                            cout<<"Cold Start Assist : "<<dc->getColdStartAssist()<<endl;
                            cout<<"Emission Standard : "<<dc->getEmissionStandard()<<endl;
                        }
                    }
                }


                break;
            }
            case 3:{
                string id;
                cout<<"Enter the ID (number plate) to remove the vehicle:";
                cin>>id;
                if(maintenanceLibrary.removeVehicle(id)){
                    cout<<"Vehicle removed"<<endl;
                }else{
                    cout<<"Couldn't remove the vehicle!!"<<endl;
                }
                break;
            }
        }
    }while(choice!=7);
    
    return 0;
}