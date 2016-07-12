#include <QDebug>
#include "myimage.h"

QTime durationtime;

MyImage::MyImage(QQuickItem *parent) : QQuickPaintedItem(parent)
{
	count=600;
	durationtime.start();
	
	Qimgsvg1.load("penguin.svg", "SVG");    
	Qimgsvg2.load("simpson.svg", "SVG");    
	Qimgsvg3.load("ubuntu_cof.svg", "SVG") ;    
	
	Qimgpng1.load("mario.png", "PNG");    
	Qimgpng2.load("mushroom2.png", "PNG");    
	Qimgpng3.load("sitara-am335x-chip.png", "PNG");    

    setImplicitWidth(1024);
    setImplicitHeight(600);
}

void MyImage::paint(QPainter *painter)
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

	if((count%3)==0){
		if(category==0){
			QColor color(0xFF, 0x00, 0x00);
			painter->setPen(color); 
			painter->setBrush(QBrush(color)); 
			painter->setFont(QFont("Arial",24,QFont::Normal)); 
			for(int i=0;i<3;i++)
			{
				for(int j=1;j<=12;j++)
				{
					painter->drawText(i*340, j*40,"helloworld helloworld ");   
				}
			}
		}else if(category==1){
			Qimgsvg1.scaled(1024,600);
			painter->drawImage(0, 0, Qimgsvg1);
		}else if(category==2){
			Qimgpng1.scaled(1024,600,Qt::KeepAspectRatio);
			painter->drawImage(0,0, Qimgpng1);
		}
	}else if((count%3)==1){	
		if(category==0){
			QColor color(0xFF, 0x00, 0x00);
			painter->setPen(color); 
			painter->setBrush(QBrush(color)); 
			painter->setFont(QFont("Arial",24,QFont::Normal)); 
			for(int i=0;i<3;i++)
			{
				for(int j=1;j<=12;j++)
				{
					painter->drawText(i*340, j*40,"weinteklab weinteklab ");   
				}
			}
		}else if(category==1){
			Qimgsvg2.scaled(1024,600);
			painter->drawImage(0, 0, Qimgsvg2);
		}else if(category==2){
			Qimgpng2.scaled(1024,600,Qt::KeepAspectRatio);
			painter->drawImage(0,0, Qimgpng2);
		}
	}else{
		if(category==0){
			QColor color(0xFF, 0x00, 0x00);
			painter->setPen(color); 
			painter->setBrush(QBrush(color)); 
			painter->setFont(QFont("Arial",24,QFont::Normal)); 
			for(int i=0;i<3;i++)
			{
				for(int j=1;j<=12;j++)
				{
					painter->drawText(i*340, j*40,"omap335x omap335x ");   
				}
			}
		}else if(category==1){
			Qimgsvg3.scaled(1024,600);
			painter->drawImage(0, 0, Qimgsvg3); 
		}else if(category==2){
			Qimgpng3.scaled(width(), height(),Qt::KeepAspectRatio);
			painter->drawImage(0,0, Qimgpng3);
		}
	}

    //QImage secondImage("mario.png");
    //secondImage = secondImage.mirrored(false, true);
    //firstImage = firstImage.scaled(width(), height(),Qt::KeepAspectRatio);
    //secondImage = secondImage.scaled(width(), height(),Qt::KeepAspectRatio);
	count--;
	
	//qDebug() << "paint" << count;
    //painter->setOpacity(0.5);
	
	if(count==0){
		time_Diff = durationtime.elapsed(); 
		png_Diff = time_Diff-(svg_Diff+text_Diff); 
		qDebug() << "png cost time: " << png_Diff/1000.0;  
		qDebug() << "cost time: " << time_Diff/1000.0;  
		spendtime += time_Diff/1000.0; 
		QString tr_timeDiff = QString("%1").arg(spendtime);   
	}else{
		update();
	}
}
