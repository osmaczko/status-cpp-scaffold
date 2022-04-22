#include "WalletEmulator.h"

using namespace statusgo;

WalletEmulator::WalletEmulator(std::shared_ptr<WalletEvents> walletEvents)
    : walletEvents(walletEvents) {}

void WalletEmulator::sendTransaction(const TransactionData &tranaction) {}
