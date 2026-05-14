#include <stdio.h>
int main(){
    
    
    while(1){
        // Main loop for altitude hold controller
        float currentAltitude = getAltitude();

        if(currentAltitude < 0){
            break;  // Exit loop if altitude is negative (error condition)
        }


    }

    return 0;
}