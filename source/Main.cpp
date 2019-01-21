
#include <iostream>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "messaging/MessageBus.hpp"
#include "messaging/Messages.hpp"
#include "timing/PerfTiming.hpp"

using namespace cobalt::messaging;

void beginCombat1Handler (
	MessagePtr message
) {
	auto bcMsg = std::static_pointer_cast<BeginCombat>(message);
}

void beginCombat2Handler (
	MessagePtr message
) {
	auto bcMsg = std::static_pointer_cast<BeginCombat>(message);
}

int
main () {
	MessageBus mb;

	mb.addSubscriber(cobalt::messaging::MessageID::BEGIN_COMBAT, beginCombat1Handler);
	mb.addSubscriber(cobalt::messaging::MessageID::BEGIN_COMBAT, beginCombat2Handler);

	for (int j = 0; j < 1000; j++) {
		cobalt::timing::StartTimer();

		for (int i = 0; i < 1000000; i++) {
			mb.sendMessage(std::make_shared<BeginCombat>(i));	
		}
		
		mb.notify();

		std::cout << cobalt::timing::GetElapsedMilliseconds() << " milliseconds" << std::endl;
	}
}