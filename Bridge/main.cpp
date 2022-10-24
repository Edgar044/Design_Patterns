#include <iostream>
#include "bridge.hpp"

int main() {
	Tv *tv = new Tv();
	Device *device = new Device();
	Remote *remote = new Remote(*device);

	remote->enable();

	
	remote->channelUp();
	remote->channelUp();
	remote->channelUp();
	remote->channelUp();
	remote->channelUp();
	remote->channelUp();
	remote->channelUp();
	std::cout << device->getChannel();
	
	std::cout << "\n";

	return 0;
}