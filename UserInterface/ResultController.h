#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkScalarBarWidget.h>
#include <vtkScalarBarActor.h>
#include <vtkLookupTable.h>

#include "GraphicController.h"
#include "ResultModel.h"

//! A controller changing the style of GraphicsView, and displays results. 
/*!
	It sets up Graphicsview to use 3D, creates the color bar and the axisorientation actor.
*/
class ResultController : public GraphicController
{
	Q_OBJECT
public:
	ResultController(ResultModel*, QWidget*, QObject* parent = 0);
	~ResultController();

	/*!
		Sets the current resultmodel used and resets the view.
		It also connects model signals to the view.
	*/
	void setModel(ResultModel*);

	/*!
		Not implemented functionality in this view
	*/
	void actorClicked(vtkSmartPointer<vtkActor>){};
	/*!
		Not implemented functionality in this view
	*/
	void actorDoubleClicked(vtkSmartPointer<vtkActor>){};

	/*!
		Creates a result actor if model has resultdata, and resets the camera to display the actor.
	*/
	void createResultActor();
	
	/*!
		Creates a mesh actor if model has meshdata and resets the camera to display the actor.
	*/
	void createMeshActor();

public slots:
	/*!
		Removes all active actors from the GraphicsView and creating result actor, mesh actor and scalar bar actor.
	*/
	void reset();
	void invalidate();

	void createScalarBarActor();
	void setVisibility();

private:
	ResultModel *model;

	vtkSmartPointer<vtkActor> resultActor;
	vtkSmartPointer<vtkActor> meshActor;

	vtkSmartPointer<vtkAxesActor> axesActor;				//!< Actor displaying the axes orientation on the bottom left 
	vtkSmartPointer<vtkOrientationMarkerWidget> axesWidget;	//!< Widget holding the axes orientation actor

	vtkSmartPointer<vtkScalarBarActor> scalarBarActor;		//!< Scalar/color bar actor
	vtkSmartPointer<vtkScalarBarWidget> scalarBarWidget;	//!< Widget holding the scalar bar actor


	void createOrientationMarker();
	
};