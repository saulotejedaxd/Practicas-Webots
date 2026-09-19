#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

using namespace webots;

int main() {
  Robot robot;
  const int time_step = static_cast<int>(robot.getBasicTimeStep());

  Motor *propeller = robot.getMotor("motor_helice");
  if (propeller == nullptr)
    return 1;

  // Modo velocidad: posición infinita y velocidad angular constante.
  propeller->setPosition(INFINITY);
  propeller->setVelocity(3.0);

  while (robot.step(time_step) != -1) {
  }

  return 0;
}
