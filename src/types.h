#ifndef TYPES_H
#define TYPES_H

/*!
  \enum Types
  \brief Defines the actuators types and names

  \value T_LIGHT Light actuators or max 10A plugs
  \value T_APPLIANCE Appliance actuator such as washing machine or something similar
  \value T_POWER A power plug or something that requires more than 10A
*/
enum Types {
    T_LIGHT,
    T_APPLIANCE,
    T_POWER
};

enum Commands{
    C_SWITCH,
    C_DIM
};

#endif //TYPES_H
