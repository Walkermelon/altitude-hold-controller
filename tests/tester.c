/*
    This file will take in a list of balls and test the PID controller on each one.
    It will initialize the balls with specific PID parameters and then apply the PID 
    controller to each one.
    When the ball reaches a velocity that is greater than a certain threshold, the tester
    will be remove the ball from the list.
    When the tester finds a ball that settles, it will save the parameters of the ball.

\*/

#include "PID.h"
#include "ball.h"
#include "tester.h"
void testPIDController(BallList *ball_list) {
    BallNode *current = ball_list->node;
    while (current != NULL) {
        PID(current->ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        current = current->next;
    }
}