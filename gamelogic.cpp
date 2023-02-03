#include "gamelogic.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

gameLogic::gameLogic(vector<vector<int>> pressed_btns)
{
    m_pressed_btns = pressed_btns;
}


vector<vector<int>> gameLogic::checkAliveNeighbours()
{
    vector<vector<int>> btns_to_remove;

    for (int cell_idx = 0; cell_idx < m_pressed_btns.size(); cell_idx++)
    {
        vector<vector<int>> alive_cells;
        vector<int> left_up_cell = {m_pressed_btns[cell_idx][0] + 1, m_pressed_btns[cell_idx][1]- 1};
        vector<int> up_cell = {m_pressed_btns[cell_idx][0] + 1, m_pressed_btns[cell_idx][1]};
        vector<int> right_up_cell = {m_pressed_btns[cell_idx][0] + 1, m_pressed_btns[cell_idx][1] + 1};
        vector<int> left_cell = {m_pressed_btns[cell_idx][0], m_pressed_btns[cell_idx][1] - 1};
        vector<int> right_cell = {m_pressed_btns[cell_idx][0], m_pressed_btns[cell_idx][1] + 1};
        vector<int> left_down_cell = {m_pressed_btns[cell_idx][0] - 1, m_pressed_btns[cell_idx][1] - 1};
        vector<int> down_cell = {m_pressed_btns[cell_idx][0] - 1, m_pressed_btns[cell_idx][1]};
        vector<int> right_down_cell = {m_pressed_btns[cell_idx][0] - 1, m_pressed_btns[cell_idx][1] + 1};


        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), left_up_cell))
        {
            alive_cells.push_back(left_up_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), up_cell))
        {
            alive_cells.push_back(up_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), right_up_cell))
        {
            alive_cells.push_back(right_up_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), left_cell))
        {
            alive_cells.push_back(left_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), right_cell))
        {
            alive_cells.push_back(right_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), left_down_cell))
        {
            alive_cells.push_back(left_down_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), down_cell))
        {
            alive_cells.push_back(down_cell);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), right_down_cell))
        {
            alive_cells.push_back(right_down_cell);
        }

        if(alive_cells.size() < 2 or alive_cells.size() > 3)
        {
            btns_to_remove.push_back({m_pressed_btns[cell_idx][0], m_pressed_btns[cell_idx][1]});
        }
    }
    return btns_to_remove;
}

vector<vector<int>> gameLogic::birthNeighbours()
{
    vector<vector<int>> cells_birth;
    vector<vector<int>> pushed_cells;
    vector<vector<vector<int>>> test;
    for (int i = 0; i < m_pressed_btns.size(); i++)
    {
        test.push_back(getNeighbours(m_pressed_btns[i]));
    }
    for (int i = 0; i < test.size(); i++)
    {
        for(int j = 0; j < test[i].size(); j++)
        {
            pushed_cells.push_back(test[i][j]);
        }

    }

    for (int current_cell = 0; current_cell < pushed_cells.size(); current_cell++)
    {
        vector<vector<int>> current_cell_neighbours = getNeighbours(pushed_cells[current_cell]);
        vector<vector<int>> alive_cells;
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[0]))
        {
            alive_cells.push_back(current_cell_neighbours[0]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[1]))
        {
            alive_cells.push_back(current_cell_neighbours[1]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[2]))
        {
            alive_cells.push_back(current_cell_neighbours[2]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[3]))
        {
            alive_cells.push_back(current_cell_neighbours[3]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[4]))
        {
            alive_cells.push_back(current_cell_neighbours[4]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[5]))
        {
            alive_cells.push_back(current_cell_neighbours[5]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[6]))
        {
            alive_cells.push_back(current_cell_neighbours[6]);
        }
        if (std::count(m_pressed_btns.begin(), m_pressed_btns.end(), current_cell_neighbours[7]))
        {
            alive_cells.push_back(current_cell_neighbours[7]);
        }

        if (alive_cells.size() == 3)
        {
            cells_birth.push_back(pushed_cells[current_cell]);
        }
    }
    return cells_birth;
}


vector<vector<int>> gameLogic::getNeighbours(vector<int> active_cell)
{
    vector<vector<int>> neighbour_cells;
    neighbour_cells.push_back({active_cell[0] + 1, active_cell[1]- 1});
    neighbour_cells.push_back({active_cell[0] + 1, active_cell[1]});
    neighbour_cells.push_back({active_cell[0] + 1, active_cell[1] + 1});
    neighbour_cells.push_back({active_cell[0], active_cell[1] - 1});
    neighbour_cells.push_back({active_cell[0], active_cell[1] + 1});
    neighbour_cells.push_back({active_cell[0] - 1, active_cell[1] - 1});
    neighbour_cells.push_back({active_cell[0] - 1, active_cell[1]});
    neighbour_cells.push_back({active_cell[0] - 1, active_cell[1] + 1});
    return neighbour_cells;
}







