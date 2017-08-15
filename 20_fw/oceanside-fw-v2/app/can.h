#ifndef CAN_H_
#define CAN_H_

void can_init(void);

//http://www.chibios.com/forum/viewtopic.php?f=16&t=4079
/*0b100 - Data with EID or (0b110 - RemoteFrame with EID)*/
#define set_can_eid_data(x) ((x << 3)|0b100)

/*0b110 - Mask enable for EID/SID and DATA/RTR*/
#define set_can_eid_mask(x) ((x << 3)|0b110)

#endif


/*
2017-08-15
Interested messages.

F003 (50ms)
- [0]:5..4  Road Speed Limit Status
- [0]:3..2  Accelerator Pedal Kickdown Switch
- [0]:1..0  Accelerator Pedal Idle Switch
- [1]       Accelerator Pedal Position
- [2]       Percent Load at Current Speed
- [3]       Remote Accelerator

F004 (20ms)
- [0]: 3..0 Engine Torque Mode
- [1]       Driver's Demand Torque
- [2]       Actual Engine Torque
- [3..4]    Engine Speed
- [5]       Source Address of Controlling Device (TSC0)

FEF1 (100ms) Transmit Cruise Status
- [1..2]    Vehicle Speed
- [3]:7..6  Clutch Switch
- [3]:5..4  Brake Switch
- [3]:3..2  Cruise Enable Switch
- [4]:6..7  Cruise Accel Switch
- [4]:5..4  Cruise Resume Switch
- [4]:3..2  Cruise Decel Switch
- [4]:1..0  Cruise Set Switch
- [5]       Cruise Control Set Speed
- [6]:7..5  Cruise Control State
- [6]:4..0  PTO State

FEF2 (100ms) Transmit Fuel Economy
- [0..1]    Diesel Equivalent Fuel Flow Rate
- [6]       Throttle Position

FEF6 (500ms) Transmit Inlet Conditions
- [1]       Boost Pressure
- [2]       Intake Air Temperature
- [5..6]    Exhaust Temperature

FEAA/65194 (On Request) Alternate Fuel 2
- [1]       Engine Gaseous Fuel Correction Factor
- [2..3]    Engine Desired Absolute Intake Manifold Pressure (Turbo Boost Limit)
- [4]       Engine Turbo Charger Wastegate Valve Position
- [5]       Engine Gas Mass Flow Sensor Fueling Correction

*/
