#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "robot_tf_publisher");
    ros::NodeHandle n;

    ros::Rate r(100);

    tf::TransformBroadcaster broadcaster;
    tf::Matrix3x3 obs_mat;
    obs_mat.setEulerYPR(0.0, 3.14, 0.0);

    tf::Quaternion q_tf;
    obs_mat.getRotation(q_tf);

    while (n.ok())
    {
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(q_tf.getX(), q_tf.getY(), q_tf.getZ(), q_tf.getW()), tf::Vector3(0.1, 0.0, 0.2)),
                ros::Time::now(), "base_link", "base_laser"));
        std::cout << q_tf.getX() << " " << q_tf.getY() << " " << q_tf.getZ() << " " << q_tf.getW() << std::endl;
        r.sleep();
    }
}
