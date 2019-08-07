using namespace std;

void fitgaussian(TH1* hist, float min, float max)
{
 cout << "Called" << endl;
 hist->Fit("gaus","","",min,max);
 //Canvas_1->Fit("gaus","","",min,max);
}
