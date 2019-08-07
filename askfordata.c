#include <TGClinet.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <TRootEmbeddedCanvas.h>
#include <RQ_OBJECT.h>

class InputFrame
{
	RQ_OBJECT("InputFrame")
private:
	TGMainFrame *fMain;
	TRootEmbeddedCanvas *fEcanvas;
public:
	InputFrame(const TGWindow *p, UInt_t w, UInt_t h);
	virtual ~InputFrame();
	void DoDraw();
};

InputFrame::InputFrame(const TGWindow *p, UInt_t w, UInt_t h) 
{
	//Create a frame
	fMain = new TGMainFrame(p,w,h);

	//Create canvas
}
