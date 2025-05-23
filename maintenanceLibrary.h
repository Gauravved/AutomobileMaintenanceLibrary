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
        vector<MaintenanceTask*> maintenanceTasks;
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
        vector<MaintenanceTask> searchMaintenanceTask(string id){
            return tasks[id];
        }
        unordered_map<string,vector<MaintenanceTask>> getTasks() const { return tasks; }
        void removeTask(string vehicleId, int id){
            int i;
            // vector<MaintenanceTask> t = tasks[vehicleId];
            for(i=0;i<tasks[vehicleId].size();i++){
                if(tasks[vehicleId][i].getId() == id){
                    tasks[vehicleId].erase(tasks[vehicleId].begin()+i);
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
                //delete *it;
                vehicle.erase(it);
                return true;
            }
            tasks.erase(id);
            return false;
        }
        void addTask(MaintenanceTask* t){
            maintenanceTasks.push_back(t);
        }
        vector<MaintenanceTask*> getMaintenanceTasks(){
            return maintenanceTasks;
        }
        MaintenanceTask* searchTask(int id){
            for(auto i: maintenanceTasks){
                if(i->getId() == id){
                    return i;
                }
            }
            return nullptr;
        }
        void removeMaintenanceTask(MaintenanceTask* taskToRemove){
            maintenanceTasks.erase(
                std::remove(maintenanceTasks.begin(), maintenanceTasks.end(), taskToRemove),
                maintenanceTasks.end()
            );
        
            for (auto& pair : tasks) {
                string category = pair.first; 
                vector<MaintenanceTask>& taskVec = pair.second;
                taskVec.erase(
                    std::remove_if(taskVec.begin(), taskVec.end(),
                        [taskToRemove](const MaintenanceTask& task) {
                            return task.getId() == taskToRemove->getId(); 
                        }),
                    taskVec.end()
                );
            }
        }
        bool findVehicleWithId(string id){
            for(auto& i: vehicle){
                if(i->getId() == id){
                    return true;
                }
            }
            return false;
        }
        
        bool findTaskWithId(int id){
            for(auto& i: maintenanceTasks){
                if(i->getId() == id){
                    return true;
                }
            }
            return false;
        }
        MaintenanceTask* isValidTask(string id, int taskId){
            Automobile* temp = searchVehicle(id);
            for(auto& j: maintenanceTasks){
                if(taskId == j->getId()){
                    vector<string> str = j->getApplicableVehicles();
                    if(find(str.begin(),str.end(),temp->getType())!=str.end()){
                        return j;
                    }
                    break;
                }
            }
            return nullptr;
        }

        bool isTaskAdded(string id, int taskId){
            for(auto i: tasks[id]){
                if(taskId == i.getId()){
                    return true;
                }
            }
            return false;
        }
};