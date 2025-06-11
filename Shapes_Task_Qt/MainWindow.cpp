#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    std::cout << "MainWindow Constructor Called" << std::endl;

    setupCentralWidget();
    setupConnections();
}
void MainWindow::setupCentralWidget()
{
    cout<<"MainWindow setupCentralWidget function called "<<endl;
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *mainLayout = new QHBoxLayout(central);

    shapeSelector = new ShapeSelectorWidget();
    shapeOptions = new ShapeOptionsWidget();
    drawArea = new DrawAreaWidget();
    drawArea->setFixedSize(350, 350);

    mainLayout->addWidget(shapeSelector, 0);
    mainLayout->addWidget(drawArea, 1);
    mainLayout->addWidget(shapeOptions, 0);
}
void MainWindow::setupConnections()
{
    cout<<"MainWindow setupConnections function called "<<endl;

    connect(shapeSelector, &ShapeSelectorWidget::shapeSelected, this, [=](int type)
            {
                int defaultPenWidth = 2;
                QColor defaultBorderColor = Qt::black;
                QColor defaultFillColor = Qt::white;

                drawArea->setPenWidth(defaultPenWidth);
                drawArea->setBorderColor(defaultBorderColor);
                drawArea->setFillColor(defaultFillColor);

                shapeOptions->setPenWidth(defaultPenWidth);
                shapeOptions->setBorderColor(defaultBorderColor);
                shapeOptions->setFillColor(defaultFillColor);

                drawArea->setShape(static_cast<DrawAreaWidget::Shape>(type));
            });

    connect(shapeOptions, &ShapeOptionsWidget::penWidthChanged, drawArea, &DrawAreaWidget::setPenWidth);
    connect(shapeOptions, &ShapeOptionsWidget::borderColorChanged, drawArea, &DrawAreaWidget::setBorderColor);
    connect(shapeOptions, &ShapeOptionsWidget::fillColorChanged, drawArea, &DrawAreaWidget::setFillColor);
}


MainWindow::~MainWindow()
{
    cout<<"MainWindow Destructor Called"<<endl;

}
