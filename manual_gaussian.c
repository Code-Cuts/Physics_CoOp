using namespace std;
#include <unistd.h>

void findx(int* pxhold);

void manual_gaussian()
{
 printf("Opened\n");

 int x1;
 int x2;

 int* pxhold;
 *pxhold = -1;

 printf("Initialized\n");

 do{
    printf("Loop 1\n");
    findx(pxhold);
    sleep(1);
 }while(*pxhold == -1);

 x1 = *pxhold;

 *pxhold = -1;
 
 do{
    findx(pxhold);
 }while(*pxhold == -1);

 x2 = *pxhold;

 gROOT->ProcessLine(Form(".x fitgaussian.c(%f,%f)",(float) std::min(x1, x2),(float) std::max(x1,x2)));
}

void findx(int* pxhold)
{
   printf("Called\n");
   
   if (!gPad) {
      Error("exec1", "gPad is null, you are not supposed to run this macro");
      return;
   }

   int event;
/*
   while(event  != 11)
   {
    printf("Current event: %d\n",event);
    event  = gPad->GetEvent();
   }
*/
   if (event != 11)
   {
     printf("If event != 11\n");
     return;
   }

   int px = gPad->GetEventX();
   TObject *select = gPad->GetSelected();

   if (!select)
   {
     printf("If !select\n");
     return;
   }

   if (select->InheritsFrom(TH1::Class())) 
   {
      printf("If select inherits\n");
      TH1 *h = (TH1*)select;
      float xx = gPad->AbsPixeltoX(px);
      float x  = gPad->PadtoX(xx);
      int binx = h->GetXaxis()->FindBin(x);
      
      *pxhold = binx;

      return;
   }   
}
