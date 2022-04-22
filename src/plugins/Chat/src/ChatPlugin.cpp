#include <QDebug>
#include <QObject>
#include <QQmlEngine>
#include <QQmlEngineExtensionPlugin>

class ChatModule : public QObject {
  Q_OBJECT

public slots:
  void openWallet() { qDebug() << "Hello from wallet"; }
};

class ChatPlugin : public QQmlExtensionPlugin {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
  explicit ChatPlugin(QObject *parent = nullptr) : QQmlExtensionPlugin(parent) {
    static bool created = false;
    Q_ASSERT(!created); // ensure ChatPlugin is created only once
    created = true;
  }

  void registerTypes(const char *uri) override {
    qmlRegisterSingletonType<ChatModule>(
        uri, 1, 0, "Module", [](auto, auto) { return new ChatModule; });
  }
};

#include "ChatPlugin.moc"
