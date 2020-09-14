#include <iostream>
#include <queue>

class ICommand {
public:
	virtual ~ICommand() = default;

	virtual void execute() = 0;
};

class Switch {
private:
	std::queue<ICommand*> commands_;
public:
	void storeAndExecute(ICommand *command) {
		if (command) {
			commands_.push(command);
			command->execute();
			commands_.pop();
		}
	}
};

class Light {
public:
	void turnOn() {
		std::cout << "The light is on." << std::endl;
	}
	void turnOff() {
		std::cout << "The light is off." << std::endl;
	}
};

// The Command for turning on the light - ConcreteCommand #1
class SwitchOnCommand: public ICommand {
private:
	Light *light_;
public:
	SwitchOnCommand(Light *light) :
			light_(light) {
	}

	void execute() {
		light_->turnOn();
	}
};

// The Command for turning off the light - ConcreteCommand #2
class SwitchOffCommand: public ICommand {
private:
	Light *light_;
public:
	SwitchOffCommand(Light *light) :
			light_(light) {
	}

	void execute() {
		light_->turnOff();
	}
};

int main() {
	Light light = Light();
	SwitchOnCommand onCommand(&light);
	SwitchOffCommand offCommand(&light);

	ICommand *switchOn = &onCommand;
	ICommand *switchOff = &offCommand;

	Switch switcher = Switch();
	switcher.storeAndExecute(switchOn);
	switcher.storeAndExecute(switchOff);
}
