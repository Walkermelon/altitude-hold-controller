##**Purpose**
    
For now, be able to effectively control the altitude of a drone in a noisy environement

##**Scope**

This program will simulate the PID process

##**Functional Requirements**

(REQ1)The system shall output a control signal within the range of [TBD] 
(REQ2)The system shall have a real time input-output loop
(REQ3)The system shall log simulation data to a CSV file for external visualization
(REQ4)The system shall report rise time, percent overshoot, settle time, and steady-state error at the end of each simulation run
(REQ5)The system shall handle invalid states and properly throw errors
(REQ6)The system shall maintain altitude within ±[TBD] meters of the target under simulated mass disturbance of [TBD]
(REQ7)The system shall asssume low-to-none deadtime
(REQ8)The system shall complete each control loop iteration within [TBD] milliseconds

##**Non-functional Requirements**

(REQ9)The system shall be written in C, conforming to the C99 standard
(REQ10)The system shall be written and maintained using an Agile approach

##**Interface Requirements**

The input is process variable, that is in this case elevation
The output is a control signal that tells the drone whether to go up or down