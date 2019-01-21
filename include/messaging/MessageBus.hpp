#pragma once

#include <functional>
#include <map>
#include <queue>
#include <vector>
#include <memory>

#include "messaging/Messages.hpp"

namespace cobalt {
	namespace messaging {
		typedef std::shared_ptr<Message> MessagePtr;
		typedef std::function<void(MessagePtr)> Subscriber;

		class MessageBus {
		public:
			MessageBus();

			void addSubscriber(MessageID msgID, Subscriber subscriber);
			void sendMessage(MessagePtr msg);
			void notify();

		private:
			std::map<MessageID, std::vector<Subscriber>> m_subscribers;
			std::map<MessageID, std::queue<MessagePtr>> m_unsentMessages;
		};
	};
};