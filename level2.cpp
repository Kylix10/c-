#include "level2.h"
#include "ui_level2.h"

level2::level2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level2)
{
    ui->setupUi(this);
}

level2::~level2()
{
    delete ui;
}
