#ifndef BRIGE_HPP
#define BRIDE_HPP

class Device {
private:
  bool power = 0;
  int volume = 0;
  int channel = 1;

public:
  bool isEnable() { return power; }

  void enable() { power = 1; }

  void disable() { power = 0; }

  int getVolume() { return volume; }

  void setVolume(int Volume) { volume = Volume; }

  int getChannel() { return channel; }

  void setChannel(int Channel) { channel = Channel; }
};

class AdvancedRemote : public Remote {
public:
  void brightnessUp() {}
  void brightnessDown() {}
};

class Remote : public Device {
  Device *device = new Device();
  Remote(Device d) : Device(d) {}

  void togglePower() {
    if (device->isEnable()) {
      device->disable();
    } else {
      device->enable();
    }
  }
  void volumeDown() {
    int vol = device->getVolume();
    --vol;
    device->setVolume(vol);
  }

  void volumeUp() {
    int vol = device->getVolume();
    ++vol;
    device->setVolume(vol);
  }

  void channelDown() {
    int ch = device->getVolume();
    --ch;
    device->setVolume(ch);
  }

  void channelUp() {
    int ch = device->getVolume();
    ++ch;
    device->setVolume(ch);
  }
};

class Tv : public Device {
  int brightness = 100;

public:
  void setBrightness(int value) { brightness = value; }
  int getBrightness() { return brightness; }
};

class Radio : public Device {
  std::string radioType = "FM";

public:
  void changheRadioType() {
    if (radioType == "FM") {
      radioType = "AM";
    } else {
      radioType = "FM";
    }
  }
};

#endif //! BRIGE_HPP
