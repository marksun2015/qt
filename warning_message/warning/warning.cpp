#include <QGuiApplication>
#include <QQuickItem>
#include <QQuickView>

int main(int argc, char *argv[]) {
  QString message;
  message = QString(QLatin1String(argv[1]));
  QGuiApplication app(argc, argv);
  QQuickView *m_view = new QQuickView;

  /// Resize mode
  m_view->setResizeMode(QQuickView::SizeRootObjectToView);

  // set transparent and hide decorate
  // m_view->setClearBeforeRendering(true);
  // m_view->setColor(QColor(Qt::transparent));
  // m_view->setFlags(Qt::FramelessWindowHint);

  m_view->setSource(QUrl("qrc:/w_qml_pic/warning1.qml"));
  m_view->show();

  QObject *object = m_view->rootObject();
  object->setProperty("message", message);

  return app.exec();
}
