#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QImage>

#include <QQuickPaintedItem>
#include <QQuickItem>
#include <QPainter>

class MyImage : public QQuickPaintedItem
{
	Q_OBJECT

	public:
		explicit MyImage(QQuickItem *parent = 0);
		void paint(QPainter* painter) override;
		int count;
		int category=0; 
		int time_Diff; 
		int text_Diff;     
		int svg_Diff;       
		int png_Diff;
		float spendtime=0;

		QImage Qimgsvg1;
		QImage Qimgsvg2;
		QImage Qimgsvg3;
		QImage Qimgpng1;
		QImage Qimgpng2;
		QImage Qimgpng3;
	signals:    
	public slots:   
};

#endif // MYIMAGE_H

