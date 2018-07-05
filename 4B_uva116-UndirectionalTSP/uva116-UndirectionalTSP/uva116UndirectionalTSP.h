#pragma once

void ReadInputToGraph();

void PrintPath(int &r, int best);

void StartRecursion(int &best, int &r);

int DynamicRecursion(int i, int j);