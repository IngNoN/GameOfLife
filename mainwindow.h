#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QPushButton>

#include <vector>

using namespace std;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    vector<vector<int>> getPressedBtns();


private slots:
    void buildGrid();
public slots:
    void print(int i, int j);
    void startGame();

private:
    static constexpr int m_x_size = 12;
    static constexpr int m_y_size = 12;
    vector<vector<int>> m_pressed_btns;

    QPushButton *btns[m_x_size][m_y_size];

    void print_arr();



};
#endif // MAINWINDOW_H
