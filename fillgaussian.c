void fillgaussian(int location)
  {

  //ph1->FillRandom("gaus",1000000);
  TRandom* r = new TRandom();
  for(int i = 0; i<10000000; i++)
   {
    ph1->Fill(r->Gaus(location,1));
   }

  }
