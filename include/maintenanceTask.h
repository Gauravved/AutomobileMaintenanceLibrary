#include<string>
#include<vector>
using namespace std;
class MaintenanceTask{
    private:
        int id;
        string taskName;
        string description;
        vector<string> applicableVehicles;
    public:
        MaintenanceTask(int id, string taskName, string description, vector<string> applicableVehicles){
            this->id = id;
            this->taskName = taskName;
            this->description = description;
            this->applicableVehicles = applicableVehicles;
        }
        string getTaskName() const { return taskName; }
        void setTaskName(const string &taskName_) { taskName = taskName_; }

        string getDescription() const { return description; }
        void setDescription(const string &description_) { description = description_; }

        vector<string> getApplicableVehicles() const { return applicableVehicles; }
        void setApplicableVehicles(const vector<string> &applicableVehicles_) { applicableVehicles = applicableVehicles_; }

        int getId() const { return id; }
        void setId(int id_) { id = id_; }
};