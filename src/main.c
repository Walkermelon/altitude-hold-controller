#include <stdio.h>
int main(){
    
    float currentAltitude = getAltitude();
    float previousAltitude = currentAltitude;  // Initialize previous altitude for differential calculation
    float setPoint = 100.0f;  // Desired altitude (for testing purposes)
    float kp = 1.0f;  // Proportional gain (for testing purposes)
    float ki = 0.1f;  // Integral gain (for testing purposes)
    float kd = 0.05f; // Differential gain (for testing purposes)


    while(currentAltitude > 0){
        float p = proportional(currentAltitude, setPoint);
        float i = integral(currentAltitude, setPoint);
        float d = differential(currentAltitude, previousAltitude);

        // Combine the PID components to calculate the control output
        float controlOutput = kp * p + ki * i + kd * d;

        // For testing purposes, print the control output
        printf("Control Output: %f\n", controlOutput);


        

        //iterate next altitude reading
        currentAltitude = getAltitude();
    }

    return 0;
}