#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <statusgo-emulator/Emulator.h>

int main(int argc, char *argv[]) {
  statusgo::Emulator::init();

  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  auto app = QGuiApplication{argc, argv};
  auto engine = QQmlApplicationEngine{};
  engine.addImportPath("./plugins");

  const auto url = QUrl(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) {
          QCoreApplication::exit(-1);
        }
      },
      Qt::QueuedConnection);
  engine.load(url);

  return QGuiApplication::exec();
}
