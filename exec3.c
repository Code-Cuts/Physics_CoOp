using namespace std;

int findX();
//TH1* findHist();


void exec3()
{
   int x_1, x_2;
   do{
      x_1 = findX();
   }while(x_1 == -1);

   do{
      x_2 = findX();
   }while(x_2 == -1);

   double x1 = (double)std::min(x_1, x_2);
   double x2 = (double)std::max(x_1, x_2);

   gROOT->ProcessLine(Form(".x fitgaussian.c(%f,%f)",x1,x2));


   
   /*
   if (!gPad) {
      Error("exec3", "gPad is null, you are not supposed to run this macro");
      return;
   }
   int event = gPad->GetEvent();
   if (event != 11) return;
   int px = gPad->GetEventX();
   TObject *select = gPad->GetSelected();
   if (!select) return;
   if (select->InheritsFrom(TH1::Class())) {
      int x1,x2;
      TH1 *h = (TH1*)select;
      float xx = gPad->AbsPixeltoX(px);
      float x  = gPad->PadtoX(xx);
      int binx = h->GetXaxis()->FindBin(x);
      printf("event=%d, hist:%s, bin=%d, content=%f\n",event,h->GetName(),binx,h->GetBinContent(binx));

      x1 = binx;
      //x2 = x1 + 100;
      

      while(x2 == 0){
	if(gPad->getEvent() == 11)
		x2 = h->GetXaxis()->FindBin(gPad->PadtoX(gPad->AbsPixeltoX(gPad->GetEventX())));
      }
      

      printf("Min Bin = %d\n",std::min(x1,x2));
      printf("Max Bin = %d\n",std::max(x1,x2));

      //Convert bins to hist. Every 62.5  bins is 1 unit on the canvas, on which the his is 
      //bins [100,900] and units [-8,8]

      float x1_true, x2_true;
 
      x1_true = (x1/61.5)-8;
      x2_true = (x2/61.5)-8;

      gROOT->ProcessLine(Form(".x fitgaussian.c(%f,%f)",std::min(x1_true,x2_true),std::max(x1_true,x2_true)));
   } */
}

int findX()
{
    if(!gPad) {
        Error("findX", "gPad is null, there is no X to find");
	return -1;
    }

    int event = gPad->GetEvent();
    if(event != 11) return -1;
    
    TObject* select = gPad->GetSelected();
    if(!select) return -1;
    if(!select->InheritsFrom(TH1::Class())) return -1;
    TH1* h = (TH1*)select;
    int px = gPad->GetEventX();
        if(select->InheritsFrom(TH1::Class())) {
	    int out;
	    float xx = gPad->AbsPixeltoX(px);
	    float x = gPad->PadtoX(xx);
	    out = h->GetXaxis()->FindBin(x);
	    return out;
	}
    return -1;
}


/*
TH1* findHist(){
    if(!gPad) {
	Error("findHist", "gPad is null, what histogram are you looking for");
	return 0;
    }

    int event = gPad->GetEvent();
    if(event != 11) return 0;
    TObject* select = gPad->GetSelected();
    if(!select) return 0;
    if(select->InheritsFrom(TH1::Class())) return (TH1*)select;
    return 0;    
} 

*/






















