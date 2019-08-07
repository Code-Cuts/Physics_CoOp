//EXEC_CNT is a global variable counting how many times an x position has been selected
//PX1 and PX2 are pointers to global variables that store the x positions recorded
//Globals are initialized in controlbar

#include "fitgaussian.c"
#include "myglobals.h"

using namespace std;

void exec4()
{
  //if(*PEXEC_CNT == 0) {
  if (!gPad) {
    Error("exec2", "gPad is null, you are not supposed to run this macro");
    return;
  }
  int event = gPad->GetEvent();
  if (event != 11) return;
  int px = gPad->GetEventX();
  TH1* h;
  TIter iter(gPad->GetListOfPrimitives());
  while(TObject *obj = iter.Next()) {
    if(obj->InheritsFrom(TH1::Class())) {
      h = (TH1*)obj;
      float xx = gPad->AbsPixeltoX(px);
      float x  = gPad->PadtoX(xx);
      int binx = h->GetXaxis()->FindBin(x);
      printf("event=%d, hist:%s, bin=%d, content=%f\n",event,h->GetName(),binx,h->GetBinContent(binx));

      PX2 = PX1;
      PX1 = h->GetXaxis()->GetBinCenter(binx);
      //*PEXEC_CNT = 1 + *PEXEC_CNT;
      break;    
    }
  }

  if(PX1==PX1 && PX2==PX2) {
    if(PX1>PX2) swap(PX1,PX2);
    //gROOT->ProcessLine(Form(".x fitgaussian.c(%f,%f)",PX1,PX2));
    //gROOT->ProcessLine(".L fitgaussian.c");
    fitgaussian(h, PX1, PX2);
    std::cout << "Made it" << endl;
    PX1 = sqrt(-1);
    PX2 = sqrt(-1);
  }

  return;


  /*
     TObject *select = gPad->GetSelected();
     if (!select) return;
     if (select->InheritsFrom(TH1::Class())) {
     TH1 *h = (TH1*)select;
     float xx = gPad->AbsPixeltoX(px);
     float x  = gPad->PadtoX(xx);
     int binx = h->GetXaxis()->FindBin(x);
     printf("event=%d, hist:%s, bin=%d, content=%f\n",event,h->GetName(),binx,h->GetBinContent(binx));

   *PX1 = binx;
   *PEXEC_CNT = 1 + *PEXEC_CNT;
   }

   } else if(*PEXEC_CNT == 1) {
   if (!gPad) {
   Error("exec2", "gPad is null, you are not supposed to run this macro");
   return;
   }
   int event = gPad->GetEvent();
   if (event != 11) return;
   int px = gPad->GetEventX();
   TObject *select = gPad->GetSelected();
   if (!select) return;
   if (select->InheritsFrom(TH1::Class())) {
   TH1 *h = (TH1*)select;
   float xx = gPad->AbsPixeltoX(px);
   float x  = gPad->PadtoX(xx);
   int binx = h->GetXaxis()->FindBin(x);
   printf("event=%d, hist:%s, bin=%d, content=%f\n",event,h->GetName(),binx,h->GetBinContent(binx));

   *PX2 = binx;
   *PEXEC_CNT = 1 + *PEXEC_CNT;
   }
   }

   else if(*PEXEC_CNT == 2)
   {

  //Convert bins to hist. Every 62.5  bins is 1 unit on the canvas, on which the his is 
  //bins [100,900] and units [-8,8]

  float x1_true, x2_true;

  x1_true = (*PX1/61.5)-8;
  x2_true = (*PX2/61.5)-8;

  gROOT->ProcessLine(Form(".x fitgaussian.c(%f,%f)",std::min(x1_true,x2_true),std::max(x1_true,x2_true)));

   *PEXEC_CNT = 1 + *PEXEC_CNT;
   }
   */
}
