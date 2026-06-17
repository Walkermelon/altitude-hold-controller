#include "PID.h"

float PID(){

    //CONSIDER MAKING A STRUCT FOR THESE TO PASS IN
    float currentAltitude = getAltitude();
    float previousAltitude = currentAltitude;  // Initialize previous altitude for differential calculation
    float setPoint = getSetPoint();  // Retrieve the desired set point
    float sumError = 0.0f;  // Initialize sum of errors for integral calculation
    float kp = 1.0f;  // Proportional gain (for testing purposes)
    float ki = 0.1f;  // Integral gain (for testing purposes)
    float kd = 0.05f; // Differential gain (for testing purposes)








    // while(currentAltitude > 0){
    //     float p = proportional(currentAltitude, setPoint);
    //     float i = integral(currentAltitude, sumError, setPoint);
    //     float d = differential(currentAltitude, previousAltitude);

    //     // Combine the PID components to calculate the control output
    //     float controlOutput = kp * p + ki * i + kd * d;
        
    //     // For testing purposes, print the control output
    //     printf("Control Output: %f\n", controlOutput);

    //     // Set the throttle based on the control output (for testing purposes)
    //     setThrottle(controlOutput);

    //     //iterate next altitude reading
    //     setPoint = getSetPoint();  // Update set point if needed
    //     previousAltitude = currentAltitude;  // Update previous altitude for the next iteration
    //     currentAltitude = getAltitude();
    //     sumError = i;  // Update the sum of errors for the next iteration
    // }

}