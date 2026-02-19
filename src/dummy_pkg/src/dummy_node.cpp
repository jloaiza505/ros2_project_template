#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class DummyNode : public rclcpp::Node
{
public:
  DummyNode()
  : Node("dummy_node")
  {
    timer_ = this->create_wall_timer(
      1s, [this]() {RCLCPP_DEBUG(this->get_logger(), "dummy node alive");});
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DummyNode>());
  rclcpp::shutdown();
  return 0;
}
