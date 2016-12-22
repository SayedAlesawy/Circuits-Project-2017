#pragma once
#include "Libraries.h"

struct Component
{
	float Magnitude;
	string Label;
	int Terminal1;
	int Terminal2;
};


struct Node
{
	int Number;
	vector<Component>Resistors;
	vector<Component>CurrentSource;
	vector<Component>VoltageSource;
};

bool checkEssential(Node* node);
double CalculateMutualG(Node* node1, Node* node2);
double CalculateCurrent(Node* node);
double CalculateMutualCurrent(Node* node1, Node* node2);