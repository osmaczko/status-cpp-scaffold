#pragma once

#include "../DependencyInjector.h"
#include "ChatEmulator.h"
#include "WalletEmulator.h"

namespace statusgo {
class Emulator {
public:
  Emulator() = delete;

  static void init() { Injector::create(); }

private:
  class Injector : public DependencyInjector {
  public:
    Injector()
        : chatEventsInst(std::make_shared<ChatEvents>()),
          chatImpl(std::make_shared<ChatEmulator>(chatEventsInst)),
          walletEventsInst(std::make_shared<WalletEvents>()),
          walletImpl(std::make_shared<WalletEmulator>(walletEventsInst)) {}
    std::shared_ptr<IChat> chat() const override { return chatImpl; }
    std::shared_ptr<ChatEvents> chatEvents() const override {
      return chatEventsInst;
    }
    std::shared_ptr<IWallet> wallet() const override { return walletImpl; }
    std::shared_ptr<WalletEvents> walletEvents() const override {
      return walletEventsInst;
    }

    static void create() {
      DependencyInjector::create([] { return std::make_unique<Injector>(); });
    }

  private:
    std::shared_ptr<ChatEvents> chatEventsInst;
    std::shared_ptr<IChat> chatImpl;
    std::shared_ptr<WalletEvents> walletEventsInst;
    std::shared_ptr<IWallet> walletImpl;
  };
};
} // namespace statusgo
