#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ShapeSelectorWidget.h"
#include "ShapeOptionsWidget.h"
#include <QHBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QColorDialog>
#include "DrawAreaWidget.h"
#include <iostream>
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupCentralWidget();
    void setupConnections();

    DrawAreaWidget *drawArea;
    ShapeSelectorWidget *shapeSelector;
    ShapeOptionsWidget *shapeOptions;
    QSpinBox *penWidthBox;
};

#endif // MAINWINDOW_H
