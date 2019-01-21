#pragma once

namespace cobalt {
	namespace messaging {
		enum class MessageID {
			BEGIN_COMBAT
		};

		struct Message {
			MessageID id;
		};

		struct BeginCombat : public Message {
			int combatID = 1;
			BeginCombat (int p_combatID) {
				this->id = MessageID::BEGIN_COMBAT;
				this->combatID = p_combatID;
			};
		};

	};
};