#include "ShapeSelectorWidget.h"
#include <QVBoxLayout>

ShapeSelectorWidget::ShapeSelectorWidget(QWidget *parent)
    : QWidget(parent)
{
    cout << "ShapeSelectorWidget Constructor Called" << endl;
    setupUI();
    setupConnections();
}

ShapeSelectorWidget::~ShapeSelectorWidget()
{
    cout<<"ShapeSelectorWidget Destructor Called"<<endl;

}
void ShapeSelectorWidget::setupUI()
{
    cout << "ShapeSelectorWidget setupUI fun Called" << endl;

    QVBoxLayout *layout = new QVBoxLayout(this);

    rectBtn = new ShapeButton(Shape_Rectangle);
    circleBtn = new ShapeButton(Shape_Circle);
    triangleBtn = new ShapeButton(Shape_Triangle);
    squareBtn = new ShapeButton(Shape_Square);

    layout->addWidget(rectBtn);
    layout->addWidget(circleBtn);
    layout->addWidget(triangleBtn);
    layout->addWidget(squareBtn);
}
void ShapeSelectorWidget::setupConnections()
{
    cout << "ShapeSelectorWidget setupConnections fun Called" << endl;

    connect(rectBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Rectangle);
    });

    connect(circleBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Circle);
    });

    connect(triangleBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Triangle);
    });

    connect(squareBtn, &QPushButton::clicked, this, [=]() {
        emit shapeSelected(Shape_Square);
    });
}
