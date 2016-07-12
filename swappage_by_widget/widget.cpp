#include <QLabel>
#include <QThread>
#include <QDebug>
#include "widget.h"

extern QImage myImage;
QTime durationtime;

Widget::Widget(QWidget *parent) :
	QGLWidget(parent)
{
	count=600;
	durationtime.start();
	setAutoFillBackground(true);  
	setAttribute(Qt::WA_NoSystemBackground); 
	
	svgimg1.load("penguin.svg", "SVG");    
	svgimg2.load("simpson.svg", "SVG");    
	svgimg3.load("ubuntu_cof.svg", "SVG");    
	
	pngimg1.load("mario.png", "PNG");    
	pngimg2.load("mushroom2.png", "PNG");    
	pngimg3.load("sitara-am335x-chip.png", "PNG");    

#if 0	
	Qimgpng1.load("mario.png", "PNG");    
	Qimgpng2.load("mushroom2.png", "PNG");    
	Qimgpng3.load("sitara-am335x-chip.png", "PNG");    
	
	Qimgpng1=Qimgpng1.scaled(1024,600);    
	Qimgpng2=Qimgpng2.scaled(1024,600);    
	Qimgpng3=Qimgpng3.scaled(1024,600);    
#endif	
	
	QTimer::singleShot(200, this, SLOT(repaint()));  
}

void Widget::paintEvent(QPaintEvent *)
{
	if(count==400){
		time_Diff = durationtime.elapsed(); 
		text_Diff = time_Diff; 
		qDebug() << "Text cost time: " << text_Diff/1000.0;  
		category=1;

	}else if(count==200){
		time_Diff = durationtime.elapsed(); 
		svg_Diff = time_Diff-text_Diff; 
		qDebug() << "svg cost time: " << svg_Diff/1000.0;  
		category=2;
	}
	
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true); 	
		
	if((count%3)==0){
		if(category==0){
			QColor color(0xFF, 0x00, 0x00);
			painter.setPen(color); 
			painter.setBrush(QBrush(color)); 
			painter.setFont(QFont("Arial",24,QFont::Normal)); 
			for(int i=0;i<3;i++)
			{
				for(int j=1;j<=12;j++)
				{
					painter.drawText(i*340, j*40,"helloworld helloworld ");   
				}
			}
		}else if(category==1){
			svgimg1=svgimg1.scaled(1024,600);
			painter.drawPixmap(0, 0, svgimg1);
		}else if(category==2){
			pngimg1=pngimg1.scaled(1024,600);
			painter.drawPixmap(0, 0, pngimg1); 
			//painter.drawImage(0,0,Qimgpng1); 
		}
	}else if((count%3)==1){
		if(category==0){
			QColor color(0xFF, 0x00, 0x00);
			painter.setPen(color); 
			painter.setBrush(QBrush(color)); 
			painter.setFont(QFont("Arial",24,QFont::Normal)); 
			for(int i=0;i<3;i++)
			{
				for(int j=1;j<=12;j++)
				{
					painter.drawText(i*340, j*40,"weinteklab weinteklab ");   
				}
			}
		}else if(category==1){
			svgimg2=svgimg2.scaled(1024,600);
			painter.drawPixmap(0, 0, svgimg2); 
		}else if(category==2){
			pngimg2=pngimg2.scaled(1024,600);
			painter.drawPixmap(0, 0, pngimg2); 
			//painter.drawImage(0,0,Qimgpng2); 
		}
	}else{
		if(category==0){
			QColor color(0xFF, 0x00, 0x00);
			painter.setPen(color); 
			painter.setBrush(QBrush(color)); 
			painter.setFont(QFont("Arial",24,QFont::Normal)); 
			for(int i=0;i<3;i++)
			{
				for(int j=1;j<=12;j++)
				{
					painter.drawText(i*340, j*40,"omap335x omap335x ");   
				}
			}
		}else if(category==1){
			svgimg3=svgimg3.scaled(1024,600);
			painter.drawPixmap(0, 0, svgimg3); 
		}else if(category==2){
			pngimg3=pngimg3.scaled(1024,600);
			painter.drawPixmap(0, 0, pngimg3); 
			//painter.drawImage(0,0,Qimgpng3); 
		}
	}
	
	count--;

	if(count==0){
		time_Diff = durationtime.elapsed(); 
		png_Diff = time_Diff-(svg_Diff+text_Diff); 
		qDebug() << "png cost time: " << png_Diff/1000.0;  
		qDebug() << "cost time: " << time_Diff/1000.0;  
		spendtime += time_Diff/1000.0; 
		QString tr_timeDiff = QString("%1").arg(spendtime);   
		
	}else{
		update();
		//QTimer::singleShot(500, this, SLOT(repaint()));
	}
} 

