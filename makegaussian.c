using namespace std;

#include "num-entry.c"
#include "myglobals.h"

void makegaussian(int n){
	
	//User input for location and height
	int loc; //= get_location();
	int h; //= get_height();
	
	if(n==5)
	{
	 loc = 0;
	 h = 1;
	}
	else
	{
	 loc = get_location();
	 h = get_height();
	}

	//If the histogram is alreadly filled, reset it
	if(!ph1)
	{
	  ph1 = new TH1D("ph1","Control Bar Gaussian",1000,-10+loc,10+loc);
	  cout << "Made" << endl;
	}
	else
	{
	  ph1->Reset("ICESM");
	  cout << "Reset" << endl;
	}
	
	//Fills the Histogram with n Gaussians	
	switch(n)
	{
	  case 1:
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc));
	    break;
	  case 2:
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc-3));
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc+3));
	    break;
	  case 3:
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc-3));
            gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc));
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc+3));	
	    break;
	  case 4:
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc-6));
            gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc-3));
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc+3));
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",loc+6));
	    break;
	  case 5:
	    printf(".x fillgaussian.c(%i)\n",(int)(gRandom->Uniform()*100));
	    gROOT->ProcessLine(Form(".x fillgaussian.c(%i)",(int)(gRandom->Uniform(-8,8))));
	    break;
	  default:
	    cout << "makegaussian defaulted" << endl;	
	}

	//Scales the axis
	
	ph1->GetXaxis()->SetRangeUser(loc-8, loc+8);
	ph1->GetYaxis()->SetRangeUser(0, h*1.5);

	//Scales the histogram
	ph1->Scale(1/ph1->GetEntries());
	ph1->Scale(h);
	
	//Draws the histogram
	ph1->Draw();
}
