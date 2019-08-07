#ifndef __MYGLOBALS_H__
#define __MYGLOBALS_H__


TH1* ph1 = 0;  //who am i??? -> Pointer to histogram 1. Initialized here, as it's used later.

//Global variables for manual gaussian selection
int EXEC_CNT = 0;
int X1 = 0;
int X2 = 0;

int* PEXEC_CNT = &EXEC_CNT;
double  PX1 = sqrt(-1);
double  PX2 = sqrt(-1);



#endif
