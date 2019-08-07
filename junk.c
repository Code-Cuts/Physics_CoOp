void junk()
{
   if (!gPad) {
      //Error("exec1", "gPad is null, you are not supposed to run this macro");
      printf("No\n");
      exit(1);
   }
   int event = gPad->GetEvent();
/*
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
   } 
*/
  printf("event=%d\n",event);
  return;
}
