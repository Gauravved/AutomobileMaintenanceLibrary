#include <iostream>
#include "maintenanceLibrary.h"
#include <typeinfo>
using namespace std;
void displayTask(MaintenanceLibrary maintenanceLibrary)
{
    cout << "ID \t Name \n";
    for (auto i : maintenanceLibrary.getMaintenanceTasks())
    {
        cout << i->getId() << "\t";
        cout << i->getTaskName() << "\t";
        // cout<<i->getDescription()<<"\t";
        // for(auto j: i->getApplicableVehicles()){
        //     cout<<j<<", ";
        // }
        cout << endl;
    }
}
void displayVehicle(MaintenanceLibrary maintenanceLibrary)
{
    int i = 0;
    for (auto j : maintenanceLibrary.getVehicle())
    {
        cout << i + 1 << "> " << j->getId() << " -> " << j->getModel() << endl;
        i++;
    }
}
void displayVehicleDetails(Automobile *v)
{
    cout << "ID : " << v->getId() << endl;
    cout << "Make : " << v->getMake() << endl;
    cout << "Model : " << v->getModel() << endl;
    cout << "Odometer Reading : " << v->getOdometerReading() << endl;
    cout << "Year : " << v->getYear() << endl;
    cout << "Car type : " << v->getCarType() << endl;
    if (ElectricCar *ec = dynamic_cast<ElectricCar *>(v))
    {
        cout << "Battery Capacity : " << ec->getBatteryCapacity() << endl;
        cout << "Battery Level : " << ec->getBatteryLevel() << endl;
        cout << "Type: " << ec->getType() << endl;
    }
    else if (HybridCar *hc = dynamic_cast<HybridCar *>(v))
    {
        cout << "Cylinder Size : " << hc->getCylinderSize() << endl;
        cout << "Gas Type : " << hc->getGasType() << endl;
        cout << "Tank Size : " << hc->getTankSize() << endl;
        cout << "Cold Start Assist : " << hc->getColdStartAssist() << endl;
        cout << "Emission Standard : " << hc->getEmissionStandard() << endl;
        cout << "Type: " << hc->getType() << endl;
    }
    else if (GasCar *gc = dynamic_cast<GasCar *>(v))
    {
        cout << "Cylinder Size : " << gc->getCylinderSize() << endl;
        cout << "Gas Type : " << gc->getGasType() << endl;
        cout << "Type: " << gc->getType() << endl;
    }
    else if (DieselCar *dc = dynamic_cast<DieselCar *>(v))
    {
        cout << "Tank Size : " << dc->getTankSize() << endl;
        cout << "Cold Start Assist : " << dc->getColdStartAssist() << endl;
        cout << "Emission Standard : " << dc->getEmissionStandard() << endl;
        cout << "Type: " << dc->getType() << endl;
    }
}
int main()
{
    MaintenanceLibrary maintenanceLibrary;
    maintenanceLibrary.addTask(new MaintenanceTask(101, "Battery Inspection", "Check the battery condition", vector<string>{"Electric"}));
    maintenanceLibrary.addTask(new MaintenanceTask(102, "Oil Change", "Check the engine oil level and refil", vector<string>{"Gas", "Diesel", "Hybrid"}));
    maintenanceLibrary.addTask(new MaintenanceTask(103, "Wheel Alignment", "Check the wheel alignment if not aligned fix it", vector<string>{"Electric", "Gas", "Diesel", "Hybrid"}));
    int choice = 0;
    int choice2 = 0;
    int choice3 = 0;
    int mainCh = 0;
    do
    {
        cout << "1> Vehicle \n2> Tasks \n3> Task for Vehicle\n4> Exit\nEnter choice:";
        cin >> mainCh;
        switch (mainCh)
        {
        case 1:
        {
            do
            {
                cout << "\t1> Add Vehicle \n\t2> List Vehicles \n\t3> Remove Vehicle \n\t4> Exit";
                cout << "\nEnter your choice:";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    Automobile *vehicle;
                    Type carType;
                    int ctype;
                    cout << "\t1> Electric \n\t2> Gas \n\t3> Diesel \n\t4> Hybrid \n\tEnter your car type:";
                    cin >> ctype;
                    while (ctype > 4 || ctype < 1)
                    {
                        cout << "Please re-enter:";
                        cin >> ctype;
                    }
                    carType = static_cast<Type>(ctype);
                    int odometer, year;
                    string make, model, id;
                    cout << "Enter car ID(number plate): ";
                    cin >> id;
                    while(maintenanceLibrary.findVehicleWithId(id)){
                        cout<<"Vehicle already exists!! Enter other Vehicle ID:";
                        cin>>id;
                    }
                    cin.ignore();
                    cout << "Make:";
                    getline(cin, make);
                    cout << "Model:";
                    getline(cin, model);
                    cout << "Odometer Reading:";
                    cin >> odometer;
                    cout << "Year (of model):";
                    cin >> year;
                    CarType type;
                    cout << "1> HatchBag \n2> Sedan \n3> SUV \nEnter car type:";
                    cin >> type;
                    switch (carType)
                    {
                    case 1:
                        float batteryCapacity, batteryLevel;
                        cout << "Enter Battery Capacity:";
                        cin >> batteryCapacity;
                        cout << "Enter Battery Level:";
                        cin >> batteryLevel;
                        vehicle = new ElectricCar(id, make, model, odometer, year, type, batteryCapacity, batteryLevel);
                        break;
                    case 2:
                        float cylinderSize;
                        GasType gt;
                        cout << "Enter Cylinder Size:";
                        cin >> cylinderSize;
                        cout << "\n\t1> CNG \n\t2> Premium \n\t3> E85 \nEnter Gas Type: ";
                        cin >> gt;
                        vehicle = new GasCar(id, make, model, odometer, year, type, cylinderSize, gt);
                        break;
                    case 3:
                        bool coldStart;
                        float tankSize;
                        EmissionStandard est;
                        cout << "Enter Tank Size:";
                        cin >> tankSize;
                        cout << "Is cold start assist feature present? (1- Yes , 0- No):";
                        cin >> coldStart;
                        cout << "\n\t1> BS6 \n\t2> Euro6 \n\t3> China6 \n\t4> Californial EV \nEnter your emission standard:";
                        cin >> est;
                        vehicle = new DieselCar(id, make, model, odometer, year, type, tankSize, coldStart, est);
                        break;
                    case 4:
                        // float cylinderSize;
                        // GasType gt;
                        cout << "Enter Cylinder Size:";
                        cin >> cylinderSize;
                        cout << "\n\t1> CNG \n\t2> Premium \n\t3> E85 \nEnter Gas Type: ";
                        cin >> gt;
                        // bool coldStart, isSwitchable;
                        // float tankSize;
                        // EmissionStandard est;
                        bool isSwitchable;
                        cout << "Enter Tank Size:";
                        cin >> tankSize;
                        cout << "Is cold start assist feature present? (1- Yes , 0- No):";
                        cin >> coldStart;
                        cout << "\n\t1> BS6 \n\t2> Euro6 \n\t3> China6 \n\t4> Californial EV \nEnter your emission standard:";
                        cin >> est;
                        cout << "Is it switchable? (1- Yes, 0- No):";
                        cin >> isSwitchable;
                        vehicle = new HybridCar(id, make, model, odometer, year, type, cylinderSize, gt, tankSize, coldStart, est, isSwitchable);
                        break;
                    default:
                        break;
                    }
                    maintenanceLibrary.addVehicle(vehicle);

                    break;
                }
                case 2:
                {
                    string id;
                    if (maintenanceLibrary.getVehicle().size() == 0)
                    {
                        cout << "No vehicles added!!" << endl;
                        break;
                    }
                    displayVehicle(maintenanceLibrary);
                    cout << "Enter the vehile ID (number plate) to view more details (else press N):";
                    cin >> id;
                    cin.ignore();
                    if (id == "N")
                    {
                        break;
                    }
                    else
                    {
                        Automobile *v = maintenanceLibrary.searchVehicle(id);
                        if (v == nullptr)
                        {
                            cout << "Vehicle not available!!!" << endl;
                        }
                        else
                        {
                            displayVehicleDetails(v);
                        }
                    }

                    break;
                }
                case 3:
                {
                    string id;
                    cout << "Enter the ID (number plate) to remove the vehicle:";
                    cin >> id;
                    if (maintenanceLibrary.removeVehicle(id))
                    {
                        cout << "Vehicle removed" << endl;
                    }
                    else
                    {
                        cout << "Couldn't remove the vehicle!!" << endl;
                    }
                    break;
                }
                }
            } while (choice != 4);
            break;
        }

        case 2:
        {
            do
            {
                cout << "\t1> Add Maintenance task \n\t2> List all Tasks \n\t3> Remove a task \n\t4> Exit";
                cout << "\nEnter your choice:";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    int id;
                    string name, description;
                    vector<string> applicableVehicles;
                    cout << "Enter the Task id:";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Task name:";
                    getline(cin, name);
                    cout << "Enter Task description:";
                    getline(cin, description);
                    int ch;
                    cout << "\t1> Electric Car\n\t2> Gas Car \n\t3> Diesel Car \n\t4> Hybrid Car \n\t5> Exit\nEnter all applicable cars: ";
                    cin >> ch;
                    while (ch > 4 || ch < 1)
                    {
                        cout << "Atleast one car is required!! Enter again:";
                        cin >> ch;
                    }
                    while (ch != 5)
                    {
                        switch (ch)
                        {
                        case 1:
                        {
                            auto it = find(applicableVehicles.begin(), applicableVehicles.end(), "Electric");
                            if (it != applicableVehicles.end())
                            {
                                cout << "Vehicle Type already added\n";
                                break;
                            }
                            else
                            {
                                applicableVehicles.push_back("Electric");
                            }
                            break;
                        }
                        case 2:
                        {
                            auto it = find(applicableVehicles.begin(), applicableVehicles.end(), "Gas");
                            if (it != applicableVehicles.end())
                            {
                                cout << "Vehicle Type already added\n";
                                break;
                            }
                            else
                            {
                                applicableVehicles.push_back("Gas");
                            }
                            break;
                        }
                        case 3:
                        {
                            auto it = find(applicableVehicles.begin(), applicableVehicles.end(), "Diesel");
                            if (it != applicableVehicles.end())
                            {
                                cout << "Vehicle Type already added\n";
                                break;
                            }
                            else
                            {
                                applicableVehicles.push_back("Diesel");
                            }
                            break;
                        }
                        case 4:
                        {
                            auto it = find(applicableVehicles.begin(), applicableVehicles.end(), "Hybrid");
                            if (it != applicableVehicles.end())
                            {
                                cout << "Vehicle Type already added\n";
                                break;
                            }
                            else
                            {
                                applicableVehicles.push_back("Hybrid");
                            }
                            break;
                        }
                        case 5:
                            break;
                        default:
                            cout << "Enter valid car choice!";
                        }
                        cout << "Add more car? :";
                        cin >> ch;
                    }
                    maintenanceLibrary.addTask(new MaintenanceTask(id, name, description, applicableVehicles));
                    break;
                }
                case 2:
                {
                    displayTask(maintenanceLibrary);
                    break;
                }
                case 3:
                {
                    int id;
                    displayTask(maintenanceLibrary);
                    cout << "Enter Id to delete:";
                    cin >> id;
                    MaintenanceTask *toDelete = maintenanceLibrary.searchTask(id);
                    if (toDelete == nullptr)
                    {
                        cout << "Invalid id!!" << endl;
                    }
                    else
                    {
                        maintenanceLibrary.removeMaintenanceTask(toDelete);
                        cout << "Task Removed!!"<<endl;
                    }
                    break;
                }
                }
            } while (choice2 != 4);
            break;
        }
        case 3:
        {
            do
            {
                cout << "\t1> Add Task to Vehicle \n\t2> List Vehicles and Tasks \n\t3> Remove a Task \n\t4> Exit";
                cout << "\nEnter your choice: ";
                cin >> choice3;
                switch (choice3)
                {
                case 1:
                {
                    string id;
                    int taskId;
                    displayVehicle(maintenanceLibrary);
                    cout << "Enter the Vehicle ID(number plate):";
                    cin.ignore();
                    getline(cin, id);
                    while (!maintenanceLibrary.findVehicleWithId(id))
                    {
                        cout << "Vehicle not added please add it or enter other vehicle ID:";
                        cin >> id;
                    }
                    char ch;
                    do
                    {
                        cout << "Enter the Task ID:";
                        cin >> taskId;
                        while (!maintenanceLibrary.findTaskWithId(taskId))
                        {
                            cout << "Task not added please add it or enter other task ID:";
                            cin >> taskId;
                        }
                        MaintenanceTask *m = maintenanceLibrary.isValidTask(id, taskId);
                        if (m != nullptr)
                        {
                            if(maintenanceLibrary.isTaskAdded(id, taskId)){
                                cout<<"Task Already added!!"<<endl;
                            }else{
                                maintenanceLibrary.addMaintenanceTask(id, *m);
                                cout << "Task Added" << endl;
                            }
                        }
                        else
                        {
                            cout << "This vehicle Type is not competible with the the task!!" << endl;
                        }
                        cout << "Add more Tasks? (Y/N):";
                        cin.ignore();
                        cin >> ch;

                    } while (ch != 'N' && ch != 'n');
                    break;
                }
                case 2:
                {
                    if (maintenanceLibrary.getVehicle().size() == 0)
                    {
                        cout << "No vehicles added!!" << endl;
                        break;
                    }
                    displayVehicle(maintenanceLibrary);
                    string id;
                    cout << "Enter the Vehicle ID:";
                    cin >> id;
                    Automobile *v = maintenanceLibrary.searchVehicle(id);
                    if (v == nullptr)
                    {
                        cout << "Vehicle not available!!!" << endl;
                    }
                    else
                    {
                        displayVehicleDetails(v);
                        vector<MaintenanceTask> m = maintenanceLibrary.searchMaintenanceTask(id);
                        if(m.size() == 0){
                            cout<<"No task added yet!!"<<endl;
                        }else{
                            cout<<"Sr NO. \t Name - Description"<<endl;
                            for(int i=0;i<m.size();i++){
                                cout<<m[i].getId()<<"\t"<<m[i].getTaskName()<<" - "<<m[i].getDescription()<<endl;
                            }
                        }
                    }
                    break;
                }
                case 3:{
                    string id;
                    int taskId;
                    displayVehicle(maintenanceLibrary);
                    cout << "Enter the Vehicle ID(number plate):";
                    cin.ignore();
                    getline(cin, id);
                    while (!maintenanceLibrary.findVehicleWithId(id))
                    {
                        cout << "Vehicle not added please add it or enter other vehicle ID:";
                        cin >> id;
                    }
                    cout << "Enter the Task ID:";
                    cin >> taskId;
                    while (!maintenanceLibrary.findTaskWithId(taskId))
                    {
                        cout << "Task not added please add it or enter other task ID:";
                        cin >> taskId;
                    }
                    maintenanceLibrary.removeTask(id,taskId);
                    cout<<"Task Deleted!!"<<endl;
                    break;
                }
                }
            } while (choice3 != 4);
        }
        }
    } while (mainCh != 4);

    return 0;
}