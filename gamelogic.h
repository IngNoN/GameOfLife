#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <iostream>
#include <vector>

using namespace std;

class gameLogic
{
public:
    gameLogic(vector<vector<int>> pressedBtns);
    vector<vector<int>> checkAliveNeighbours();
    vector<vector<int>> birthNeighbours();
    vector<vector<int>> getNeighbours(vector<int> active_cell);

private:
    vector<vector<int>> m_pressed_btns;


};

#endif
