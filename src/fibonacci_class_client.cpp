#include <actionlib/client/simple_action_client.h>
#include <ros/ros.h>
#include <ros_beginner_tutorials/FibonacciAction.h>

using namespace ros_beginner_tutorials;
typedef actionlib::SimpleActionClient<FibonacciAction> Client;

class MyNode
{
public:
    MyNode()
        : ac("fibonacci", true)
    {
        ROS_INFO("Waiting for action server to start.");
        ac.waitForServer();
        ROS_INFO("Action server started, sending goal.");
    }

    void doStuff(int order)
    {
        FibonacciGoal goal;
        goal.order = order;

        // Need boost::bind to pass in the 'this' pointer
        ac.sendGoal(goal,
                    boost::bind(&MyNode::doneCb, this, _1, _2),
                    boost::bind(&MyNode::activeCb, this),
                    boost::bind(&MyNode::feedbackCb, this, _1));
    }

    void doneCb(const actionlib::SimpleClientGoalState& state,
                const FibonacciResultConstPtr& result)
    {
        ROS_INFO("Finished in state [%s]", state.toString().c_str());
        ROS_INFO("Answer: %i", result->sequence.back());
        ros::shutdown();
    }

    // Called once when the goal becomes active
    void activeCb()
    {
        ROS_INFO("Goal just went active");
    }

    // Called every time feedback is received for the goal
    void feedbackCb(const FibonacciFeedbackConstPtr& feedback)
    {
        ROS_INFO("Got Feedback of length %lu", feedback->sequence.size());
    }

private:
    Client ac;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_fibonacci_class_client");
    MyNode my_node;
    my_node.doStuff(20);
    ros::spin();
    return 0;
}
