#include "base.h"
#include <QPainter>

int Base::_imgNumber = 0;

Base::Base(const QString &name, QObject *parent) :
    QObject(parent)
{
    _name = name;
}

Base::~Base()
{
}

QString Base::name()
{
    return _name;
}

void Base::insertImage(QTextEdit *textEdit,
                       QGraphicsScene *scene)
{
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(0, 0, image.size().width(), image.size().height(), Qt::GlobalColor::white);
    scene->render(&painter);

    QUrl Uri (QString("file://%1").arg(_imgNumber));
    _imgNumber++;
    QTextDocument * textDocument = textEdit->document();
    textDocument->addResource( QTextDocument::ImageResource, Uri, QVariant ( image ) );
    QTextCursor cursor = textEdit->textCursor();
    QTextImageFormat imageFormat;
    imageFormat.setWidth( image.width() );
    imageFormat.setHeight( image.height() );
    imageFormat.setName( Uri.toString() );
    cursor.insertImage(imageFormat);
}
