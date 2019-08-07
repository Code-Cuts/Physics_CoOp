void mouseclick()
{
 int event = gPad->GetEvent();
/*
 if(event != 11)
 {
  return;
 }
*/ 
 //Gets last x mouse position in canvas
 int xpos = gPad->GetEventX();

 //Gets currently selected object
 TObject *select = gPad->GetSelected();

 //If there is no selection, exit
 if(!select)
 {
  return;
 }

 //If the selection is of type TH1
 if(select->InheritsFrom(TH1::Class()))
 {
  TH1 *h = (TH1*)select;
  float xx = gPad->AbsPixeltoX(xpos);
  float x = gPad->PadtoX(xx);
  int binx = h->GetXaxis()->FindBin(x);
  printf("event=%d, hist:%s, bin=%d, content=%f\n",event,h->GetName(),binx,h->GetBinContent(binx));
 }





}
