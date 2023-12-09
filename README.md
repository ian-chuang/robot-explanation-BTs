# Robot Explanation Generation Using Behavior Trees (BTs)

This repository is a fork of the original project available at [uml-robotics/robot-explanation-BTs](https://github.com/uml-robotics/robot-explanation-BTs) and is associated with the paper, "What Will You Do Next? Extending Explanation Generation Using Behavior Trees to Include Projection-Level XAI."

## Project Overview

In the context of this paper, we have introduced an extension to [an existing codebase](https://anonymous.4open.science/r/BehaviorTreeCPPD20A/README.md) for generating explanations using behavior trees (BTs). Our contributions to this project include:

1. **Next Action Explanations**: We've created algorithms that allow users to ask about what an agent's next action will be in case of success or failure in their current action.

2. **Pre/Post-Condition Explanations**: The extended codebase allows users to pose questions regarding the preconditions and postconditions of the current action being executed.

3. **Code Refactoring**: We've refactored the original explanation generation code to enhance its modularity, making it easier for future researchers to add new explanations.

4. **Dependency Library Upgrade**: The project includes an updated version of the dependency library BehaviorTree.CPP, which is tailored to support our enhancements.

5. **Graphical User Interface (GUI)**: To facilitate the exploration of explanation interface designs for future Human-Robot Interaction (HRI) studies, we've integrated a GUI. This GUI provides a simple means to iterate on the presentation of explanations.

## System Requirements

To use this codebase, please ensure that your system meets the following requirements:

- **ROS Noetic**
- **Ubuntu 20.04**

Our code has been tested on WSL2 Ubuntu 20.04 with ROS Noetic.

## Installation

To install the necessary dependencies and set up your environment, follow these steps:

1. Verify that you are running Ubuntu 20.04 and have ROS Noetic installed. You can find installation instructions for ROS Noetic [here](https://wiki.ros.org/noetic/Installation/Ubuntu).

2. Install catkin the ROS build system:

   ```bash
   sudo apt install ros-noetic-catkin python3-catkin-tools
   ```

3. Create a ROS workspace. In your terminal, execute the following commands:

   ```bash
   mkdir -p ~/catkin_ws/src
   cd ~/catkin_ws/src
   ```

4. Clone the required repositories:

   ```bash
   git clone -b v4.3 https://anonymous.4open.science/r/BehaviorTreeCPPD20A.git
   git clone https://github.com/ian-chuang/robot-explanation-BTs.git
   ```

5. Install ROS dependencies for the cloned packages:

   ```bash
   cd ~/catkin_ws/src
   rosdep install -y --from-paths . --ignore-src --rosdistro noetic
   ```

6. Build the project using Catkin:

   ```bash
   cd ~/catkin_ws
   catkin build
   ```

7. Source the setup script to configure your environment:

   ```bash
   source ~/catkin_ws/devel/setup.bash
   ```

## Running the Project

To run the example behavior tree, use the following command:

```bash
roslaunch explain_bt example_bt.launch
```

Once executed, the GUI will be displayed. Click the "Start" button at the top left of the GUI to begin the behavior tree execution. The GUI will provide real-time generated explanations while the behavior tree is running. If needed, you can restart the behavior tree by clicking "Reset" and "Start."

Feel free to explore and experiment with the behavior tree located at `explain_bt/bt_xml/example_bt.xml`.

## Algorithms

<p align="center">
  <img src="images/algorithm1.png" width="300"  alt="Algorithm 1">
  <img src="images/algorithm2.png" width="300"  alt="Algorithm 4">
</p>

<p align="center">
  <img src="images/algorithm3.png" width="300"  alt="Algorithm 2">
  <img src="images/algorithm4.png" width="300"  alt="Algorithm 5">
</p>

<p align="center">
  <img src="images/algorithm5.png" width="300"  alt="Algorithm 3">
  <img src="images/algorithm6.png" width="300"  alt="Algorithm 6">
</p>