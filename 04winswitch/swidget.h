#ifndef SWIDGET_H
#define SWIDGET_H

#include <QWidget>

class SWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SWidget(QWidget *parent = nullptr);

signals:
    void back();
};

#endif // SWIDGET_H
