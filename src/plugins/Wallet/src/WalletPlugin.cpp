#include <QDebug>
#include <QObject>
#include <QQmlEngine>
#include <QQmlEngineExtensionPlugin>

class WalletPlugin : public QQmlExtensionPlugin {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
  explicit WalletPlugin(QObject *parent = nullptr)
      : QQmlExtensionPlugin(parent) {
    static bool created = false;
    Q_ASSERT(!created); // ensure WalletPlugin is created only once
    created = true;
  }

  void registerTypes(const char *uri) override { qmlRegisterModule(uri, 1, 0); }
};

#include "WalletPlugin.moc"
