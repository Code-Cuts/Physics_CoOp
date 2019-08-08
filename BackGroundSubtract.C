#include "TH1.h"
#include "TCanvas.h"
#include "TF1.h"

void BackGroundSubtract(TPad* p)
{
   TH1* h;
   TIter iter(p->GetListOfPrimitives());
   while(TObject *obj = iter.Next())
   {
       if(obj->InheritsFrom(TH1::Class()))
       {
         h = (TH1*)obj;
       }
   }
         

   if(!h->InheritsFrom(TArrayD::Class()))
       return;
   double* bins = ((TH1D*) h)->GetArray();

   double mu = h->GetMean(2);
   double sigma = h->GetMeanError(2);

   double m;  //y=mx+b ya dingus
   double b;

   double sumxy;
   double sumx;
   double sumy;
   double sumx2;

   for(int i = 0; i < h->GetNbinsX(); i++)
   {
      if(((bins[i] < mu + 2*sigma) && (bins[i] > mu - 2*sigma)))
      {
        sumxy += i*bins[i];
        sumx += i;
        sumy += bins[i];
        sumx2 += i*i;
      } 
   }

   m = (h->GetNbinsX() * sumxy - sumx * sumy)/(h->GetNbinsX() * sumx2 - sumx * sumx);
   b = (sumy - m * sumx)/(h->GetNbinsX());

   TF1* fit = new TF1("fit", "-[0]*x-[1]", 0, (int) h->GetNbinsX());
   fit->SetParameters(m, b);
   h->Add(fit);
}
