#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkCommand.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataMapper.h>
#include <vtkSeedWidget.h>
#include "vtkSeedWidget.h"
#include "vtkSeedRepresentation.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCommand.h"
#include "vtkInteractorEventRecorder.h"
#include "vtkCoordinate.h"
#include "vtkMath.h"
#include "vtkHandleWidget.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkAxisActor2D.h"
#include "vtkProperty2D.h"
#include "vtkOrientedPolygonalHandleRepresentation3D.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkProperty.h"
#include "vtkGlyphSource2D.h"
#include "vtkPolyData.h"

#ifndef VTKCALLBACK
#define VTKCALLBACK

class vtkSeedCallback : public vtkCommand
{
public:
	static vtkSeedCallback *New()
	{
		return new vtkSeedCallback;
	}

	vtkSeedCallback() {};

	void SetRepresentation(vtkSmartPointer<vtkSeedRepresentation>);

	vtkSmartPointer<vtkSeedRepresentation> SeedRepresentation;

	virtual void Execute(vtkObject*, unsigned long event, void *calldata)
	{
		if (event == vtkCommand::PlacePointEvent)
		{
			std::cout << "Point placed, total of: "
				<< this->SeedRepresentation->GetNumberOfSeeds() << std::endl;
		}
		if (event == vtkCommand::InteractionEvent)
		{
			if (calldata)
			{
				std::cout << "Interacting with seed : "
					<< *(static_cast< int * >(calldata)) << std::endl;
			}
		}

		std::cout << "List of seeds (Display coordinates):" << std::endl;
		for (vtkIdType i = 0; i < this->SeedRepresentation->GetNumberOfSeeds(); i++)
		{
			double pos[3];
			this->SeedRepresentation->GetSeedDisplayPosition(i, pos);
			std::cout << "(" << pos[0] << " " << pos[1] << " " << pos[2] << ")" << std::endl;
		}
	}
};

#endif