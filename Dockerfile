FROM ros:melodic

RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-melodic-interactive-markers \
    ros-melodic-pcl-conversions \
    ros-melodic-pcl-ros \
    ros-melodic-turtlesim \
    ros-melodic-urdf \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /root/catkin_ws/src

COPY . ros_beginner_tutorials

RUN /bin/bash -c '. /opt/ros/melodic/setup.bash && catkin_make -C /root/catkin_ws -DCMAKE_BUILD_TYPE=Release'

RUN rm -rf ros_beginner_tutorials
