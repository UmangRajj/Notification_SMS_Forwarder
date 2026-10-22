#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->repeatTime->setTime(QTime(1, 30));
    ui->repeatTime->setMaximumTime(QTime(24, 0));

    connect(ui->serviceToggleBtn, &QPushButton::toggled, [this] (const bool &checked) {
        if (checked) {
            ui->serviceToggleBtn->setText("Stop Service");
        } else {
            ui->serviceToggleBtn->setText("Start Service");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
