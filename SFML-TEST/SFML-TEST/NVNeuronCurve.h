#pragma once
#include "NVNeuron.h"
class NVNeuronCurve :
    public NVNeuron
{
public:
	NVNeuronCurve(std::vector<float> w);
	NVNeuronCurve(std::vector<float> wx, std::vector<float> wy);
	NVNeuronCurve(float l_seglen, float l_size, std::vector<float> w, float l_breatheInterval, float l_breatheAmp, sf::Vector2f l_origin);
	~NVNeuronCurve();
	void Step();
};

