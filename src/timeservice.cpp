#include "timeservice.h"

namespace {
    constexpr int INITIAL_TIME_TO_RESET_MODE_S = 10; // default value 3600
    constexpr int INITIAL_TIME_TO_MAKE_MEASUREMENTS_S = 1; // default value 1
    constexpr int INITIAL_TIME_TO_ADD_MEASUREMENTS_TO_DATA_BASE_S = 0; // default value 900
}

TimeService::TimeService():     
timeToResetMode(0),
timeToMakeMeasurements(0),
timeToAddMeasurementsToDataBase(0),
initialTimeToResetMode(INITIAL_TIME_TO_RESET_MODE_S),
initialTimeToMakeMeasurements(INITIAL_TIME_TO_MAKE_MEASUREMENTS_S),
initialTimeToAddMeasurementsToDataBase(INITIAL_TIME_TO_ADD_MEASUREMENTS_TO_DATA_BASE_S), 
mode(Modes::AUTOMATIC),
requestFromHost(0) {}

TimeService::TimeService(int newInitialTimeToResetMode, 
                         int newInitialTimeToMakeMeasurements,
                         int newIinitialTimeToAddMeasurementsToDataBase):     
timeToResetMode(0),
timeToMakeMeasurements(0),
timeToAddMeasurementsToDataBase(0),
initialTimeToResetMode(newInitialTimeToResetMode),
initialTimeToMakeMeasurements(newInitialTimeToMakeMeasurements),
initialTimeToAddMeasurementsToDataBase(newIinitialTimeToAddMeasurementsToDataBase),
mode(Modes::AUTOMATIC) {}

// getters to current time
int TimeService::getTimeToResetMode() { 
    return timeToResetMode; 
}

int TimeService::getTimeToMakeMeasurements() { 
    return timeToMakeMeasurements;
}

int TimeService::getTimeToAddMeasurementsToDataBase() { 
    return timeToAddMeasurementsToDataBase;
}
   
// getters to initial time
int TimeService::getInitialTimeToResetMode() { 
    return initialTimeToResetMode; 
}

int TimeService::getInitialTimeToMakeMeasurements() { 
    return initialTimeToMakeMeasurements;
}

int TimeService::getInitialTimeToAddMeasurementsToDataBase() { 
    return initialTimeToAddMeasurementsToDataBase;
}

// setters to initial time
void TimeService::setInitialTimeToResetMode(int newInitialTimeToResetMode){
    initialTimeToResetMode = newInitialTimeToResetMode;
}

void TimeService::setInitialTimeToMakeMeasurements(int newInitialTimeToMakeMeasurements){
    initialTimeToMakeMeasurements = newInitialTimeToMakeMeasurements;
}
void TimeService::setInitialTimeToAddMeasurementsToDataBase(int newInitialTimeToAddMeasurementsToDataBase){
    initialTimeToAddMeasurementsToDataBase = newInitialTimeToAddMeasurementsToDataBase;
}

int TimeService::resetTimeToResetMode() {
    timeToResetMode = 0;
}

int TimeService::resetTimeToMakeMeasurements() {
    timeToMakeMeasurements = 0;
}

int TimeService::resetTimeToAddMeasurementsToDataBase() {
    timeToAddMeasurementsToDataBase = 0;
}

void TimeService::checkTimeToResetMode(){
    timeToResetMode = timeToResetMode >= initialTimeToResetMode 
                                      ? 0 
                                      : timeToResetMode+1 ;
    if (timeToResetMode == initialTimeToResetMode - 1){
        TimeService::instance().setMode(Modes::AUTOMATIC);
    }
}

void TimeService::checkTimeToMakeMeasurements(){    
    timeToMakeMeasurements = timeToMakeMeasurements >= initialTimeToMakeMeasurements 
                                                    ? 0 
                                                    : timeToMakeMeasurements+1 ;
}

void TimeService::checkTimeToAddMeasurementsToDataBase(){    
    timeToAddMeasurementsToDataBase = timeToAddMeasurementsToDataBase >= initialTimeToAddMeasurementsToDataBase 
                                                                      ? 0 
                                                                      : timeToAddMeasurementsToDataBase+1 ;
}

void TimeService::setMode(Modes newMode){
    mode = newMode;
}

Modes TimeService::getMode(){
    return mode;
}

void TimeService::setRequestFromHost(int newRequestFromHost){
    requestFromHost = newRequestFromHost;
}
int TimeService::getRequestFromHost(){
    return requestFromHost;
}