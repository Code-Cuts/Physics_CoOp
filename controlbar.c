
#include "myglobals.h"

void controlbar() {

  TTimeStamp *time_gen = new TTimeStamp;
  unsigned long current_time = time_gen->GetSec();

  printf("%lu\n",current_time);

  TRandom *random_gen = new TRandom;
  random_gen->SetSeed(current_time);

  //gROOT->Reset();

  TControlBar *bar = new TControlBar("vertical");
  bar->AddButton("Gaussian 1",".x ~/sandbox/gaussian_button_project/makegaussian.c(1)","Makes a gaussian with 1 random variable");
  bar->AddButton("Gaussian 2",".x ~/sandbox/gaussian_button_project/makegaussian.c(2)","Makes a gaussian with 2 random variables");
  bar->AddButton("Gaussian 3",".x ~/sandbox/gaussian_button_project/makegaussian.c(3)","Makes a gaussian with 3 random variables");
  bar->AddButton("Gaussian 4",".x ~/sandbox/gaussian_button_project/makegaussian.c(4)","Makes a gaussian with 4 random variables");
  bar->AddButton("Random Gaussian",".x ~/sandbox/gaussian_button_project/makegaussian.c(5)","Makes a random 1 variable gaussian");
  bar->AddButton("Fit Histogram",".x ~/sandbox/gaussian_button_project/fitgaussian.c(-8.0,8.0)","Fits the histogram with default bounds");
  bar->AddButton("Find Peaks",".x ~/sandbox/gaussian_button_project/peakfind.c","Finds peaks in a histogram");
  bar->AddButton("Add Bin Finder", ".x ~/sandbox/gaussian_button_project/binfinder.c","Adds a TExec. Use LMB on a point to find information");
  bar->AddButton("Manual Gaussian",".x ~/sandbox/gaussian_button_project/call_exec.c","Use mouse to define gaussian");
  bar->AddSeparator();
  bar->AddButton("Close Root","gApplication->Terminate()","Closes bar and root");

  bar->SetButtonWidth(500);
  
  bar->Show();
  gROOT->SaveContext();

}
