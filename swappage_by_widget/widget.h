#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPainter>
#include <QGLWidget>
//#include <QWidget>
#include <QImage>

class Widget : public QGLWidget
{
	Q_OBJECT

	public:
		Widget(QWidget *parent = 0);
		void paintEvent(QPaintEvent *);
		int count=200;
		int category=0;
		int time_Diff;   
		int text_Diff;   
		int svg_Diff;   
		int png_Diff;   
		float spendtime=0; 
		QPixmap img;
		QPixmap pngimg1;
		QPixmap pngimg2;
		QPixmap pngimg3;
		QPixmap svgimg1;
		QPixmap svgimg2;
		QPixmap svgimg3;
	
#if 0
		QImage Qimgpng1;
		QImage Qimgpng2;
		QImage Qimgpng3;
#endif

};

#endif 
