#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/Robot.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace webots;

int main() {
  Robot robot;
  const int time_step = static_cast<int>(robot.getBasicTimeStep());
  const double dt = static_cast<double>(time_step) / 1000.0;

  Motor *motor = robot.getMotor("motor_pendulo");
  PositionSensor *encoder = robot.getPositionSensor("encoder_pendulo");
  if (motor == nullptr || encoder == nullptr)
    return 1;

  encoder->enable(time_step);

  // Control PID manual sobre el ángulo del péndulo.
  // Los valores se dejan explícitos para que la sintonía sea visible en la práctica.
  constexpr double kp = 2.0;
  constexpr double ki = 0.10;
  constexpr double kd = 0.08;
  constexpr double reference = 0.0;  // rad
  constexpr double integral_limit = 2.0;

  motor->setPosition(INFINITY);

  double integral = 0.0;
  double previous_error = 0.0;
  bool first_sample = true;

  while (robot.step(time_step) != -1) {
    const double angle = encoder->getValue();
    const double error = reference - angle;

    integral += error * dt;
    integral = std::clamp(integral, -integral_limit, integral_limit);

    double derivative = 0.0;
    if (!first_sample)
      derivative = (error - previous_error) / dt;
    first_sample = false;

    const double raw_command = kp * error + ki * integral + kd * derivative;
    const double max_speed = motor->getMaxVelocity();
    const double command = std::clamp(raw_command, -max_speed, max_speed);

    motor->setVelocity(command);
    previous_error = error;

    std::cout << "angulo=" << angle
              << " error=" << error
              << " salida_pid=" << command << std::endl;
  }

  return 0;
}
