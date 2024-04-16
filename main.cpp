#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QCheckBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.setWindowTitle("Qwerty");
    // w.show();

    QWidget widget;
    QVBoxLayout *layout = new QVBoxLayout(&widget);

    // QPushButton b1("Pranav");
    // b1.show();
    // b1.setWindowTitle("Going2Heven");

    // QCheckBox check("QWERTY");
    // check.show();
    // check.setWindowTitle("Check box qwerty");

    // QRadioButton radio1("Radio 1");
    // QRadioButton radio2("Radio 2");

    // layout -> addWidget(&radio1);
    // layout -> addWidget(&radio2);

    // widget.show();

    QSlider *slider = new QSlider(Qt::Horizontal, &widget);
    slider->setRange(0, 100);
    layout -> addWidget(slider);

    QLabel *label = new QLabel("Slider Value: 0", &widget);
    layout -> addWidget(label);

    QObject::connect(slider, &QSlider::valueChanged, [&label](int value) {
        label -> setText("Slider Value: " + QString::number(value));
    });

    widget.show();

    qDebug() << "Before exec";
    a.exec();
    qDebug() << "After exec";

    return 1;
}
