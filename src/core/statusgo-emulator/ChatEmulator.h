#pragma once

#include "../StatusGoInterface.h"

#include <memory>

namespace statusgo {
class ChatEmulator : public IChat {
public:
  explicit ChatEmulator(std::shared_ptr<ChatEvents> chatEvents);

  void getAllChats() override;
  void getMessages(const QString &chatId) override;
  void sendMessage(const QString &chatId, const MessageData &message) override;

private:
  std::shared_ptr<ChatEvents> chatEvents;
};
} // namespace statusgo
