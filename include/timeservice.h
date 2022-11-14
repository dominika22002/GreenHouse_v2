#pragma once

enum Modes {
    AUTOMATIC,
    MANUAL
};
class TimeService {
    int timeToResetMode;
    int timeToMakeMeasurements;
    int timeToAddMeasurementsToDataBase;

    int initialTimeToResetMode;
    int initialTimeToMakeMeasurements;
    int initialTimeToAddMeasurementsToDataBase;

    Modes mode;
    int requestFromHost;
    TimeService();
    TimeService(int newInitialTimeToResetMode, 
                int newInitialTimeToMakeMeasurements,
                int newIinitialTimeToAddMeasurementsToDataBase);

public:

    int getTimeToResetMode();
    int getTimeToMakeMeasurements();
    int getTimeToAddMeasurementsToDataBase();

    int getInitialTimeToResetMode();
    int getInitialTimeToMakeMeasurements();
    int getInitialTimeToAddMeasurementsToDataBase();

    void setInitialTimeToResetMode(int newInitialTimeToResetMode);
    void setInitialTimeToMakeMeasurements(int newInitialTimeToMakeMeasurements);
    void setInitialTimeToAddMeasurementsToDataBase(int newInitialTimeToAddMeasurementsToDataBase);
    
    int resetTimeToResetMode();
    int resetTimeToMakeMeasurements();
    int resetTimeToAddMeasurementsToDataBase();

    void checkTimeToResetMode();
    void checkTimeToMakeMeasurements();
    void checkTimeToAddMeasurementsToDataBase();

    void setMode(Modes newMode);
    Modes getMode();

    void setRequestFromHost(int newRequestFromHost);
    int getRequestFromHost();

    static TimeService & instance() {
    static TimeService s;
    return s;
  } // instance
};