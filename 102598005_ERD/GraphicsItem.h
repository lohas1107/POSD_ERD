#ifndef _GRAPHICSITEM_H_
#define _GRAPHICSITEM_H_

#include <QGraphicsItem>
#include "PresentationModel.h"
#include <string>

using namespace std;

enum Data {
	idData,
	textData
};

class GraphicsItem : public QGraphicsItem
{
public:
	GraphicsItem(PresentationModel* presentationModel);
	virtual ~GraphicsItem();
	virtual void doAdjustSize(QFontMetrics fontMetrics);
	QRectF boundingRect() const;
	QPainterPath shape() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

protected:
	PresentationModel* _presentationModel;
	QGraphicsItem* _item;
	bool _isSelected;
};

#endif