#include "level5.h"
#include "ui_level5.h"

level5::level5(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level5)
{
    ui->setupUi(this);
}

level5::~level5()
{
    delete ui;
}
