#include <cassert>
#include <vector>
#include <string>
#include "maintenanceLibrary.h"

void testElectricCar()
{
    ElectricCar ec(
        std::string("V001"),
        std::string("Tesla"),
        std::string("Model S"),
        2000,
        2021,
        SEDAN,
        100.0f,
        85.0f);
    assert(ec.getMake() == "Tesla" && "ElectricCar make should be Tesla");
    assert(ec.getModel() == "Model S" && "ElectricCar model should be Model S");
    assert(ec.getBatteryCapacity() == 100.0 && "ElectricCar battery capacity should be 100.0");
    assert(ec.getType() == "Electric" && "ElectricCar type should be Electric");
}

void testGasCarGasType()
{
    GasCar gc(
        std::string("V002"),
        std::string("Toyota"),
        std::string("Camry"),
        5000,
        2020,
        SEDAN,
        2.5f,
        PREMIUM);
    assert(gc.getGasType() == "Premium" && "GasCar gas type should be Premium");
}

void testHybridCarType()
{
    HybridCar hc(
        std::string("V003"),
        std::string("Honda"),
        std::string("Insight"),
        1000,
        2022,
        SEDAN,
        1.8f,
        CNG,
        40.0f,
        true,
        BS6,
        true);
    assert(hc.getType() == "Hybrid" && "HybridCar type should be Hybrid");
    assert(hc.getIsSwitchable() == true && "HybridCar should be switchable");
}

void testMaintenanceTaskBasic()
{
    std::vector<std::string> vehicles = {"Electric", "Gas", "Diesel", "Hybrid"};
    MaintenanceTask task(105, "Wheel Alignment", "Check the wheel alignment", vehicles);
    assert(task.getTaskName() == "Wheel Alignment" && "Task name should be Wheel Alignment");
    assert(task.getDescription() == "Check the wheel alignment" && "Task description mismatch");
    assert(task.getApplicableVehicles().size() == 4 && "Applicable vehicles count should be 4");
    assert(task.getId() == 105 && "Task ID should be 105");
}

int main()
{
    cout<<"Running the Tests"<<endl;
    testElectricCar();
    testGasCarGasType();
    testHybridCarType();
    testMaintenanceTaskBasic();
    cout<<"No assert error found. Code executed successfully. Tests successful";
    return 0;
}
