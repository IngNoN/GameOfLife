#include "mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <iostream>
#include <QSignalMapper>
#include <iostream>

#include "gamelogic.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    buildGrid();
}

void MainWindow::buildGrid()
{
    QWidget *w = new QWidget();

    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    QGridLayout *gridLayout = new QGridLayout;


    for (int i = 0; i < 12; i++)
    {

        for(int j = 0; j < 12; j++)
        {
            QPushButton *btn = new QPushButton();
            btns[i][j] = btn;
            btns[i][j]->setObjectName(std::to_string(i + j));
            btns[i][j]->setStyleSheet("QPushButton {background-color : white}");
            connect(btn, &QPushButton::clicked, [=](){
                            emit print(i,j);
                        });


            gridLayout->addWidget(btns[i][j],i,j,1,1);
            print_arr();
        }
    }

    QPushButton *start_btn = new QPushButton;
    start_btn->setText("Start");
    connect(start_btn, SIGNAL(clicked()), SLOT(startGame()));

    vBoxLayout->addWidget(start_btn);
    vBoxLayout->addStretch();
    vBoxLayout->addLayout(gridLayout);

    w->setLayout(vBoxLayout);

    // Window title
    w->setWindowTitle("Game of Life");

    w->show();

}

void MainWindow::print_arr()
{
    return;
}

void MainWindow::print(int i, int j)
{

    vector<int> test;
    test.push_back(i);
    test.push_back(j);
    m_pressed_btns.push_back(test);
    test.clear();

    btns[i][j]->setStyleSheet("background-color : black");
}


void MainWindow::startGame()
{
    print_arr();
    gameLogic game_logic(m_pressed_btns);
    vector<vector<int>> test = game_logic.checkAliveNeighbours();
    vector<vector<int>> reborn_cells = game_logic.birthNeighbours();
    for (int i = 0; i < test.size(); i++)
    {
        m_pressed_btns.erase(remove(m_pressed_btns.begin(), m_pressed_btns.end(), test[i]), m_pressed_btns.end());
    }
    for (int i = 0; i < reborn_cells.size(); i++)
    {
        m_pressed_btns.push_back(reborn_cells[i]);
    }
    for (int i = 0; i < test.size(); i++)
    {
        int x = test[i][0];
        int y = test[i][1];
        if (x >= 0 and y >= 0)
        {
        btns[x][y]->setStyleSheet("background-color : white");
        }
    }
    for (int i = 0; i < reborn_cells.size(); i++)
    {
        int x = reborn_cells[i][0];
        int y = reborn_cells[i][1];
        if (x >= 0 and y >= 0)
        {
        btns[x][y]->setStyleSheet("background-color : black");
        }
    }
}



MainWindow::~MainWindow()
{
}

