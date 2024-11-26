### 0.gitee令牌
仓库令牌：e66317743ba8c43c34921ceeb92d6eef

    git clone https://boreep:e66317743ba8c43c34921ceeb92d6eef@gitee.com/boreep/rm65_src.git -b unauthenticated

### 1.主要移动指令
移动指令分为`MOVEJ`、`MOVEJ_P`、`MOVEL`、`MOVEC`、`MOVES`五种运动类型。

- `MOVEJ`与`MOVEJ_P`指令：只保证最终路点位置，不对中间轨迹进行约束。其中`MOVEJ`与`MOVEJ_P`均为关节运动，但路点参数不同，`MOVEJ`的路点参数为各轴关节角度，`MOVEJ_P`为工具坐标点的位姿。
- `MOVEL`指令：在保证最终路点位置的同时，保证两点之间轨迹为直线运动。
- `MOVEC`指令：用来执行圆弧或圆形轨迹，只能添加两个路点（中间点和终点）。
- `MOVES`指令：可以实现更加复杂的曲线运动，不能有连续点位位置相同。


![运动图例](docs/image.png)

### 2.六维力传感器参数

|       | X | Y | Z | MX | MY | MZ |
| --- | --- | --- | --- | --- | --- | --- |
| 额定载荷| 200N | 200N | 200N | 7Nm | 7Nm | 7Nm |

*PS：六维力量程200N/7NM，如果末端受到600N以上的力或者21NM以上的力矩，会对传感器造成不可逆损坏。机械臂在运行过程中，避免传感器与外部设备发生硬碰撞，造成损伤。*

### 3.机械臂目前版本V1.6.5

![机械臂版本](docs/version.jpg)

### 4.Ros文件说明

#### 4.1 Demo演示文件

- `control_arm_move`：机械臂运动控制。
  
基于RM65、RM75机械臂和ROS功能包实现MoveJ、MoveJ_P、MoveL、MoveC规划运动功能，在程序执行时将依次执行关节运动MoveJ指令，位姿运动MoveJ_P指令、直线运动MoveL指令，圆弧运动MoveC指令，在运动开始和结束时终端都会收到相关提示，目的是使ROS开发者迅速掌握并灵活运用机械臂。
```
├── CMakeLists.txt                    <-CMake编译文件
├── launch                            <-启动文件夹
│   └── rm_65_move_demo.launch        <-启动文件(RM65)
    └── rm_75_move_demo.launch        <-启动文件(RM75)
├── LICENSE                           <-版本说明
├── package.xml                       <-依赖描述文件夹
├── README.md                         <-说明文档
└── src                               <-C++源码文件夹
    └── api_move_demo.cpp             <-源码文件
```

- `force_position_control`力位混合控制规划
  
基于RM65和RM75机械臂和ROS功能包实现力位混合控制规划运动功能（该功能适用于类似于MoveL的笛卡尔运动，不适用与MoveJ等关节运动），程序在执行时会依次执行开启力位混合控制，进行笛卡尔运动，关闭力位混合控制的操作，目的是使ROS开发者迅速掌握并灵活运用机械臂。


```
├── CMakeLists.txt                           <-CMake编译文件
├── launch                                   <-启动文件夹
│   └── force_position_control_demo.launch   <-启动文件
├── LICENSE                                  <-版本说明
├── package.xml                              <-依赖描述文件夹
├── README.md                                <-说明文档
└── src                                      <-C++源码文件夹
    └── api_force_position_control_demo.cpp  <-源码文件
```

-`control_arm_move`

基于机械臂机械臂本体和ROS功能包实现获取机械臂当前控制器版本、关节状态、位姿状态、六维力信息功能，程序将依次执行获取控制器版本信息，获取机械臂状态，获取六维力数据信息的指令，程序执行时，对应的数据信息会打印在终端中，该示例目的是使ROS开发者迅速掌握并灵活运用机械臂。

```
├── CMakeLists.txt                    <-CMake编译文件
├── launch                            <-启动文件夹
│   └── get_arm_state_demo.launch     <-启动文件
├── LICENSE                           <-版本说明
├── package.xml                       <-依赖描述文件夹
├── README.md                         <-说明文档
└── src                               <-C++源码文件夹
    └── api_Get_Arm_State_demo.cpp    <-源码文件
```

#### 4.2 ROS示例文件（具体查看rm_doc）


![ROS使用说明](docs/ROS使用说明.jpeg)
![ROS功能包关系](docs/流程图.png)

- 模型描述`rm_description`
该功能包为机械臂模型描述功能包，其作用为提供机械臂模型文件和模型加载节点，并为其他功能包提供机械臂关节间的坐标变换关系。
---

- ROS消息接口`rm_msgs`
该功能包为机械臂的消息文件功能包，其作用为提供机械臂适配ROS的所有控制消息和状态消息。
---

- 硬件驱动`rm_driver`
该功能包为机械臂的ROS底层驱动功能包，其作用为订阅和发布机械臂底层相关话题信息。
---

- 启动`rm_bringup`
该功能包为机械臂的节点启动功能包，其作用为快速启动多节点复合的机械臂功能。
---

- moveit配置`rm_moveit_config`
该功能包为机械臂的moveit适配功能包，其作用为适配和实现各系列机械臂的moveit规划控制功能，主要包括虚拟机械臂控制和真实机械臂控制两部分控制功能。
---

- `rm_control`功能包为实现moveit控制真实机械臂时所必须的一个功能包，该功能包的主要作用为将moveit规划好的路径点进行进一步的细分，将细分后的路径点以透传的方式给到`rm_driver`，实现机械臂的规划运行。
---

- `rm_moveit_config`文件夹为实现moveit控制真实机械臂的功能包，该功能包的主要作用为调用官方的moveit框架，结合我们机械臂本身的URDF生成适配于我们机械臂的moveit的配置和启动文件，通过该功能包我们可以实现moveit控制虚拟机械臂和控制真实机械臂。
---

- Gazebo仿真机械臂控制`rm_gazebo`
该功能包为gazebo仿真机械臂功能包，主要功能为在gazebo仿真环境中显示机械臂模型，可通过moveit对仿真的机械臂进行规划控制。
---
- 使用案例`rm_demo`
该功能包为机械臂的一些使用案例，主要功能为实现机械臂的一些基本的控制功能和运动功能的使用案例。
---

- 技术文档`rm_doc`
该功能包为介绍文档的功能包，其主要包括为对整体的功能包内容和使用方式进行总体介绍的文档和对每个功能包中的内容和使用方式进行详细介绍的文档。




