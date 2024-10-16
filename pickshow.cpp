#include "pickshow.h"
#include "ui_pickshow.h"

pickshow::pickshow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pickshow)
{
    ui->setupUi(this);
}

pickshow::~pickshow()
{
    delete ui;
}
