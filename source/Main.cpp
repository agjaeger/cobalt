
#include <iostream>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "messaging/MessageBus.hpp"
#include "messaging/Messages.hpp"

using namespace cobalt::messaging;

void beginCombat1Handler (
	MessagePtr message
) {
	auto bcMsg = std::static_pointer_cast<BeginCombat>(message);
	std::cout << "Begin Combat 1 Found Message " << bcMsg->combatID << std::endl;
}

void beginCombat2Handler (
	MessagePtr message
) {
	std::cout << "Begin Combat 2 Found Message" << std::endl;
}

int
main () {
	MessageBus mb;

	mb.addSubscriber(cobalt::messaging::MessageID::BEGIN_COMBAT, beginCombat1Handler);
	mb.addSubscriber(cobalt::messaging::MessageID::BEGIN_COMBAT, beginCombat2Handler);

	mb.sendMessage(std::make_shared<BeginCombat>(2));
	mb.sendMessage(std::make_shared<BeginCombat>(4));

	mb.notify();
}