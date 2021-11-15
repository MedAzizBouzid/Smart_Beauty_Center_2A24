#ifndef PEICHARTWIDGET_H
#define PEICHARTWIDGET_H

#include <QWidget>

class peichartwidget : public QWidget
{
    Q_OBJECT
public:
    explicit peichartwidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *) ;

signals:

};

#endif // PEICHARTWIDGET_H
