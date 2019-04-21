#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;

void cloud_cb(const pcl::PCLPointCloud2ConstPtr& cloud) {
    pcl::PCLPointCloud2 cloud_filtered;

    // Perform the actual filtering
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    sor.setInputCloud(cloud);
    sor.setLeafSize(0.01, 0.01, 0.01);
    sor.filter(cloud_filtered);

    // Publish the data
    pub.publish(cloud_filtered);
}

int main(int argc, char** argv) {
    // Initialize ROS
    ros::init(argc, argv, "pcl_example");
    ros::NodeHandle nh;

    // Create a ROS subscriber for the input point cloud
    ros::Subscriber sub = nh.subscribe("/kinect2/qhd/points", 1, cloud_cb);

    // Create a ROS publisher for the output point cloud
    pub = nh.advertise<pcl::PCLPointCloud2>("/kinect2/qhd/downsampled_points", 1);

    // Spin
    ros::spin();
}