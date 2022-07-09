#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include "ros/ros.h"
#include <behaviortree_cpp_v3/bt_factory.h>
#include "explain_bt/Explain.h"
#include "ExplainableBT.h"
#include "ur5e_nodes.h"

using namespace BT;
using boost::filesystem::current_path;

int main (int argc, char **argv)
{
   BehaviorTreeFactory factory;

   using namespace UR5eNodes;
   factory.registerNodeType<GoHome>("GoHome");
   factory.registerNodeType<GoVertical>("GoVertical");
   factory.registerNodeType<MoveToPose>("MoveToPose");
   factory.registerNodeType<TranslateToPose>("TranslateToPose");
   factory.registerNodeType<BadMove>("BadMove");


   GripperInterface gripper;
   factory.registerSimpleAction("OpenGripper", 
                                 std::bind(&GripperInterface::open, &gripper));
   factory.registerSimpleAction("CloseGripper", 
                                 std::bind(&GripperInterface::close, &gripper));
   factory.registerSimpleAction("GripGripper", 
                                 std::bind(&GripperInterface::grip, &gripper));

   std::string cwd = get_current_dir_name();
   auto tree = factory.createTreeFromFile(cwd + "/src/explain_bt/src/test_tree_fallback.xml");
   ROS_INFO("BT created from file.");

   ExplainableBT explainable_tree(tree);

   ros::init(argc, argv, "explainable_bt_server");
   ros::NodeHandle n;
   ros::ServiceServer service = n.advertiseService("explainable_bt", &ExplainableBT::explain_callback, &explainable_tree);
   ros::AsyncSpinner spinner(1); // Use 1 thread
   spinner.start();
   
   ROS_INFO("Explainable BT node started.");

   // This executeTick method runs the BT without explainability
   // tree.root_node->executeTick();
   
   // This option runs the BT with explainability
   explainable_tree.execute();

   ros::waitForShutdown();

   return 0;
}