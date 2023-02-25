#include "IrregularCircle.h"
#include "NVNeuron.h"
#include "NVNeurons.h"

//Parameters:
// seglen(segment length),
// ampsx(amplitude for each phases at x)
// ampsy(amplitude for each phases at y axis)

IrregularCircle::IrregularCircle(float l_seglen, std::vector<float> l_amps) :
	m_window("Irregular Circle", sf::Vector2u(800, 600)),
	m_seglen(l_seglen), m_ampsx(l_amps), m_ampsy(l_amps)
{ }

IrregularCircle::IrregularCircle(float l_seglen, std::vector<float> l_ampsx, std::vector<float> l_ampsy) :
	m_window("Irregular Circle", sf::Vector2u(800, 600)),
	m_seglen(l_seglen), m_ampsx(l_ampsx), m_ampsy(l_ampsy)
{ }

IrregularCircle::~IrregularCircle(){ }

void IrregularCircle::Run() {
	//while (!GetWindow()->IsDone()) {
	//	Update();
	//	Render();
	//}
	
	//RunSingleCurve();
	//RunSingleCircle();
	//RunSimpleFourierCircle();
	//RunFourierCircle();
	//RunNVNeuron();
	RunNVNeurons();
}

void IrregularCircle::Render() { }

void IrregularCircle::Update() {
	m_window.Update();
	srand(time(NULL));
}

void IrregularCircle::Step()
{ }

void IrregularCircle::RestartClock() { m_elapsed = m_clock.restart(); }

sf::Time IrregularCircle::GetElapsedTime() { return m_clock.getElapsedTime(); }
Window* IrregularCircle::GetWindow() { return &m_window; }

void IrregularCircle::RunSingleCurve(){
	SetSingleCurve();
	DrawSingleCurve();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::SetSingleCurve() {
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip, 100);
	for (int x = 0; x < 100; x++)
	{
		m_curve[x].position = sf::Vector2f(10 * x + 50, 10 * -sin(x) + 400);
	}
}

void IrregularCircle::DrawSingleCurve(){
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}

void IrregularCircle::RunSingleCircle(){
	SetSingleCircle();
	DrawSigleCircle();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::SetSingleCircle()
{
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip, (int)(6.28/0.02));
	for (int x = 0; x < (int)(6.28 / 0.02); x++)
	{
		double xx = x * 0.02;
		m_curve[x].position.x = 100 * cos(xx) + 400;
		m_curve[x].position.y = 100 * sin(xx) + 300;
	}
}

void IrregularCircle::DrawSigleCircle() {
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}

void IrregularCircle::RunSimpleFourierCircle() {
	SetSimpleFourierCircle();
	DrawSimpleFourierCircle();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::SetSimpleFourierCircle() {
	m_curve = sf::VertexArray(sf::PrimitiveType::LinesStrip, (int)(6.28 / 0.02));
	for (int x = 0; x < (int)(6.29 / 0.02); x++)
	{
		double xx = x * 0.02;
		m_curve[x].position.x = 400 + 100 * cos(xx) + 50 * cos(2 * xx) + 70 * cos(4 * xx) + 20 * cos(8 * xx);
		m_curve[x].position.y = 400 + 100 * sin(xx) + 30 * sin(4 * xx) + 15 * sin(16 * xx);
	}
	// close the shape
	m_curve[(6.29 / 0.02)-1].position.x = m_curve[0].position.x;
	m_curve[(6.29 / 0.02)-1].position.y = m_curve[0].position.y;
}

void IrregularCircle::RunNVNeuron()
{
	//NVNeuron neuron(0.01f, 10.f, std::vector<float>{0.2, 0.2, 0.2, 0.2, -0.2});
	//neuron.SetOrigin(sf::Vector2f(400, 300));
	//neuron.SetClock(&m_clock);
	//neuron.SetWindow(&m_window);
	//neuron.SetNeuronCircleSize(80);
	//neuron.SetNeuronCurveSize(80);
	//neuron.SetBreatheAmp(3);
	//neuron.SetBreatheInterval(0.5);

	//while (!GetWindow()->IsDone()) {
	//	// Update
	//	m_window.Update();
	//	neuron.Step();
	//	srand(time(NULL));
	//	//Render
	//	m_window.BeginDraw();
	//	neuron.DrawNeuronCircle();
	//	neuron.DrawNeuronCurve();
	//	m_window.EndDraw();
	//}
}

void IrregularCircle::RunNVNeurons() {
	std::vector<std::vector<std::vector<float>>> weights 
	{
		//{{{0.2f, 0.2f, 0.2f, 0.2f, 0.2f}}}
		{{0.2f, 0.2f, 0.2f, 0.2f, 0.2f},
		{0.1f, 0.2f, 0.3f, 0.1f, 0.3f}},

		{{0.1f, 0.2f, 0.3f, 0.1f, 0.3f},
		{0.2f, 0.2f, 0.2f, 0.2f, 0.2f}}
	};

	NVNeurons neurons(&m_window, &m_clock, weights, sf::Vector2f(80.f, 400.f));
	neurons.SetMargin(120.f);
	neurons.Init();

	while (!GetWindow()->IsDone()) {
		m_window.Update();
		neurons.Step();
		srand(time(NULL));
		m_window.BeginDraw();
		neurons.Render();
		m_window.EndDraw();
	}

}

void IrregularCircle::DrawSimpleFourierCircle() {
	m_window.BeginDraw();
	m_window.Draw(m_curve);
	m_window.EndDraw();
}


void IrregularCircle::RunFourierCircle()
{
	SetFourierCircle();
	DrawFourierCircle();
	while (!GetWindow()->IsDone()) {
		Update();
		Render();
	}
}

void IrregularCircle::SetFourierCircle()
{
	int size = (int)(6.28 / m_seglen);
	int nterm = m_ampsx.size(); // TODO: make the max size and fill the small ones with 0s
	m_circle = sf::VertexArray(sf::PrimitiveType::LinesStrip, size);
	for (int i = 0; i < size; i++) {
		float x = 0.0f;
		float y = 0.0f;
		float seg = (float)i * m_seglen;
		for (int j = 0; j < nterm; j++) {
			float phase = pow(2.0, (float)j);
			//float phase = j;
			x += m_ampsx[j] * cos(phase * seg);
			y += m_ampsy[j] * sin(phase * seg);
		}
		m_circle[i].position.x = 400 + x;
		m_circle[i].position.y = 300 + y;
	}
	//Close the curve
	m_circle[size - 1].position.x = m_circle[0].position.x;
	m_circle[size - 1].position.y = m_circle[0].position.y;
}

void IrregularCircle::DrawFourierCircle()
{
	m_window.BeginDraw();
	m_window.Draw(m_circle);
	m_window.EndDraw();
}
