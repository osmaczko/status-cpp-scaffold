#pragma once

#include <QObject>
#include <QString>

namespace statusgo {
struct MessageData {
  QString id;
  QString content;
  QString fromPubkey;
};

struct ChatData {
  QString id;
  QString name;
};

class IChat {
public:
  virtual void getAllChats() = 0;
  virtual void getMessages(const QString &chatId) = 0;
  virtual void sendMessage(const QString &chatId,
                           const MessageData &message) = 0;
};

class ChatEvents : public QObject {
  Q_OBJECT

public:
  using QObject::QObject;

signals:
  void chatsReceived(const std::vector<ChatData> &chats) const;
  void messagesReceived(const QString &chatId,
                        const std::vector<MessageData> &messages) const;
};

struct TransactionData {
  QString id;
  QString fromAddress;
  QString toAddress;
  QString coinType;
  int amount;
};

class IWallet {
public:
  virtual void sendTransaction(const TransactionData &tranaction) = 0;
};

class WalletEvents : public QObject {
  Q_OBJECT

public:
  using QObject::QObject;

signals:
  void transactionFailed(const TransactionData &transaction,
                         const QString &reason) const;
  void transactionSucceed(const TransactionData &transaction) const;
  void transactionReceived(const TransactionData &transaction) const;
};

} // namespace statusgo
