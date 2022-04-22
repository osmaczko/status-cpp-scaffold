#include "ChatEmulator.h"

using namespace statusgo;

ChatEmulator::ChatEmulator(std::shared_ptr<ChatEvents> chatEvents)
    : chatEvents(chatEvents) {}

void ChatEmulator::getAllChats() {}
void ChatEmulator::getMessages(const QString &chatId) {}
void ChatEmulator::sendMessage(const QString &chatId,
                               const MessageData &message) {}
