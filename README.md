# ros_socket_adaptor
This repo is about a universal trajectory display interface based on **RVIZ**. The client can send trajectory data to the server through the socket in the **specified format** for display.

## Data Format
The three-dimensional coordinates *xyz* and a *flag* are used to detect whether a loop occurs.

## Server
The server receives the data sent by the client through the socket, and converts it into *visualization_msgs::Marker* messages and publishes them.  
In this way, when rviz is opened, the corresponding topic can be selected for display. By the way, the server's IP address and port number are written in the **controller.cpp** file, remember to modify them.

## Client
The client needs to send the specified data format to the server. The specific implementation needs to be completed according to your SLAM framework and code structure.  
I provide two simple implementations of the test version here, namely **client*x*.cpp**, which reads data from the document **traj_example.txt**.
