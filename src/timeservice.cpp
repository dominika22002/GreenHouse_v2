#include "global.h"

namespace {
    constexpr int INITIAL_TIME_TO_RESET_MODE_S = 10; // default value 3600
    constexpr int INITIAL_TIME_TO_MAKE_MEASUREMENTS_S = 1; // default value 1
}

TimeService::TimeService():     
    timeToResetMode(0),
    timeToMakeMeasurements(0),
    initialTimeToResetMode(INITIAL_TIME_TO_RESET_MODE_S),
    initialTimeToMakeMeasurements(INITIAL_TIME_TO_MAKE_MEASUREMENTS_S){
}

TimeService::TimeService(int newInitialTimeToResetMode, 
                         int newInitialTimeToMakeMeasurements,
                         int newIinitialTimeToAddMeasurementsToDataBase):     
    timeToResetMode(0),
    timeToMakeMeasurements(0),
    initialTimeToResetMode(newInitialTimeToResetMode),
    initialTimeToMakeMeasurements(newInitialTimeToMakeMeasurements){
}

void TimeService::checkTimes(){
    if (Statuses::instance().mode == Modes::MANUAL){
        timeToResetMode = timeToResetMode >= initialTimeToResetMode 
                                        ? 0 
                                        : timeToResetMode+1 ;
        if (timeToResetMode == initialTimeToResetMode - 1){
            Statuses::instance().mode = Modes::AUTOMATIC;
        }
    }
    timeToMakeMeasurements = timeToMakeMeasurements >= initialTimeToMakeMeasurements 
                                                    ? 0 
                                                    : timeToMakeMeasurements+1 ;
}