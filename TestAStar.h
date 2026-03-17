#pragma once
#ifndef TESTASTAR_H
#define TESTASTAR_H

void RunTests();
void TestBasicPath();
void TestNoPath();
void TestStartIsGoal();
void TestOutOfBounds();
void TestStartOnObstacle();
void TestGoalOnObstacle();
void TestLargerGrid();
void TestWeightedGrid();
#endif