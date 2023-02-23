#include <SFML/Graphics.hpp>
//#include "Game.h"
#include "SimpleGrid.h"
#include "RotateRectangle.h"
#include "RotateGrid.h"
#include "IrregularCircle.h"
#include "NVNeuron.h"

void runSimpleGrid() {
	SimpleGrid simpleGrid(40, 40, 10, 10);
	while (!simpleGrid.GetWindow()->IsDone()) {
		// Game loop.
		simpleGrid.Update();
		simpleGrid.Render();
	}
}

void runRotateRectangle() {
	RotateRectangle rotateRectangle;
	while (!rotateRectangle.GetWindow()->IsDone()) {
		rotateRectangle.Update();
		rotateRectangle.ChangeRectLocation();
		rotateRectangle.Render();
	}
}

void runRorateGrid() {
	RotateGrid rotateGrid(10, 10, 50.f, 60.f, 10.f);
	rotateGrid.Run();
}

void runIrregularCircle() {
	std::vector<float> ampsx{ 120, 0, 0, 10 };
	//std::vector<float> ampsy{ 120, 0, 0, 10 };
	// std::vector<float> ampsx{ 120, 0, 0, 1 };
	// std::vector<float> ampsx{ 120, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	// std::vector<float> ampsx{ 120, 0, 0, 5 };
	
	IrregularCircle irregularCircle(0.01, ampsx);
	//IrregularCircle irregularCircle(0.01, ampsx, ampsy);
	irregularCircle.Run();
}

int main()
{
	runIrregularCircle();
}