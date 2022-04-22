#pragma once

#include "StatusGoInterface.h"

#include <memory>

class DependencyInjector {
public:
  virtual std::shared_ptr<statusgo::IChat> chat() const = 0;
  virtual std::shared_ptr<statusgo::ChatEvents> chatEvents() const = 0;
  virtual std::shared_ptr<statusgo::IWallet> wallet() const = 0;
  virtual std::shared_ptr<statusgo::WalletEvents> walletEvents() const = 0;

  static const DependencyInjector &instance() { return *injector; }

protected:
  DependencyInjector() = default;

  template <typename Factory>
  static void create(const Factory &createInjector) {
    Q_ASSERT(injector == nullptr);
    injector = createInjector();
  }

private:
  inline static std::unique_ptr<DependencyInjector> injector;
};
