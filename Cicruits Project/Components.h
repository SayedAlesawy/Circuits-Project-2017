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

struct NewNode
{
	int Number;
	vector<Component *>Resistors;
	vector<Component *>CurrentSource;
	vector<Component *>VoltageSource;
};

void LoadFile(vector<Node> &Circuit, vector<Component>&Resistors, vector<Component>&VoltageSources, vector<Component>&CurrentSources);

int WhichNodeIsConnected(vector<Node>Circuit, int FirstNode, string name);

void UpgradingTerminals(vector<Node>&Circuit);

void UpgradingVectors(vector<Node>Circuit, vector<Component>&Resistors, vector<Component>&VoltageSources, vector<Component>&CurrentSources);

vector <NewNode>TheCircuitIs(vector<Node>Circuit, vector<Component> &VoltageSources, vector<Component> &CurrentSources, vector<Component>&Resistors);

void ConnectElementsToNode(vector<NewNode>&Circuit, vector<Component> &VoltageSources, vector<Component> &CurrentSources,
	vector<Component>&Resistors, int i, vector<Component>Aux, int SizeOfNodes);

int GetTheIndex(string name, vector<Component> Objects);

bool FirstAppear(string name, vector<Component>Aux);

bool CheckEssential(Node* node);
double CalculateG(Node* node);
double CalculateMutualG(Node* node1, Node* node2);
double CalculateCurrent(Node* node);
double CalculateMutualCurrent(Node* node1, Node* node2);
MatrixXd BuildMatrixG(vector<Node> nodes);
MatrixXd BuildMatrixI(vector<Node> nodes);
MatrixXd GetMatrixV(MatrixXd G, MatrixXd I);
