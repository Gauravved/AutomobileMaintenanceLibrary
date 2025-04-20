#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include "maintenanceTask.h"
#include "vehicle.h"
using namespace std;
class MaintenanceLibrary{
    private:
        vector<Automobile*> vehicle;
        unordered_map<string, vector<MaintenanceTask>> tasks;
    public:
        MaintenanceLibrary(){}
        MaintenanceLibrary(const vector<Automobile*>& vehicle, const unordered_map<string, vector<MaintenanceTask>>& tasks):vehicle(vehicle),tasks(tasks){}
        
        vector<Automobile*> getVehicle() const { return vehicle; }
        // void setVehicle(const Automobile &vehicle_) { vehicle = vehicle_; }

        // void setTasks(const vector<MaintenanceTask> &tasks_) { tasks = tasks_; }
        void addVehicle(Automobile* automobile){
            vehicle.push_back(automobile);
            tasks[automobile->getId()];
        }
        void addMaintenanceTask(string vehicleId, MaintenanceTask task){
            tasks[vehicleId].push_back(task);
        }
        unordered_map<string,vector<MaintenanceTask>> getTasks() const { return tasks; }
        void removeTask(string vehicleId, int id){
            int i;
            vector<MaintenanceTask> t = tasks[vehicleId];
            for(i=0;i<t.size();i++){
                if(t[i].getId() == id){
                    t.erase(t.begin()+i);
                    break;
                }
            }
        }
        Automobile* searchVehicle(string vehicleId){
            for(auto i: vehicle){
                if(vehicleId == i->getId()){
                    return i;
                }
            }
            return nullptr;
        }
        bool removeVehicle(string id){
            auto it = find_if(vehicle.begin(),vehicle.end(),[&id](Automobile *e){
                return e->getId() == id;
            });
            if(it != vehicle.end()){
                delete *it;
                vehicle.erase(it);
                return true;
            }
            return false;
        }
        
};