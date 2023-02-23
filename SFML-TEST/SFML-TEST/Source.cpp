#include <SFML/Graphics.hpp>
//#include "Game.h"
#include "SimpleGrid.h"
#include "RotateRectangle.h"
#include "RotateGrid.h"
#include "IrregularCircle.h"

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
	std::vector<float> amps{60, 3, 10, 1, 1, 5};
	IrregularCircle irregularCircle(0.01, amps);
	irregularCircle.Run();
}

int main()
{
	runIrregularCircle();
}