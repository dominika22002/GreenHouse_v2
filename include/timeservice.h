#pragma once

class TimeService {
    TimeService();
    TimeService(int newInitialTimeToResetMode, 
                int newInitialTimeToMakeMeasurements,
                int newIinitialTimeToAddMeasurementsToDataBase);

public:
    int timeToResetMode;
    int timeToMakeMeasurements;

    int initialTimeToResetMode;
    int initialTimeToMakeMeasurements;

    void resetTimeToResetMode(){
        timeToResetMode = 0;
    }

    void resetTimeToMakeMeasurements(){
        timeToMakeMeasurements = 0;
    }

    void checkTimes();

    static TimeService & instance() {
    static TimeService s;
    return s;
  } // instance
};