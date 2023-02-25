#pragma once
#include "NVNeuron.h"
class NVNeuronCircle : public NVNeuron
{
public:
	NVNeuronCircle(std::vector<float> w);
	NVNeuronCircle(std::vector<float> wx, std::vector<float> wy);
	NVNeuronCircle(float l_seglen, float l_size, std::vector<float> w, float l_breatheInterval, float l_breatheAmp, sf::Vector2f l_origin);
	~NVNeuronCircle();
	void Step();
};

