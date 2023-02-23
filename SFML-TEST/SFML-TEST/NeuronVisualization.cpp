#include "NeuronVisualization.h"

// Visualization for perceptrons and simple layer NNs

// Parameters:
// 1. neuron size as a circle
// 2. breathe mode?
// 3. vectors of neurons

// Class related:
// NV has NVNeuron (Visual)
// NV has NVNetwork (Model / real training)
// NV has NVControl (Control)
// NV has NVLib

// TODO:
// 1. draw neurons (NVNeuron)
// 2. organize neurons so that they are aligned well (NVNeuron)
// 3. make neurons breathe (NVNeuron)
// 4. implement neuron related algorithms? (NVNetwork)
// 5. make the update step-wise (NVControl)
// 6. Finally, possibly add a mouse button and more other functionalities

NeuronVisualization::NeuronVisualization()
{
}

NeuronVisualization::~NeuronVisualization()
{
}

void NeuronVisualization::Render()
{
}

void NeuronVisualization::Update()
{
}

void NeuronVisualization::RestartClock()
{
}

void NeuronVisualization::Step()
{
}

void NeuronVisualization::Run()
{
}

sf::Time NeuronVisualization::GetElapsedTime()
{
    return sf::Time();
}

Window* NeuronVisualization::GetWindow()
{
    return nullptr;
}
