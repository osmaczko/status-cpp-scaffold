#pragma once

#include "../StatusGoInterface.h"

#include <memory>

namespace statusgo {
class WalletEmulator : public IWallet {
public:
  explicit WalletEmulator(std::shared_ptr<WalletEvents> walletEvents);

  void sendTransaction(const TransactionData &tranaction) override;

private:
  std::shared_ptr<WalletEvents> walletEvents;
};
} // namespace statusgo
