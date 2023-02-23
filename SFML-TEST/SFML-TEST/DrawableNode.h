#pragma once
#include "Window.h"

class DrawableNode
{
public:
	sf::Drawable* m_drawable;
	std::vector<DrawableNode*> children;
	sf::Drawable* GetNode();
	std::vector<DrawableNode*> GetChildren();
	void AddChild();
	void Next();
	void RemoveChild(DrawableNode* l_child);
};

