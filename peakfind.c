//finds peaks from 1d spectra

using namespace std;

#include "TCanvas.h"
#include "TMath.h"
#include "TH1.h"
#include "TF1.h"
#include "TRandom.h"
#include "TSpectrum.h"
#include "TVirtualFitter.h"

#include <iostream>
#include <cstdlib>

void peakfind(void)
{
 //Get number of peaks. Temporary until a way is found to determine automatically
 int numpeaks = 10;
 //cout << "Enter the number of peaks: " << endl;
 //cin >> numpeaks; 
 
 //Use TSpectrum to find peak candidates
 double sigma = 2.0;
 double threshold = 0.10;

 TSpectrum *pspec = new TSpectrum(numpeaks);
 int numfound = pspec->Search(ph1,sigma,"",threshold);

 printf("Found %d candidate peaks to fit\n",numfound);

 //Allocate memory to place x positions in
 double* pxpeaks;
 pxpeaks = (double*) malloc(numfound*sizeof(double));

 if(!pxpeaks)
 {
  cout << "Memory allocation failed";
  exit(1);
 }

 //Get x positions
 pxpeaks = pspec->GetPositionX();
 //numfound is divided by 2 because the program makes double peaks as of now. MAGIC NUMBER
 for(int i = 0; i < numfound; i++)
 {
  //printf("X-position #%d: %f\n",i,pxpeaks[i]);
  printf("---GAUSSIAN #%d---\n",i+1);
  gROOT->ProcessLine(Form(".x fitgaussian.c(%f,%f)",pxpeaks[i]-sigma, pxpeaks[i]+sigma));
 }

 //Free memory
 free(pxpeaks);

/* This method only returns the first position, and no others
 //Get polymarkers
 TList *functions = ph1->GetListOfFunctions();
 TPolyMarker *pmark = (TPolyMarker*)functions->FindObject("TPolyMarker");

 //Get x-coordinates from polymarkers
 //double* xcord = pmark->GetX();
 int i;
 double* xcord[10] = {};
 for(i = 0; i < numpeaks; i++)
 {
  xcord[i] = 0;
 }
 for(i = 0; i < numfound; i++)
 {
  xcord[i] = pmark->GetX();
  printf("X-coord (%d): %f\n",i,*xcord[i]);
 }
*/
}
