
#include "messaging/MessageBus.hpp"

using namespace cobalt::messaging;

MessageBus::MessageBus () {}

/*
	Registers a subscriber to a specific message
*/
void
MessageBus::addSubscriber (
	MessageID p_msgID,
	Subscriber p_subscriber
) {
	m_subscribers[p_msgID].push_back(p_subscriber);
}

/*
	Sends a message to all subscribers of this message
	Note: sending the message is delayed.
*/
void
MessageBus::sendMessage (
	MessagePtr p_msg
) {
	m_unsentMessages[p_msg->id].push(p_msg);
}

/*
	Processes the unsent message queue
*/
void
MessageBus::notify () {
	// loop over all unsent messages by type
	// unsentMsg.first is the message id
	// unsentMsg.second is the queue of messages

	for (auto const& unsentMsg : m_unsentMessages) {
		auto messageId = unsentMsg.first;
		auto messageQueue = unsentMsg.second;

		while (!messageQueue.empty()) {
			for (auto subscriber = m_subscribers[messageId].begin(); subscriber != m_subscribers[messageId].end(); subscriber++) {
				(*subscriber)(messageQueue.front());
			}

			messageQueue.pop();
		}
	}
}